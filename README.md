# Printf - Recriando um Clássico da Programação em C

## Visão Geral
O projeto **Printf** reimagina a clássica função `printf` da biblioteca C, um desafio técnico que explora a profundidade da formatação de saída e conversão de tipos em programação. Essa implementação é parte de minha trajetória educacional na [42 School](https://www.42.fr/), visando não apenas replicar a funcionalidade, mas também compreender o intricado funcionamento interno de uma das funções mais utilizadas em C.

## Funcionalidades
- **Compatibilidade Extensa**: Capaz de processar diversos especificadores de formato, como `%s`, `%d`, `%x`, e muitos outros, replicando a flexibilidade da `printf` original.
- **Personalização**: Inclui recursos adicionais e melhorias, estendendo a funcionalidade para além da implementação padrão.
- **Código Testável e Confiável**: Rigorosamente testada para assegurar precisão e confiabilidade nas conversões e na formatação de saída.

## Como Utilizar
Integre esta versão personalizada do `printf` em seus projetos C para experimentar a versatilidade e robustez de uma implementação clássica:

1. Clone o repositório:
   ```
   git clone https://github.com/renanbatista/printf.git
   ```
2. Compile a biblioteca com seus projetos para acessar a função `ft_printf`.

## Exemplo de Implementação
Utilize a `ft_printf` assim como usaria a função `printf` original:
```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("String: %s, Int: %d, Hex: %x\n", "example", 42, 42);
    return 0;
}
```

## Contribuições
A contribuição para o projeto `printf` é bem-vinda, seja refinando o código, expandindo a cobertura de formatos ou otimizando a performance. Para contribuir, faça um fork, realize suas melhorias e submeta um pull request.

## Observações
Este projeto foi meticulosamente desenvolvido em conformidade com as normas de codificação da 42 School, enfatizando um código bem estruturado, eficiente e modular.

## Licença
Este projeto `printf` é disponibilizado sob a MIT License, encorajando o uso e a colaboração aberta.
