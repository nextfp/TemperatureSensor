# 元々の Arduino 基盤(NU22)

A6: ギアポジションとして使用(analogRead)。降圧せずそのまま。プログラム上では 1.6V~4.7V?  
A7: 水温として使用(analogRead)

# esp32 案(nu23)

確定しているピン  
15 :ディスプレイ cs  
4 :ディスプレイ reset  
2 :ディスプレイ dc  
23 :ディスプレイ mosi  
18 :ディスプレイ sck  
5 :SD カード cs  
23 :sd カード MOSI  
19 :sd カード MISO  
18 :sd カード sck

思考中のピン(おおよそ決定)  
32 :水温?  
33 :ギアポジ?

保留中  
35 :舵角  
25 :舵角リセット(digitalRead なのでどこでも)  
26 :gpsRead(要実験) (どこでも)  
27 :gpsWrite(要実験) (どこでも)
