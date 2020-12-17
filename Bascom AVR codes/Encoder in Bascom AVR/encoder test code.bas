$regfile = "m16def.dat"
$crystal = 8000000
$hwstack = 40
$swstack = 16
$framesize = 32
$baud = 19200

Config Portb = Input
Config Int0 = Rising


On Int0 A_phase
Enable Int0

Enable Interrupts

Dim Count As Integer

A Alias Pind.2
B Alias Pinb.1


Do

    'Print "A=" + A + "b=" + B                               '+ "z=" + Z



Loop
End

A_phase:

   If B = 0 Then
      Print "ccw"
   Else
      Print "cw"
   End If

Return
