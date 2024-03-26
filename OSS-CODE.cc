// PROJETO VINÍCULA - OPEN SOURCE SOFTWARE

// Definindo a qual pino os Leds estão ligados:
int LED_PIN_RED = 10; // Define a qual pino o Led Vermelho está ligado
int LED_PIN_YELLOW = 9;// Define a qual pino o Led Amarelo está ligado
int LED_PIN_GREEN = 8; // Define a qual pino o Led Verde está ligado

int IntensidadeLuz; //Criação da Variável que futuramente converterá os valores do LDR para %
int BUZZER = 13;// Define a qual pino o Buzzer está ligado
int LDR_PIN = A0;// Define que o LDR está ligado na entrada Analógica 0

void setup() {
  Serial.begin(9600);// Inicializa a Comunicação Serial
  pinMode (LDR_PIN, INPUT); //Define o LDR como INTPUT

  // Define os LED's e o Buzzer como output
  pinMode(LED_PIN_RED, OUTPUT);
  pinMode(LED_PIN_YELLOW, OUTPUT);
  pinMode(LED_PIN_GREEN, OUTPUT);
  pinMode(BUZZER, OUTPUT);
}

void loop() {
  
  int ValorLDR = analogRead(LDR_PIN); //leitura, definição e exibição dos valores do LDR através do comando 'analogRead', que converte dados analógicos do LDR em dados digitais
  IntensidadeLuz = map(ValorLDR, 0, 1023, 0, 100); //Comando 'map' foi usado para transformar os valores do LDR em valores percentuais, ou seja, valores de 0 a 100
  Serial.println(IntensidadeLuz); //Printando os valores percentuais do LDR para o usuário a partir do comando 'Serial.Println'

  // Estabeleçendo condicionais dos Leds Baseados nos valores percentuais do LDR

  //condicional do Led Vermelho (luminosidade alta)
  if (IntensidadeLuz < 50) { 
    analogWrite(LED_PIN_RED, 255); // Faz com que o Led vermelho brilhe
    analogWrite(LED_PIN_YELLOW, 0); // Faz com que o Led amarelo apague
    analogWrite(LED_PIN_GREEN, 0); // Faz com que o Led verde apague
    tone(BUZZER,400,1500); // Este comando faz o buzzer acionar 1 vez, com uma certa frequência e duração de tempo (BUZZER, Freq ,Temp)
    delay(1000);
    tone(BUZZER,500,1500); 
    delay(1000);
  } 

  //condicional do Led Amarelo (luminosidade média)
  else if (IntensidadeLuz < 65) {
    analogWrite(LED_PIN_RED, 0); // Faz com que o Led vermelho apague
    analogWrite(LED_PIN_YELLOW, 255); // Faz com que o Led amarelo brilhe
    analogWrite(LED_PIN_GREEN, 0); // Faz com que o Led verde apague
  } 

  //condicional do Led Verde (luminosidade baixa)
  else if (IntensidadeLuz < 100) {
    analogWrite(LED_PIN_RED, 0); // Faz com que o Led vermelho apague
    analogWrite(LED_PIN_YELLOW, 0); // Faz com que o Led amarelo apague
    analogWrite(LED_PIN_GREEN, 255); // Faz com que o Led verde brilhe
  }
}
