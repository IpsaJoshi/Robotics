$regfile = "m16def.dat"
$crystal = 8000000
$hwstack = 40
$swstack = 16
$framesize = 32
$baud = 19200


Config Porta = Input
Config Portb = Input
Config Portd.2 = Input

Config Int0 = Rising
On Int0 J_pulse
Enable Int0
Enable Interrupts


Config Adc = Single , Prescaler = Auto , Reference = Avcc

Dim W As Word : Dim Count As Integer

Start Adc



Do

  Print Pinb.0                                              'Print Count                                               ' Print Pind.2

  W = Getadc(7)                                             'lsa analog



Loop
End



J_pulse:

      Incr Count

Return