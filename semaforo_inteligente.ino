/*
 * SEMAFORO INTELIGENTE COM ARDUINO
 * Disciplina: Programacao de Microprocessadores
 * Professor: Felipe Douglas
 *
 * Descricao:
 *   Sistema de semaforo inteligente que usa sensor
 *   de presenca para ajustar o tempo do verde.
 *   Conceito de IA: tomada de decisao baseada em dados
 *   do sensor (tempo adaptativo).
 *
 * Componentes:
 *   - Arduino UNO (ARM Cortex-M0 no Due / UNO usa AVR)
 *   - LED Vermelho  -> pino 8
 *   - LED Amarelo   -> pino 9
 *   - LED Verde     -> pino 10
 *   - Sensor PIR    -> pino 2 (detecta presenca/carro)
 *   - Buzzer        -> pino 11 (bip no verde)
 */

// ---- Definicao dos pinos ----
#define LED_VERMELHO  8
#define LED_AMARELO   9
#define LED_VERDE     10
#define SENSOR_PIR    2
#define BUZZER        11

// ---- Tempos base (ms) ----
#define TEMPO_VERMELHO     5000
#define TEMPO_AMARELO      2000
#define TEMPO_VERDE_NORMAL 4000
#define TEMPO_VERDE_CARRO  8000   // IA: mais tempo se detectar carro

// ---- Variaveis globais ----
bool carroDetectado = false;
unsigned long tempoVerde = TEMPO_VERDE_NORMAL;
int ciclos = 0;

// ---- Setup ----
void setup() {
  Serial.begin(9600);
  pinMode(LED_VERMELHO, OUTPUT);
  pinMode(LED_AMARELO,  OUTPUT);
  pinMode(LED_VERDE,    OUTPUT);
  pinMode(SENSOR_PIR,   INPUT);
  pinMode(BUZZER,       OUTPUT);

  Serial.println("=== SEMAFORO INTELIGENTE INICIADO ===");
  Serial.println("Aguardando ciclo...");
}

// ---- Funcao principal ----
void loop() {
  ciclos++;
  Serial.print("\n--- Ciclo #");
  Serial.println(ciclos);

  // 1. VERMELHO
  ligarLed(LED_VERMELHO);
  Serial.println("[VERMELHO] Aguardando...");

  // Leitura do sensor durante o vermelho
  carroDetectado = digitalRead(SENSOR_PIR);
  tomarDecisao();  // IA: decide o tempo do verde

  delay(TEMPO_VERMELHO);

  // 2. VERDE
  ligarLed(LED_VERDE);
  Serial.print("[VERDE] Duracao: ");
  Serial.print(tempoVerde / 1000);
  Serial.println("s");

  // Bip no buzzer ao abrir o verde
  tone(BUZZER, 1000, 200);
  delay(tempoVerde);

  // 3. AMARELO
  ligarLed(LED_AMARELO);
  Serial.println("[AMARELO] Atencao...");
  delay(TEMPO_AMARELO);
}

// ---- Liga apenas um LED ----
void ligarLed(int pino) {
  digitalWrite(LED_VERMELHO, LOW);
  digitalWrite(LED_AMARELO,  LOW);
  digitalWrite(LED_VERDE,    LOW);
  digitalWrite(pino,         HIGH);
}

/*
 * TOMADA DE DECISAO (conceito de IA embarcada)
 * Algoritmo simples de decisao adaptativa:
 * - Se sensor detectou carro -> aumenta tempo do verde
 * - Caso contrario -> usa tempo padrao
 * Isso simula um sistema de controle inteligente.
 */
void tomarDecisao() {
  if (carroDetectado) {
    tempoVerde = TEMPO_VERDE_CARRO;
    Serial.println("[IA] Carro detectado! Verde estendido para 8s.");
  } else {
    tempoVerde = TEMPO_VERDE_NORMAL;
    Serial.println("[IA] Sem carro. Verde normal de 4s.");
  }
}
