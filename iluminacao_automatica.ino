/*
 * SISTEMA DE ILUMINACAO AUTOMATICA
 * Disciplina: Programacao de Microprocessadores
 * Professor: Felipe Douglas
 *
 * Descricao:
 *   Sensor LDR mede a luminosidade do ambiente.
 *   Se estiver escuro, a lampada acende sozinha.
 *   Se estiver claro, a lampada apaga.
 *   Conceito de IA: limiar adaptativo de decisao.
 *
 * Componentes:
 *   - Arduino UNO
 *   - Sensor LDR        -> pino A0 (analogico)
 *   - Resistor 10k ohm  -> divisor de tensao com LDR
 *   - LED (lampada)     -> pino 9
 *   - LED status        -> pino 13 (embutido)
 */

#define PINO_LDR      A0
#define PINO_LAMPADA  9
#define PINO_STATUS   13

// Limiar de decisao (0-1023)
// Abaixo desse valor = escuro = lampada LIGA
#define LIMIAR        500

// Histerese: evita ficar ligando/desligando
// quando a luz esta exatamente no limiar
#define HISTERESE     30

// Variaveis globais
int leituraLDR   = 0;
bool lampacaoAtual = false;
int leituras[10];  // historico para media movel
int indice = 0;

void setup() {
  Serial.begin(9600);
  pinMode(PINO_LAMPADA, OUTPUT);
  pinMode(PINO_STATUS,  OUTPUT);

  Serial.println("=== ILUMINACAO AUTOMATICA ===");
  Serial.println("Limiar: 500 | Histerese: 30");
  Serial.println("Iniciando leituras...\n");
}

void loop() {
  // Leitura do sensor LDR
  leituraLDR = analogRead(PINO_LDR);

  // Media movel (suaviza ruido do sensor)
  leituras[indice] = leituraLDR;
  indice = (indice + 1) % 10;
  int media = calcularMedia();

  // Tomada de decisao com histerese (IA basica)
  tomarDecisao(media);

  // Log serial
  Serial.print("LDR: ");
  Serial.print(leituraLDR);
  Serial.print(" | Media: ");
  Serial.print(media);
  Serial.print(" | Lampada: ");
  Serial.println(lampacaoAtual ? "LIGADA" : "DESLIGADA");

  delay(500);
}

// Calcula media dos ultimos 10 valores
int calcularMedia() {
  long soma = 0;
  for (int i = 0; i < 10; i++) soma += leituras[i];
  return soma / 10;
}

/*
 * TOMADA DE DECISAO (IA embarcada)
 * Usa histerese para evitar oscilacao:
 * - Liga se media < (LIMIAR - HISTERESE)
 * - Desliga se media > (LIMIAR + HISTERESE)
 * - Mantem estado atual na zona intermediaria
 */
void tomarDecisao(int media) {
  if (media < (LIMIAR - HISTERESE) && !lampacaoAtual) {
    lampacaoAtual = true;
    digitalWrite(PINO_LAMPADA, HIGH);
    digitalWrite(PINO_STATUS,  HIGH);
    Serial.println("[IA] Escuro detectado! Lampada LIGADA.");

  } else if (media > (LIMIAR + HISTERESE) && lampacaoAtual) {
    lampacaoAtual = false;
    digitalWrite(PINO_LAMPADA, LOW);
    digitalWrite(PINO_STATUS,  LOW);
    Serial.println("[IA] Ambiente claro. Lampada DESLIGADA.");
  }
}
