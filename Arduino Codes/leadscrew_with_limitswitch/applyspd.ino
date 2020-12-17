void LSapplyspd()
{
  switch(LSspd)
  {
    case 1 ... 150:   digitalWrite(LSmot1,LOW);digitalWrite(LSmot2,HIGH); analogWrite(LSmot5,LSspd);  break;
    case -150 ... -1: digitalWrite(LSmot1,HIGH);digitalWrite(LSmot2,LOW);  analogWrite(LSmot5,-LSspd);  break;
    default:          digitalWrite(LSmot1,LOW);digitalWrite(LSmot1,LOW);analogWrite(LSmot5,0);  break;
  }
}
