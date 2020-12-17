

$regfile = "m16def.dat"
$crystal = 8000000
$hwstack = 40
$swstack = 16
$framesize = 32
$baud = 19200

Config Spi = Hard , Interrupt = Off , Data Order = Lsb , Master = Yes , Polarity = Low , Phase = 1 , Clockrate = 128 , Noss = 0 , Spiin = Value

Spiinit


Config Portc = Output : Config Portd.6 = Input : Config Portb.3 = Output:
'----------------------------------------------------DECLARATION--------------------------------------------------------
         Dim 1_byte_cmd As Byte : 1_byte_cmd = &H01 : Dim 2_byte_cmd As Byte : 2_byte_cmd = &H42 : Dim 3_byte_cmd As Byte : 3_byte_cmd = &H00
         Dim 4_byte_data As Byte : Dim 5_byte_data As Byte
         Dim R_x As Byte : Dim R_y As Byte : Dim L_x As Byte : Dim L_y As Byte
         Dim A As String * 10 : Dim X As String * 10 : Dim N As Integer : N = 0

         Key_select Alias 4_byte_data.0 : Key_l3 Alias 4_byte_data.1 : Key_r3 Alias 4_byte_data.2 : Key_start Alias 4_byte_data.3 : Key_up Alias 4_byte_data.4 : Key_right Alias 4_byte_data.5 : Key_down Alias 4_byte_data.6 : Key_left Alias 4_byte_data.7
         Key_l2 Alias 5_byte_data.0 : Key_r2 Alias 5_byte_data : Key_l1 Alias 5_byte_data.2 : Key_r1 Alias 5_byte_data.3 : Key_triangle Alias 5_byte_data.4 : Key_circle Alias 5_byte_data.5 : Key_x Alias 5_byte_data.6 : Key_square Alias 5_byte_data.7
         Btn Alias Pind.6 : Ss Alias Portb.3

         L_r Alias Portc.4 : L_f Alias Portc.5 : R_f Alias Portc.6 : R_r Alias Portc.7
         Declare Sub Analog : Declare Sub Direction

       Reset L_f : Reset R_f : Reset L_r : Reset R_r

'-------------------------------------------------------MAIN-------------------------------------------
Do

      'Print " l_x=" + L_x + " l_y=" + L_y + " r_x=" + R_x + " r_y=" + R_y
      Print "X=" + X + " A=" + A
         Reset Ss
           Spiout 1_byte_cmd , 1 : Spiout 2_byte_cmd , 1 : Spiout 3_byte_cmd , 1
           Spiin 4_byte_data , 1 : Spiin 5_byte_data , 1 : Spiin R_x , 1 : Spiin R_y , 1 : Spiin L_x , 1 : Spiin L_y , 1
         Set Ss

     If Key_l3 = 0 Then : N = 1 : End If
     If N = 1 Then : Reset L_f : Reset R_f : Reset L_r : Reset R_r : End If

      Call Analog

Loop
End
'-------------------------------------------------------------------------------------------------------------------------


Sub Analog

   Select Case L_x

     Case 1 To 122 : Set R_f
                     Reset L_f
                     Reset L_r
                     Reset R_r

     Case 124 To 254 : Set L_f
                        Reset R_f
                        Reset L_r
                        Reset R_r

     Case 255 :       Select Case L_y
                          Case 0 To 123 : Set L_f
                                           Reset R_f
                                           Reset L_r
                                           Reset R_r
                          Case 124 To 254 : Set L_r
                                             Reset L_f
                                             Reset R_f
                                             Reset R_r

                       End Select

     Case 0 : Select Case L_y
                          Case 0 To 123 : Set R_f
                                           Reset L_f
                                           Reset L_r
                                           Reset R_r
                          Case 124 To 254 : Set R_r
                                             Reset L_f
                                             Reset R_f
                                             Reset L_r

                       End Select

     Case 123 : Select Case L_y
                          Case 0 To 122 : Set L_f
                                           Set R_f
                                           Reset L_r
                                           Reset R_r
                          Case 124 To 255 : Set L_r
                                            Set R_r
                                            Reset L_f
                                            Reset R_f

                         End Select
     Case Else : Reset L_f
                  Reset R_f
                  Reset L_r
                  Reset R_r
   End Select


End Sub
