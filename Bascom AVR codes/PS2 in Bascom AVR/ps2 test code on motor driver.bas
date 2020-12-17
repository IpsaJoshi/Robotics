

$regfile = "m16def.dat"
$crystal = 8000000
$hwstack = 40
$swstack = 16
$framesize = 32
$baud = 19200

Config Spi = Hard , Interrupt = Off , Data Order = Lsb , Master = Yes , Polarity = Low , Phase = 1 , Clockrate = 128 , Noss = 0 , Spiin = Value
Config Timer1 = Pwm , Pwm = 8 , Compare A Pwm = Clear Up , Compare B Pwm = Clear Up , Prescale = 8

Spiinit

         Dim L_spd As Integer : L_spd = 0 : Dim R_spd As Integer : R_spd = 0

Config Portc = Output : Config Porta = Output : Config Portd.6 = Input : Config Portb.3 = Output
'----------------------------------------------------DECLARATION--------------------------------------------------------
         Dim 1_byte_cmd As Byte : 1_byte_cmd = &H01 : Dim 2_byte_cmd As Byte : 2_byte_cmd = &H42 : Dim 3_byte_cmd As Byte : 3_byte_cmd = &H00
         Dim 4_byte_data As Byte : Dim 5_byte_data As Byte
         Dim R_x As Byte : Dim R_y As Byte : Dim L_x As Byte : Dim L_y As Byte
         Dim A As String * 10 : Dim X As String * 10 : Dim N As Integer : N = 0 : Dim M As Integer

         Key_select Alias 4_byte_data.0 : Key_l3 Alias 4_byte_data.1 : Key_r3 Alias 4_byte_data.2 : Key_start Alias 4_byte_data.3 : Key_up Alias 4_byte_data.4 : Key_right Alias 4_byte_data.5 : Key_down Alias 4_byte_data.6 : Key_left Alias 4_byte_data.7
         Key_l2 Alias 5_byte_data.0 : Key_r2 Alias 5_byte_data : Key_l1 Alias 5_byte_data.2 : Key_r1 Alias 5_byte_data.3 : Key_triangle Alias 5_byte_data.4 : Key_circle Alias 5_byte_data.5 : Key_x Alias 5_byte_data.6 : Key_square Alias 5_byte_data.7


         rms Alias Compare1a : lms Alias Compare1b
         Lm Alias Porta.1 : Rm Alias Porta.2
         L_r Alias Portc.4 : L_f Alias Portc.5 : R_f Alias Portc.6 : R_r Alias Portc.7

         Btn Alias Pind.6 : Ss Alias Portb.3

         Declare Sub Analog : Declare Sub Direction : Declare Sub Applyspd

       Reset L_f : Reset R_f : Reset L_r : Reset R_r

        M = 50
'-------------------------------------------------------MAIN-------------------------------------------
Do

      Print " l_x=" + L_x + " l_y=" + L_y + " r_x=" + R_x + " r_y=" + R_y
     ' Print "X=" + X + " A=" + A
         Reset Ss
           Spiout 1_byte_cmd , 1 : Spiout 2_byte_cmd , 1 : Spiout 3_byte_cmd , 1
           Spiin 4_byte_data , 1 : Spiin 5_byte_data , 1 : Spiin R_x , 1 : Spiin R_y , 1 : Spiin L_x , 1 : Spiin L_y , 1
         Set Ss

      If Key_l3 = 0 Then : N = 1 : End If
      If Key_start = 0 Then : N = 0 : End If

      If N = 0 Then : Call Analog
      Elseif N = 1 Then : Lms = 0 : Rms = 0 : End If

Loop
End
'-------------------------------------------------------------------------------------------------------------------------


Sub Analog


   Select Case L_x

     Case 1 To 122 : R_spd = M
                      L_spd = 0


     Case 124 To 254 : L_spd = M
                        R_spd = 0

     Case 255 : Select Case L_y
                          Case 0 To 123 : L_spd = M
                                           R_spd = 0
                          Case 124 To 254 : L_spd = -m
                                             R_spd = 0

                       End Select

     Case 0 : Select Case L_y
                          Case 0 To 123 : R_spd = M
                                           L_spd = 0
                          Case 124 To 254 : R_spd = -m
                                             L_spd = 0
                       End Select

     Case 123 : Select Case L_y
                          Case 0 To 122 : L_spd = M
                                           R_spd = M

                          Case 124 To 255 : L_spd = -m
                                             R_spd = -m
                          Case Else : L_spd = 0
                                       R_spd = 0
                         End Select
     Case Else : L_spd = 0
                  R_spd = 0
   End Select
   Call Applyspd

End Sub

Sub Applyspd

If L_spd > 0 Then : Reset Lm : Lms = L_spd
Elseif L_spd < 0 Then : Set Lm : Lms = -l_spd
Else : Lms = 0 : End If

If R_spd > 0 Then : Reset Rm : Rms = R_spd
Elseif R_spd < 0 Then : Set Rm : Rms = -r_spd
Else : Rms = 0 : End If

End Sub