Arthur Galvão Alves - RM554462; 
Eduardo da Silva Lima - RM554804; 
Felipe Braunstein e Silva - RM554483; 
Jefferson Junior Alvarez Urbina - RM558497;

Após a apresentação da primeira parte do projeto para os proprietários da Vinheria e eles ficaram muito satisfeitos com o resultado, porém, eles precisavam saber exatamente qual a temperatura e a umidade do depósito para ter o controle total. Para isso nós da empresa SoftEdge Dynamics incrementamos o que foi pedido.

O que foi incrementado do Projeto anterior:
- Sensor integrado DHT22 (um sensor que apresenta as mesmas características do DHT-11, porem trabalha com mais precisão);
- Um display LCD para ver os valores de temperatura, umidade e luminosidade;
- Sinalização com os LEDs e o Buzzer a luminosidade (mesmo do projeto anterior), e indicar quando a temperatura e/ou a umidade estiverem em níveis críticos;

Descrição:
Este código foi projetado para monitorar condições ambientais como temperatura, umidade e intensidade de luz usando sensores. Ele utiliza uma placa Arduino com vários componentes, incluindo um sensor DHT22 para temperatura e umidade, um sensor LDR para intensidade de luz, LEDs para indicação de status e um buzzer para alertas.

Componentes:
- Placa Arduino
- Sensor DHT22
- Sensor LDR
- LEDs (Verde, Amarelo, Vermelho)
- Buzzer

Bibliotecas Utilizadas:
- LiquidCrystal.h
- DHT.h

Variáveis:
- DHTPIN: Pino para dados do sensor DHT22
- DHTTYPE: Tipo de sensor DHT (DHT22)
- LDRPIN: Pino para o sensor LDR
- GREEN_LED, YELLOW_LED, RED_LED: Pinos para os LEDs
- BUZZER_PIN: Pino para o buzzer
Outras variáveis para armazenar leituras dos sensores e indicadores de status

Funcionalidade:
- O código lê continuamente os dados dos sensores e os exibe em um LCD 16x2.
- Calcula médias para temperatura, umidade e intensidade de luz.
- LEDs indicam o status de temperatura, umidade e intensidade de luz.
- Se algum parâmetro exceder os limites pré-definidos, o buzzer emite um alerta.

Configuração:
- Conecte os componentes conforme a configuração de pinos especificada.
- Carregue o código na placa Arduino.
- Garanta uma alimentação adequada e conexões corretas dos sensores.

Observações:
- Personalize os valores dos limites e os pinos conforme suas necessidades.
- Certifique-se de uma fiação correta para evitar erros ou mal funcionamento.
- Monitore o monitor serial para informações de depuração, se necessário.

Honorable mentions to @DarwinWasWrong who helped with the code, tks!
