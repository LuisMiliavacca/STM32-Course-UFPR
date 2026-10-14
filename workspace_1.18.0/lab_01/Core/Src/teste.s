.syntax unified
 .text
 .global Toggle_LED_PA5
 .thumb_func
 Toggle_LED_PA5:
 pop {r0} // lê o dado apontado por SP e joga em r0
 subs r0, r0, #1 // subtrai 1 de r0
 bne tchau // se a flag Z do APSR não estiver setada, pula
 // para a linha tchau
 ldr r1, =0x48000014 // armazena o endereco do GPIOA->ODR em r1
 ldr r2, [r1] // lê o dado do endereco apontado por r1 e
 // armazena em r2
 eor r2, r2, #(1 << 5) // ou exclusivo -> alterna o PA5
 str r2, [r1] // joga o valor do r2 no endereco apontado por
 // r1 (GPIOA->ODR)
 mov r0, 10 // iguala r0 a 10
tchau:
 push {r0} // joga o valor de r0 para a pilha
 BX LR




