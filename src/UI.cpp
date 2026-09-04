#include "UI.h"

void desenharCardLampada(bool ativo) {
    // Coordenadas da tela (0,0 é o canto superior esquerdo)
    int x = 10;  // Distância da borda esquerda
    int y = 140; // Distância do topo
    int w = 150; // Largura do botão (width)
    int h = 60;  // Altura do botão (height)
    int raio = 8; // Arredondamento das bordas

    if (ativo) {
        // fillRoundRect desenha um retângulo com bordas arredondadas preenchido
        lcd.fillRoundRect(x, y, w, h, raio, COR_CARD_ATIVO);
        
        // Configura o texto que vai por cima do botão
        lcd.setTextColor(TFT_BLACK);
        lcd.setTextSize(2);
        
        // drawString escreve o texto na coordenada especificada
        // Somamos um pouquinho ao x e y para o texto não ficar colado na borda do botão
        lcd.drawString("LUZ LIGADA", x + 15, y + 22); 
    } else {
        lcd.fillRoundRect(x, y, w, h, raio, COR_CARD_INATIVO);
        lcd.setTextColor(TFT_WHITE);
        lcd.setTextSize(2);
        lcd.drawString("LUZ DESLIG.", x + 15, y + 22);
    }
}