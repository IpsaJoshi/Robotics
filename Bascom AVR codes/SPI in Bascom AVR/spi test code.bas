 $regfile = "m16def.dat"
$crystal = 8000000
$hwstack = 40
$swstack = 16
$framesize = 32
$baud = 19200

Config Spi = Hard , Interrupt = Off , Data Order = Lsb , Master = Yes , Polarity = Low , Phase = 1 , Clockrate = 128 , Noss = 0 , Spiin = Value

Spiinit

Config Portc.7 = Output
Ss Alias Portc.7

Dim 1_byte_cmd As Byte : 1_byte_cmd = &H01
Dim 2_byte_cmd As Byte : 2_byte_cmd = &H42
Dim 3_byte_cmd As Byte : 3_byte_cmd = &H00
Dim 4_byte_data As Byte                                     '4th byte data  (miso)
Dim 5_byte_data As Byte                                     '5th byte data (miso)
Dim R_x As Byte                                             '6th byte
Dim R_y As Byte                                             '7th byte
Dim L_x As Byte                                             '8th byte
Dim L_y As Byte                                             '9th byte


Key_select Alias 4_byte_data.0
Key_l3 Alias 4_byte_data.1
Key_r3 Alias 4_byte_data.2
Key_start Alias 4_byte_data.3
Key_up Alias 4_byte_data.4
Key_right Alias 4_byte_data.5
Key_down Alias 4_byte_data.6
Key_left Alias 4_byte_data.7

Key_l2 Alias 5_byte_data.0
Key_r2 Alias 5_byte_data.1
Key_l1 Alias 5_byte_data.2
Key_r1 Alias 5_byte_data.3
Key_triangle Alias 5_byte_data.4
Key_circle Alias 5_byte_data.5
Key_x Alias 5_byte_data.6
Key_square Alias 5_byte_data.7



Do


'Print "hello"
'Print Key_select + " " + Key_start + " " + Key_l3 + " " + Key_r3 + " " + Key_up + " " + Key_right + " " + Key_down + " " + Key_left + " " + Key_l2 + " " + Key_l1 + " " + Key_r2 + " " + Key_r1 + " " + Key_triangle + " " + Key_circle + " " + Key_x + " " + Key_square
'Print hex(status_ )
Print " l_x=" + L_x + " l_y=" + L_y + " r_x=" + R_x + " r_y=" + R_y


Reset Ss

  Spiout 1_byte_cmd , 1
  Spiout 2_byte_cmd , 1
  Spiout 3_byte_cmd , 1


  Spiin 4_byte_data , 1
  Spiin 5_byte_data , 1
  Spiin R_x , 1
  Spiin R_y , 1
  Spiin L_x , 1
  Spiin L_y , 1

Set Ss



Loop
End                                                         'end program