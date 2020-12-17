
$regfile = "m16def.dat"
$crystal = 8000000
$hwstack = 40
$swstack = 16
$framesize = 32
$baud = 19200

Config Spi = Hard , Interrupt = Off , Data Order = Lsb , Master = Yes , Polarity = Low , Phase = 1 , Clockrate = 128 , Noss = 0 , Spiin = Value
Config Portb.3 = Output

Spiinit


Declare Sub Configure : Declare Sub Switch_lock : Declare Sub Poll

'command
   Dim 1_byte_cmd As Byte : Dim 2_byte_cmd As Byte : Dim 3_byte_cmd As Byte : Dim 4_byte_cmd As Byte : Dim 5_byte_cmd As Byte
'data
   Dim 1_byte_data As Byte : Dim 2_byte_data As Byte : Dim 3_byte_data As Byte : Dim 4_byte_data As Byte : Dim 5_byte_data As Byte : Dim R_x As Byte : Dim R_y As Byte : Dim L_y As Byte

'***********************************************************************alais*******************************************
     Key_select Alias 4_byte_data.0 : Key_l3 Alias 4_byte_data.1 : Key_r3 Alias 4_byte_data.2 : Key_start Alias 4_byte_data.3 : Key_up Alias 4_byte_data.4 : Key_right Alias 4_byte_data.5 : Key_down Alias 4_byte_data.6 : Key_left Alias 4_byte_data.7
     Key_l2 Alias 5_byte_data.0 : Key_r2 Alias 5_byte_data.1 : Key_l1 Alias 5_byte_data.2 : Key_r1 Alias 5_byte_data.3 : Key_triangle Alias 5_byte_data.4 : Key_circle Alias 5_byte_data.5 : Key_x Alias 5_byte_data.6 : Key_square Alias 5_byte_data.7
     Ss Alias Portb.3
'**********************************************************************************************************************************

'**************************************************************************main******************************************************************
Do

  Spiout 1_byte_cmd , 1 : Spiout 2_byte_cmd , 1 : Spiout 3_byte_cmd , 1 : Spiout 4_byte_cmd , 1 : Spiout 5_byte_cmd , 1
  Spiin 4_byte_data , 1 : Spiin 5_byte_data , 1 : Spiin R_x , 1 : Spiin R_y , 1 : Spiin L_x , 1 : Spiin L_y , 1



Loop
End

'-************************************************************************************************************************************************
      Sub Configure

               1_byte_cmd = &H01 : 2_byte_cmd = &H43 : 3_byte_cmd = &H00 : 4_byte_cmd = &H01 : 5_byte_cmd = &H00
               1_byte_data = &HFF : 2_byte_data = &H41 : 3_byte_data = &H5A : 4_byte_data = &HFF : 5_byte_data = &HFF

      End Sub

      Sub Switch_lock

               1_byte_cmd = &H01 : 2_byte_cmd = &H44 : 3_byte_cmd = &H00 : 4_byte_cmd = &H01 : 5_byte_cmd = &H03
               1_byte_data = &HFF : 2_byte_data = &HF3 : 3_byte_data = &H5A : 4_byte_data = &H00 : 5_byte_data = &H00

      End Sub

      Sub Poll

               1_byte_cmd = &H01 : 2_byte_cmd = &H42 : 3_byte_cmd = &H00

      End Sub