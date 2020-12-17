
'''''''''''''HEADER FILE''''''''''''''''
$regfile = "m16def.dat"
$crystal = 8000000
$hwstack = 40
$swstack = 16
$framesize = 32
$baud = 19200
'''''''''''''''''''''''''''''''''''''''''''''
Enable Interrupts


Config Porta.0 = Output
Config Pinb.1 = Input

Trig Alias Porta.0
Echopin Alias Portb.1


Dim A As Word
Dim Distance As Single
Dim Count As Integer
Dim Distance1 As Integer
Count = 0



Do

Reset Trig
Waitus 2

Set Trig
Waitus 10



Reset Trig
Pulsein A , Pinb , 1 , 1

Distance = A * 0.17

Distance1 = Round(distance)

Print Distance1 + "cm"

Loop
End