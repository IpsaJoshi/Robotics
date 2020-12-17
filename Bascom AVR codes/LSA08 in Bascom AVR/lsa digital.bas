$regfile = "m16def.dat"
$crystal = 8000000
$hwstack = 40
$swstack = 16
$framesize = 32
$baud = 19200

Config Portc = Input

A Alias Pinc.3 : B Alias Pinc.4 : C Alias Pinc.2 : D Alias Pinc.5 : E Alias Pinc.1 : F Alias Pinc.6 : G Alias Pinc.0 : H Alias Pinc.7

Do

   Print A + B + C + D + E + F + G + H

Loop
End