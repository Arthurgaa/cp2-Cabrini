Após a apresentação da primeira parte do projeto para os proprietários da Vinheria e eles ficaram muito satisfeitos com o resultado, porém, eles precisavam saber exatamente qual a temperatura e a umidade do depósito para ter o controle total. Para isso nós da empresa SoftEdge Dynamics incrementamos o que foi pedido.

O que foi incrementado do Projeto interior:
- Sensor integrado DHT11;
- Um display LCD para ver os valores de temperatura, umidade e luminosidade;
- Sinalização com os LEDs e o Buzzer a luminosidade (mesmo do projeto anterior), e indicar quando a temperatura e/ou a umidade estiverem em níveis críticos;

Requisitos do Projeto:
1. Enquanto o ambiente estiver escuro, o LED Verde deve ficar aceso;
2. Enquanto o ambiente estiver a meia luz, o LED amarelo deve ficar aceso e mensagem de
“Ambiente a meia luz” deve ser mostrado no Display;
3. Enquanto o ambiente estiver totalmente iluminado, o LED vermelho deve ficar aceso e a
mensagem “Ambiente muito claro” deve ser mostrado no display;
4. Enquanto o ambiente estiver totalmente iluminado, o Buzzer deve ficar ligado
continuamente;
5. Enquanto o ambiente estiver com uma temperatura entre 10°C e 15°C, o Display deve
informar “Temperatura OK” e também mostrar o valor da temperatura;
6. Enquanto o ambiente estiver com uma umidade entre 50% e 70%, o Display deve
informar “Umidade OK”, e também mostrar o valor da umidade;
7. Os valores apresentados no display devem ser a média de pelo menos 5 leituras dos
sensores, e os valores devem ser apresentados a cada 5 segundos;
8. Enquanto a temperatura estiver fora da faixa ideal, o LED Amarelo deve ficar aceso e o
Buzzer deve ligar continuamente;
9. Enquanto a temperatura estiver fora da faixa ideal, o Display deve informar “Temperatura
Alta”, para valores acima de 15°C e também mostrar a temperatura;
10. Enquanto a temperatura estiver fora da faixa ideal, o Display deve informar “Temperatura
Baixa”, para valores abaixo de 10°C e também mostrar a temperatura;
11. Enquanto a umidade estiver fora da faixa ideal, o LED Vermelho deve ficar aceso e o
Buzzer deve ligar continuamente;
12.Enquanto a umidade estiver fora da faixa ideal, o Display deve informar “Umidade Alta”,
para valores acima de 70% e também mostrar a umidade;
13.Enquanto a umidade estiver fora da faixa ideal, o Display deve informar “Umidade Baixa”,
para valores abaixo de 50% e também mostrar a umidade;
14. Obrigatório o uso da função map() para os valores de luminosidade;
15. Os valores devem ser medidos durante 10 ciclos de execução, após esses ciclos
apresentar os valores médios;
16. Apresentar o logo animado da equipe no Display durante a inicialização do equipamento.

