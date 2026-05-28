<p align="center">
  <img src="banner_semaforo.svg" alt="Banner Semáforo Inteligente" width="100%">
</p>

<h1 align="center">🚦 Semáforo Inteligente com Arduino & ARM</h1>

<p align="center">
  <img src="https://img.shields.io/badge/Arduino-UNO%20%26%20Due-00979D?style=for-the-badge&logo=arduino&logoColor=white" alt="Arduino">
  <img src="https://img.shields.io/badge/Plataforma-Wokwi-22c55e?style=for-the-badge" alt="Wokwi">
  <img src="https://img.shields.io/badge/Conceito-IA%20Embarcada-0077ff?style=for-the-badge" alt="IA Embarcada">
</p>

---

### 📝 Sobre o Projeto

Este projeto foi desenvolvido para a disciplina de **Programação de Microprocessadores e Microcontroladores**, sob a orientação do **Prof. Felipe Douglas**. 

O sistema simula um **Semáforo Inteligente** adaptativo que utiliza um sensor de presença (PIR) para otimizar o fluxo de trânsito em tempo real. Se um veículo for detectado na via secundária, o tempo do sinal verde é estendido automaticamente; caso contrário, o tempo é reduzido para priorizar o fluxo principal.

✨ **O conceito de IA Embarcada:** A lógica implementada vai além do piscar de LEDs convencional, executando uma tomada de decisão adaptativa baseada no ambiente físico.

---

### ⚙️ Funcionamento da Lógica

* 🚗 **Com Carro Detectado:** O sinal verde permanece ativo por **8 segundos**.
* 💨 **Sem Carros na Via:** O sinal verde dura apenas **4 segundos**, agilizando o tráfego.
* 🔊 **Feedback Sonoro:** Um buzzer emite sinais sonoros coordenados com as transições de luzes para acessibilidade ou alertas.

---

### 📌 Componentes e Pinagem

Abaixo está a tabela de conexões utilizada tanto para o circuito físico quanto para o ambiente de simulação:

| 🔌 Componente | 📍 Pino Arduino | 📝 Descrição / Função |
| :--- | :---: | :--- |
| 🔴 **LED Vermelho** | `8` | Parada obrigatória do fluxo |
| 🟡 **LED Amarelo** | `9` | Atenção/Transição de estado |
| 🟢 **LED Verde** | `10` | Via liberada para tráfego |
| 📡 **Sensor PIR** | `2` | Detecção de presença de veículos |
| 🔊 **Buzzer** | `11` | Alerta sonoro de transição |

---

### 🚀 Como Executar o Projeto

#### 💻 Opção 1 — Simulação Online (Recomendado)
1. Acesse o site do [Wokwi](https://wokwi.com).
2. Inicie um novo projeto utilizando o **Arduino UNO** (ou Arduino Due para testes ARM).
3. Copie o código contido no arquivo `semaforo_inteligente.ino` e cole no editor.
4. Monte o circuito seguindo as conexões da tabela acima ou baseando-se no arquivo `diagrama.png`.
5. Clique no botão **Play ▶** para ver a mágica acontecer!

#### 🛠️ Opção 2 — Hardware Real
1. Realize a montagem física dos componentes na protoboard utilizando os pinos indicados.
2. Abra a **Arduino IDE** em seu computador.
3. Carregue o arquivo `semaforo_inteligente.ino`.
4. Conecte sua placa Arduino via USB e faça o **Upload**.
5. Abra o **Monitor Serial** configurado em `9600 baud` para acompanhar os logs de detecção.

---

### 🧠 Compatibilidade e Arquitetura ARM

O projeto foi validado cross-platform! A simulação de arquitetura ARM foi realizada com sucesso no Wokwi utilizando o **Arduino Due (ARM Cortex-M3)**. Graças à camada de abstração do ecossistema Arduino, o exato mesmo código fonte opera perfeitamente em ambas as arquiteturas (AVR e ARM).

---

### 📂 Estrutura do Repositório

```text
semaforo-inteligente/
├── semaforo_inteligente.ino   # 📄 Código-fonte principal do sistema
├── diagrama.png               # 🗺️ Esquema elétrico do circuito
├── simulacao-wokwi.png        # 📸 Screenshot do ambiente rodando
├── artigo.pdf                 # 📚 Artigo acadêmico detalhado
├── video-demo.mp4             # 🎬 Demonstração prática em vídeo
└── README.md                  # 📖 Este guia de documentação
