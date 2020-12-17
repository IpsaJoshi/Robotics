$regfile = "m16def.dat"
$crystal = 4000000
$hwstack=40
$swstack=16
$framesize=32

Config Servos = 1 , Servo1 = Portb.0 , Reload = 10

Config Portb = Output
Config Pind.6 = Input


Enable Interrupts

Servo(1) = 100                                              '10 times 10 = 100 uS on

Dim I As Integer

Do

If Pind.6 = 0 Then

For I = 0 To 1 Step 1

  Servo(1) = I

  Waitms 5

Next

Print I

'For I = 180 To 0 Step -1

'  Servo(1) = I

'  Waitms 5

'Next
End If
Loop


End
