/*
 *Autor: Hugo Pinheiro da Silva e Leonadro de Andrade Platon
 *Data: 20/05/2017
 *Licença: Distribuição livre
 *Código base do autor: ELECTRONOOBS
 *Código base disponivel em: http://www.electronoobs.com/eng_robotica_tut5_1.php
 *Projeto e código disponivel em : https://github.com/HugoPsilvamcp/Hugo
*/


#include <Servo.h> // Inclui a bibilote servo, que será utilizada

#define sinal_maximo 2000 //Define o sinal maximo
#define sinal_minimo 1000 //Define o sinal minimo
#define motor_direita 3   //Define o pino 3 para calibrar o motor/ESC da direita
#define motor_esquerda 5  //Define o pino 5 para calibrar o motor/ESC da esquerda

int atraso = 1000; //Declara o atraso igual a 1000

Servo motor_dir;
Servo motor_esq;


void setup()
{
  Serial.begin(9600); //Taxa de transmição de dados, de 9600 bits/segundo
  Serial.println("CALIBRACAO DO ESC..."); //Mostra na tela a mensagem "CALIBRAÇÃO DO ESC"
  Serial.println(" ");
  delay(1500); //Delay de 1500 milissegundos
  Serial.println("Inicinado Programa..."); //Mostra na tela a mensagem "Iniciando o Programa"
  delay(1000); //Delay de 1500 milissegundos
  Serial.println("Esse programa ira configurar o ESC"); //Mostra na tela a mensagem "Esse programa irá configurar o ESC"

  motor_dir.attach(motor_direita);  //Configurando que o motor da direita será manipulado pelo pino  3 (motor_direita)
  motor_esq.attach(motor_esquerda); //Configurando que o motor da esquerda será manipulado pelo pino 5 (motor_esquerda)

  Serial.print("Agora escrevendo a maxima saida: ("); Serial.print(sinal_maximo); Serial.print(" Para esse caso)"); Serial.print("\n"); //Mostra na tela a mensagem que está entre ""
  Serial.println("Ligue a fonte de forca, entao espere 2 segundos  e precione qualquer tecla.");  //Mostra na tela a mensagem que está entre ""
  motor_dir.writeMicroseconds(sinal_maximo); //Escreve o sinal maximo no motor da direita
  motor_esq.writeMicroseconds(sinal_maximo); //Escreve o sinal maximo no motor da esquerda

  //Esperando por uma entrada
  while (!Serial.available()); //Enquanto o serial é avaliado
  Serial.read(); //Leitura do serial

  //Enviando minima saida
  Serial.println("\n");
  Serial.println("\n");
  Serial.print("Enviando a minima saida: ("); Serial.print(sinal_minimo); Serial.print(" Para esse caso)"); Serial.print("\n");
  motor_dir.writeMicroseconds(sinal_minimo); //Escreve o sinal minimo no motor da direita
  motor_esq.writeMicroseconds(sinal_minimo); //Escreve o sinal minimo no motor da esquerda
  Serial.println("Este ESC esta calibrado"); //Mostra na tela a mensagem "Este ESC esta calibrado"
  Serial.println("----");
  Serial.println("Agora, digite um valor entre 1000 e 2000 e pressione enter"); //Mostra na tela a mensagem que está entre ""
  Serial.println("Entao o motor ira iniciar a rodar"); //Mostra na tela a mensagem que está entre ""
  Serial.println("Envie 1000 para parar o motor e 2000 para maxima rotacao"); //Mostra na tela a mensagem que está entre ""
}

void loop()
{
  if (Serial.available() > 0)
  {
    int atraso = Serial.parseInt();

    if (atraso > 999)
    {
      motor_dir.writeMicroseconds(atraso);
      float velocidade = (atraso - 1000) / 10;
      Serial.print("\n");
      Serial.println("Velocidade do motor: "); Serial.print(velocidade); Serial.print("%");
    }
  }
}
