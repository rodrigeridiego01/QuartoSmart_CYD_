#include <Arduino.h>
#include "globals.h"
#include "UI.h"

// Lembra do 'extern LGFX_CYD lcd' no globals.h? 
// É aqui que a gente cria a tela de verdade, ocupando memória física no ESP32.
LGFX_CYD lcd; 

// Variáveis para controlar o tempo sem usar o delay() (que trava o processador)
unsigned long ultimoTempo = 0;
int contador = 0;
bool estadoLuz = false;

void setup() {
    Serial.begin(115200);
    
    // Pino 21 controla a luz de fundo da sua placa CYD específica
    pinMode(21, OUTPUT);
    digitalWrite(21, HIGH); 

    // Inicia a comunicação com a tela e a coloca no Modo Paisagem (1)
    lcd.init();
    lcd.setRotation(1); 
    
    // Pinta a tela inteira de preto para começar limpo
    lcd.fillScreen(TFT_BLACK);
}

void loop() {
    // Essa matemática simples verifica se já se passou 1000 milissegundos (1 segundo)
    // Isso é nível profissional: deixa o loop rodando solto para ouvir botões e sensores depois!
    if (millis() - ultimoTempo >= 1000) {
        ultimoTempo = millis(); // Atualiza a referência de tempo
        contador++;

        // Ao invés de apagar a tela toda (o que causa piscadas feias),
        // apagamos só um retângulo na parte de cima onde o texto vai mudar.
        lcd.fillRect(0, 0, 320, 130, TFT_BLACK);

        // Escrevemos os textos de status
        lcd.setTextColor(TFT_CYAN);
        lcd.setTextSize(2);
        lcd.setCursor(10, 20); // Posiciona o "cursor" invisível antes de escrever
        lcd.println("PAINEL DO QUARTO");

        lcd.setTextColor(TFT_WHITE);
        lcd.setCursor(10, 60);
        lcd.println("Modo Paisagem OK!");
        
        lcd.setCursor(10, 100);
        lcd.setTextColor(TFT_YELLOW);
        // O printf permite injetar uma variável (%d) no meio do texto
        lcd.printf("Tempo ligado: %d s\n", contador);

        // Uma lógica boba só para testar a interface:
        // A cada 3 segundos, ele inverte a variável 'estadoLuz' (de true pra false e vice-versa)
        if (contador % 3 == 0) {
            estadoLuz = !estadoLuz;
            // Chama a função que você aprendeu no UI.cpp
            desenharCardLampada(estadoLuz);
        }
    }
}