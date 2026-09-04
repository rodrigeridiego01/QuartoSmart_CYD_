#ifndef UI_H  // "Include Guard": Evita que o compilador leia este arquivo duas vezes e dê erro
#define UI_H

#include "globals.h" // Traz a tela pra cá

// Aqui você pode brincar de designer! 
// Se quiser mudar a cor do botão, basta alterar esses valores.
#define COR_CARD_ATIVO    TFT_GREEN
#define COR_CARD_INATIVO  TFT_DARKGREY

// Avisamos ao projeto que existe uma função chamada desenharCardLampada
// O "bool ativo" significa que ela espera receber Verdadeiro (ligada) ou Falso (desligada)
void desenharCardLampada(bool ativo);

#endif