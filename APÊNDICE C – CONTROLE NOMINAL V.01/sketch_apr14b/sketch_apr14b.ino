/*
  Autor: Hugo Pinheiro da Silva e Leonadro de Andrade Platon
  Data: 13/05/2017
  Licença: Distribuição livre
  Projeto e código disponivel em : https://github.com/HugoPsilvamcp/Hugo
*/


int pinoDig = 3;//Declarando a variável pinoDig como inteira, é pino de controle do motor pelo pulso pwm
int x = 0; //Declarando variável x como inteira, para receber os valores do Serial Monitor
int temp = 1000; //Declarando  variavel temp como inteira, para receber o valor de tempo mínimo do pwm 


void setup()//Configurações iniciais
{
  Serial.begin(9600); //Velocidade de comunicação 9.600 Btis/segundo
  pinMode(pinoDig, OUTPUT);//Declarando p pinoDig como uma saída de dados
}

void loop()//Laço
{
  if (Serial.available() > 0)//Avaliando a comunicação Serial
  {
    x = Serial.read() - '0'; //x recebe a leitura do serial
    if (x == 2) //Caso sejá igual a 2
    {
      temp = temp + 1000; //Incrementa o valor em 1000, tornando o pulso pwm máximo, ou seja, 2000 microssegudos.
    }
    if (x == 1) //Caso sejá igual a 2
    {
      temp = temp - 1000; //Decrementa o valor em 1000, tornando o pulso pwm mínimo, ou seja, 1000 microssegudos.
    }

    else //Caso contrário 
    {
      pwm(temp); // Chama a função pwm e envia o valor de temp
      temp = temp + 0; // Incremento nulo
    }



    if (temp > 1000) //Se o valor de temp for maior que 1000, torna temp igual a 1000.
    {
      temp = 1000; // temp recebe 1000.
    }
    if (temp < 1000) //Se o valor de temp for menor que 1000, torna temp igual a 1000.
    {
      temp = 1000; // temp recebe 1000.
    }
  }
  
  else //caso contrário
  {
    Serial.println();
    Serial.print("TEMPO LIGADO : "); // Escreve a mensagem "TEMPO LIGADO"
    Serial.println(temp); // Valor atual de temp
    Serial.print("TEMPO DESLIGADO : "); // Escreve a mensagem "TEMPO DESLIGADO"
    Serial.println(2000 - temp); // Valor atual de 2000 - temp
  }
  pwm(temp); // Chama a função pwm e envia o valor de temp
}

void pwm(int temp) // Função pwm que recebe valores interos de temp
{
  digitalWrite(pinoDig, HIGH); // Deixa o estado do pinoDig em nivel alto / High
  delayMicroseconds(temp); // Deixa o pino nesse estado ligado pelo periodo de tempo igual a temp
  digitalWrite(pinoDig, LOW); // Deixa o estado do pinoDig em nivel baixo / Low
  delayMicroseconds(2000 - temp); // Deixa o pino nesse estado ligado pelo periodo de tempo igual a 2000 - temp
}

