# Semáforo Inteligente com Arduino

Projeto da disciplina **Programação de Microprocessadores
e Microcontroladores** — Prof. Felipe Douglas.

## Descrição
Sistema de semáforo que usa um sensor de presença
para ajustar automaticamente o tempo do sinal verde.
Se um carro for detectado, o verde dura 8 segundos.
Caso contrário, dura apenas 4 segundos.

Isso implementa um conceito básico de **IA embarcada**:
tomada de decisão adaptativa baseada em sensor.

## Componentes
| Componente      | Pino Arduino |
|-----------------|-------------|
| LED Vermelho    | 8           |
| LED Amarelo     | 9           |
| LED Verde       | 10          |
| Sensor PIR      | 2           |
| Buzzer          | 11          |

## Como executar

### Opção 1 — Simulação online (recomendado)
1. Acesse https://wokwi.com
2. Crie novo projeto Arduino UNO
3. Cole o código de `semaforo_inteligente.ino`
4. Monte o circuito conforme o diagrama
5. Clique em Play ▶

### Opção 2 — Hardware real
1. Monte o circuito conforme o diagrama
2. Abra o Arduino IDE
3. Carregue o arquivo `semaforo_inteligente.ino`
4. Faça upload para o Arduino
5. Abra o Monitor Serial (9600 baud)

## Arquitetura ARM
A simulação ARM foi realizada no Wokwi usando
Arduino Due (ARM Cortex-M3). O mesmo código
funciona em ambos os processadores.

## Estrutura do repositório
```
semaforo-inteligente/
├── semaforo_inteligente.ino   # código principal
├── diagrama.png               # esquema do circuito
├── simulacao-wokwi.png        # screenshot da simulação
├── artigo.pdf                 # artigo acadêmico
├── video-demo.mp4             # vídeo de demonstração
└── README.md                  # este arquivo
```

## Autor
[Daniel R. Damasceno] — [Cienca da Computacao] — [2026]
