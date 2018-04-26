//Pino  de  controle  do  motor
int  pinoDig  =  3;//Definindo  o  pino  digital  3  como  inteiro, é  pino  de  controle  do  motor-saida  do  pulso  PWM.
//Declarando variavel  para  receber  o  meu  comando de + ou -
int x = 0; //Declarando  variavel  para  contar  delay
int  temp = 1000;//Tempo inicial de 1000 microssegundos ou 1ms


void setup()//Configurações iniciais
{
  Serial.begin(9600); //Comunicação com a porta serial, com velocidade de 9600 bits/segundo
  pinMode(pinoDig, OUTPUT); //Definindo a pino declarado como uma saída
}

void loop()//Laço
{
  if (Serial.available() > 0) //Coondicional para receber a leitura do serial
  {
    //  1  para  menos  e  2  para  mais  de  delay
    x = Serial.read() - '0';

    if (x == 2) //Caso a leitura seja igual á 2, o valor do temp será incrementado em 20, ou seja, mais 20 microssegundos
    {
      temp = temp + 20; //Incrementando o temp em 20 microssegundos
    }

    if (x == 1) //Caso a leitura seja igual á 1, o valor do temp será decrementado em 20, ou seja, menos 20 microssegundos
    {
      temp = temp - 20; //Decrementando o temp em 20 microssegundos
    }

    else //Caso contrario
    {
      pwm(temp); //O PWM recebe o valor do temp
      temp = temp + 0; //E incrementado um valor nulo
    }

    //Limitadores de PWM
    if (temp > 2000) //Caso o temp sejá maior que 2000 microssegundos, o condicional tornará o tempo igual á 1000.
    {
      temp = 2000; //temp recebendo o valor de 2000 microssegundos
    }
    if (temp < 1000) //Caso o temp sejá menor que 1000 microssegundos, o condicional tornará o tempo igual á 1000.

    {
      temp = 1000; //temp recebendo o valor de 2000 microssegundos
    }
  }

  else //Caso contrário, o serial monitor mostrará o tempo ligado do PWM, o tempo desligado do sinal de PWM
  {
    Serial.print("TEMPO  LIGADO  :  "); Serial.println(temp); Serial.print("TEMPO  DESLIGADO  :  "); Serial.println(20000 - temp);
  }
  pwm(temp); //Escrita do sinal PWM de acordo com o valor temp
}

void  pwm(int  temp) //Função PWM para ecrever o sinal
{
  digitalWrite(pinoDig, HIGH); delayMicroseconds(temp); digitalWrite(pinoDig, LOW); delayMicroseconds(2000 - temp);
  //Escreve o sinal ligado por um certo tempo igual ao valor de temp e escreve um sinal desligado por um certo tempo de acordo com a formula (2000 - temp)
}

