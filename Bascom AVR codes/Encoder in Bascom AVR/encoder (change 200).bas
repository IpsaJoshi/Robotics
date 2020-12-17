$regfile = "m16def.dat"
$crystal = 8000000
$hwstack = 40
$swstack = 16
$framesize = 32
$baud = 19200

Config Portb = Input
Config Portd = Input
Config Int0 = Change


On Int0 A_phase
Enable Int0

Enable Interrupts

Dim Count As Integer : Dim X As Integer : Dim F As Integer : F = 0 : Dim G As Integer : G = 0

A Alias Pind.2
B Alias Pinb.1

Set Portd.2

Do

   Print Count
   ' Print G



Loop
End

A_phase:


      If F = 0 And A = 0 Then
         F = 1
         X = 0
      Elseif F = 1 And A = 1 Then
         X = 1
         F = 0
      End If


      If X = 1 Then

        If B = 0 Then : G = 1
        Elseif B = 1 Then : G = -1 : End If

      End If

      If G = 1 Then : Incr Count
      Elseif G = -1 Then : Decr Count : End If

Return

