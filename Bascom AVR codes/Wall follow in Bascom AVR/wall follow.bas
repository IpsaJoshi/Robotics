
$regfile = "m16def.dat"
$crystal = 8000000
$hwstack = 40
$swstack = 16
$baud = 19200


Config Portc.0 = Output
Config Portc.1 = Output
Config Portc.4 = Output
Config Portc.6 = Output
Config Portc.2 = Output
Config Pinc.3 = Input
Config Porta = Input
Config Portd = Output


Config Timer1 = Pwm , Pwm = 8 , Compare A Pwm = Clear Up , Compare B Pwm = Clear Up , Prescale = 8

Trig Alias Portc.2
Echopin Alias Pinc.3
Mot1spd Alias Compare1b
Mot2spd Alias Compare1a
M1a Alias Portc.0
M1b Alias Portc.4
M2a Alias Portc.1
M2b Alias Portc.6
Btn Alias Pina.6

Dim Spd1 As Integer : Dim Spd2 As Integer :
Dim T As Word : Dim A As Integer : Dim Distance As Single : Dim Distance1 As Integer : A = 0
'Dim P As Single : P = 0
'Dim Cspd As Integer : Cspd = 255
'Dim Error As Integer : Error = 0
'Dim Kp As Single : Kp = 10

Declare Sub Applyspd




Do

Reset Trig
Waitus 2
Set Trig
Waitus 10
Reset Trig
Pulsein T , Pinc , 3 , 1
Distance = T * 0.17
Distance1 = Round(distance)
Print Distance1



If Btn = 1 Then
  A = 0
Elseif Btn = 0 Then
  A = 1
End If

If A = 1 Then

     Set M1a : Reset M1b
     Set M2a : Reset M2b

     Spd1 = 120 : Spd2 = 110

    If Distance1 > 30 Then
    Mot1spd = Spd1 + 40
    Mot2spd = Spd2

    Elseif Distance1 < 30 Then
    Mot1spd = Spd1
    Mot2spd = Spd2 + 40

    Elseif Distance1 = 30 Then
    Mot1spd = 150
    Mot2spd = 150

    End If
End If

Call Applyspd
Loop


End

Sub Applyspd


      If Spd1 > 0 Then
         Set M1a
         Reset M1b
         Mot1spd = Spd1
      Elseif Spd1 < 0 Then
         Reset M1a
         Set M1b
         Mot1spd = -spd1
      Else
         Reset M1a : Reset M1a
         Mot1spd = 0
      End If

      If Spd2 > 0 Then
         Set M2a
         Reset M2b
         Mot2spd = Spd2
      Elseif Spd2 < 0 Then
         Reset M2a
         Set M2b
         Mot2spd = -spd2
      Else
         Reset M2a : Reset M2b
         Mot2spd = 0
      End If


End Sub