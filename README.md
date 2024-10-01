# 2048 em C

Esses dias, senti vontade de revisitar a linguagem C, então decidi criar um joguinho que eu era viciado um tempo atrás: **2048**. O jogo é simples, porém envolvente, e foi uma ótima oportunidade para praticar um pouco de C!

## Como Compilar

Para gerar o executável do jogo, basta rodar o seguinte comando no terminal:

```bash
gcc -o 2048 main.c board/board.c logic/logic.c util/util.c -std=c99 -I board -I logic -I util
```
## Como Jogar

- Use as **W,A,S,D** para mover o grid
- Combine números iguais para somá-los.
- Seu objetivo é **chegar a 2048**

## Recursos Futuros (Que eu provavelmente nunca vou implementar)

Aqui estão algumas ideias de melhorias para o jogo, caso alguém (ou eu mesmo) queira expandir o projeto no futuro:

1. Sistema de pontuação.
2. Checar quando o jogador alcança **2048** e oferecer a opção de continuar ou encerrar o jogo.
3. Adicionar uma opção de **rewind**, para desfazer o último movimento.
4. Melhorar a organização do código e refatorar a lógica de movimentação.

```plaintext
Estrutura do projeto
 ┣ 📂 board        # Código relacionado ao tabuleiro do jogo
 ┣ 📂 logic        # Lógica do jogo, como movimentação e combinações
 ┣ 📂 util         # Funções auxiliares e utilitárias
 ┗ 📜 main.c       # Arquivo principal
```

Esse projetinho foi divertido de fazer mas assim como a maioria dos meus projetos, falta alguns pontos pra ele ficar 100% e provavelmente ele vai ficar sem esses pontos.