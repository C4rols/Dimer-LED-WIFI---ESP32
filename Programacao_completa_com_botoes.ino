// Projeto: Sensor de luz ambiente - Prô Terra - MakerZine
#include <Wire.h>
#include <WiFi.h> 
int valorLuz = 0;   //Define a variável "valorLuz" como zero
//Código da experiencia "luz pulsante"
int LED = 16;
int pinoPIR = 17;
int canal = 0;
int resolucao = 8; //8 bits
int i; //parametro referente ao duty cycle
int freq = 1000; //Dada em Hz
int contpir = 0; //Dada em Hz

//--------Conexão WIFI-----------------
const char *ssid     = "Galaxy";  //atribuir nome da rede WiFi
const char *password = "carolzinha"; //atribuir senha da rede
WiFiServer server(80); 

void relay_wifi();  


void setup()
{
 pinMode (LED, OUTPUT);
 pinMode(pinoPIR, INPUT); // Declara o pinoPIR como Entrada
 pinMode(39, INPUT);
  ledcSetup (canal, freq, resolucao);
  ledcAttachPin(LED, canal);

   Serial.begin(115200);                  //inicializa Serial em 115200 baud rate


//-------------Testar conexão-------------
  Serial.println();                      //
  Serial.print("Conectando-se a ");      //
  Serial.println(ssid);                  //
  WiFi.begin(ssid, password);            //inicializa WiFi, passando o nome da rede e a senha

  while(WiFi.status() != WL_CONNECTED)   //aguarda conexão (WL_CONNECTED é uma constante que indica sucesso na conexão)
  {
    delay(741);                          //
    Serial.print(".");                   //vai imprimindo pontos até realizar a conexão...
  }

  Serial.println("");                    //mostra WiFi conectada
  Serial.println("WiFi conectada");      //
  Serial.println("Endereço de IP: ");    //
  Serial.println(WiFi.localIP());        //mostra o endereço IP

  server.begin(); 
}
 
void loop()
{
wifi();

}

//FUNÇÃO BOTÕES E WIFI----------------------------------------------------------------------------
void wifi(){//--------------Puxa função wifi-----------------

while(WiFi.status() != WL_CONNECTED)   //aguarda conexão (WL_CONNECTED é uma constante que indica sucesso na conexão)
  {
    WiFi.begin(ssid, password);          //inicializa WiFi, passando o nome da rede e a senha
    Serial.print(".");                   //vai imprimindo pontos até realizar a conexão...

    delay(741);    
 
  }

   WiFiClient client = server.available(); 
     
if (!client) {
    return;
}
  Serial.println(F("new client"));

  client.setTimeout(5000); // default is 1000

  // Read the first line of the request
  String req = client.readStringUntil('\r');
  Serial.println(F("request: "));
  Serial.println(req);

if(req.indexOf("?Dez=") != -1) 
ledcWrite(canal, (10));
if(req.indexOf("?Vinte=") != -1) 
ledcWrite(canal, (20));
if(req.indexOf("?Trinta=") != -1) 
ledcWrite(canal, (30));
if(req.indexOf("?Quarenta=") != -1) 
ledcWrite(canal, (40));
if(req.indexOf("?Cinquenta=") != -1) 
ledcWrite(canal, (50));
if(req.indexOf("?Sessenta=") != -1) 
ledcWrite(canal, (60));
if(req.indexOf("?Setenta=") != -1) 
ledcWrite(canal, (70));
if(req.indexOf("?Oitenta=") != -1) 
ledcWrite(canal, (80));
if(req.indexOf("?Noventa=") != -1) 
ledcWrite(canal, (90));
if(req.indexOf("?Cem=") != -1) 
ledcWrite(canal, (1000));
if (req.indexOf("?Desliga=") != -1)      
ledcWrite(canal, (0));
if (req.indexOf("?Liga=") != -1)    
ledcWrite(canal, (1000));
while (req.indexOf("?Automatico=") != -1)    
teste();
while (req.indexOf("?Points=") >= 10)    
ledcWrite(canal, (10));
  
 while (client.available()) {
    // byte by byte is not very efficient
    client.read();
  }

  client.print("HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<!DOCTYPE HTML>\r\n<html>\r\n ");

   client.print("<h1><html style=\"font-size:14px\"> KPITEC Menu (Automa&ccedil;&atilde;o para Lampada)\n</h1>");
   client.print("<body style=\"background:#537C8E\"\n</b>");
   client.print("<form action=\"http://");
  client.print(WiFi.localIP());
  
  client.print("\" method=\"get\">\n");
  client.print("<b><br></br><html> Ligar LED do ESP32\n</b>");
  client.print("<p></p><button input name=\"Desliga\" style=\"height:50px;width:300px;font-size:20px;background-color:#FFAEBC;border-color:#FFAEBC;color:black\" >Desligar</button>"); //<br></br>
  client.print("<button input name=\"Liga\" style=\"height:50px;width:300px;font-size:20px;background-color:#B4F8C8;border-color:#B4F8C8;color:black\" >Ligar</button\n</b>");
  client.print("<p></p><button input name=\"Automatico\" style=\"height:50px;width:300px;font-size:20px;background-color:orange;border-color:orange;color:black\" >Modo Automatico</button\n</b>");
  client.print("<b><br></br><html> Dimer manual\n</b>");
  client.print("<p></p><button input name=\"Dez\" style=\"height:70px;width:150px;font-size:20px;background-color:#98c3ed;border-color:#98c3ed;color:black\" >10%</button\n</b>");
client.print("<p></p><button input name=\"Vinte\" style=\"height:70px;width:150px;font-size:20px;background-color:#98c3ed;border-color:#98c3ed;color:black\" >20%</button\n</b>");
client.print("<p></p><button input name=\"Trinta\" style=\"height:70px;width:150px;font-size:20px;background-color:#98c3ed;border-color:#98c3ed;color:black\" >30%</button\n</b>");
client.print("<p></p><button input name=\"Quarenta\" style=\"height:70px;width:150px;font-size:20px;background-color:#98c3ed;border-color:#98c3ed;color:black\" >40%</button\n</b>");
client.print("<p></p><button input name=\"Cinquenta\" style=\"height:70px;width:150px;font-size:20px;background-color:#98c3ed;border-color:#98c3ed;color:black\" >50%</button\n</b>");
client.print("<p></p><button input name=\"Sessenta\" style=\"height:70px;width:150px;font-size:20px;background-color:#98c3ed;border-color:#98c3ed;color:black\" >60%</button\n</b>");
client.print("<p></p><button input name=\"Setenta\" style=\"height:70px;width:150px;font-size:20px;background-color:#98c3ed;border-color:#98c3ed;color:black\" >70%</button\n</b>");
client.print("<p></p><button input name=\"Oitenta\" style=\"height:70px;width:150px;font-size:20px;background-color:#98c3ed;border-color:#98c3ed;color:black\" >80%</button\n</b>");
client.print("<p></p><button input name=\"Noventa\" style=\"height:70px;width:150px;font-size:20px;background-color:#98c3ed;border-color:#98c3ed;color:black\" >90%</button\n</b>");
client.print("<p></p><button input name=\"Cem\" style=\"height:70px;width:150px;font-size:20px;background-color:#98c3ed;border-color:#98c3ed;color:black\" >100%</button\n</b>");
  client.print("<p></p>");
 client.print("<label for=\"dimerizacao manual\">Points (between 0 and 100):</label>ideia futura\n</b>");
 client.print("<input type=\"range\" id=\"points\" name=\"Points\" value=\"0\" min=\"0\" max=\"100\">");
 
//IDEIA FUTURA - AJUSTA DIMER BOTAO---------------------------------------------------------------





 client.print("</form>\n");
 client.print("</body>\n");
 client.print("<body style=\"background:#537C8E\"\n</b>");
    
  client.print("</html>");

 
 Serial.println(F("Disconnecting from client"));
}




//PROGRAMAÇÃO MODO AUTOMÁTICO------------------------------------------
void teste(){

  contpir=0;
  contpir= (digitalRead(pinoPIR));
   valorLuz = (analogRead(39));  //Faz a leitura da porta A0 e armazena em "valorLuz"  


//Lógica LDR   
  if (valorLuz > 3000){ //se estiver claro
    ledcWrite(canal, (10));
    if (contpir==1) {      
    ledcWrite(canal,(500));   
   
  }
  }
 if (valorLuz < 3000){ 
    ledcWrite(canal,(50));
      if (contpir==1) { 
         ledcWrite(canal,(1000));
             }
  }
 while(WiFi.status() != WL_CONNECTED)   //aguarda conexão (WL_CONNECTED é uma constante que indica sucesso na conexão)
  {
    WiFi.begin(ssid, password);          //inicializa WiFi, passando o nome da rede e a senha
    Serial.print(".");                   //vai imprimindo pontos até realizar a conexão...

    delay(741);    
 
  }

   WiFiClient client = server.available(); 
     
if (!client) {
    return;
}
  Serial.println(F("new client"));

  client.setTimeout(5000); // default is 1000
     

  // Read the first line of the request
  String req = client.readStringUntil('\r');
  Serial.println(F("request: "));
  Serial.println(req);

  // Read the first line of the request

while(req.indexOf("?Dez=") != -1) loop();
while(req.indexOf("?Vinte=") != -1) loop();
while(req.indexOf("?Trinta=") != -1) loop();
while(req.indexOf("?Quarenta=") != -1) loop();
while(req.indexOf("?Cinquenta=") != -1) loop();
while(req.indexOf("?Sessenta=") != -1) loop();
while(req.indexOf("?Setenta=") != -1) loop();
while(req.indexOf("?Oitenta=") != -1) loop();
while(req.indexOf("?Noventa=") != -1) loop();
while(req.indexOf("?Cem=") != -1) loop();
while (req.indexOf("?Desliga=") != -1)      
loop();
if (req.indexOf("?Liga=") != -1)    
loop();

 while (client.available()) {
    // byte by byte is not very efficient
    client.read();
  }

  client.print("HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<!DOCTYPE HTML>\r\n<html>\r\n ");

   client.print("<h1><html style=\"font-size:14px\"> KPITEC Menu (Automa&ccedil;&atilde;o para Lampada)\n</h1>");
   client.print("<body style=\"background:#537C8E\"\n</b>");
   client.print("<form action=\"http://");
  client.print(WiFi.localIP());
  
  client.print("\" method=\"get\">\n");
  client.print("<b><br></br><html> Ligar LED do ESP32\n</b>");
  client.print("<p></p><button input name=\"Desliga\" style=\"height:50px;width:300px;font-size:20px;background-color:#FFAEBC;border-color:#FFAEBC;color:black\" >Desligar</button>"); //<br></br>
  client.print("<button input name=\"Liga\" style=\"height:50px;width:300px;font-size:20px;background-color:#B4F8C8;border-color:#B4F8C8;color:black\" >Ligar</button\n</b>");
  client.print("<p></p><button input name=\"Automatico\" style=\"height:50px;width:300px;font-size:20px;background-color:orange;border-color:orange;color:black\" >Modo Automatico</button\n</b>");
  client.print("<b><br></br><html> Dimer manual\n</b>");
  client.print("<p></p><button input name=\"Dez\" style=\"height:70px;width:150px;font-size:20px;background-color:#98c3ed;border-color:#98c3ed;color:black\" >10%</button\n</b>");
client.print("<p></p><button input name=\"Vinte\" style=\"height:70px;width:150px;font-size:20px;background-color:#98c3ed;border-color:#98c3ed;color:black\" >20%</button\n</b>");
client.print("<p></p><button input name=\"Trinta\" style=\"height:70px;width:150px;font-size:20px;background-color:#98c3ed;border-color:#98c3ed;color:black\" >30%</button\n</b>");
client.print("<p></p><button input name=\"Quarenta\" style=\"height:70px;width:150px;font-size:20px;background-color:#98c3ed;border-color:#98c3ed;color:black\" >40%</button\n</b>");
client.print("<p></p><button input name=\"Cinquenta\" style=\"height:70px;width:150px;font-size:20px;background-color:#98c3ed;border-color:#98c3ed;color:black\" >50%</button\n</b>");
client.print("<p></p><button input name=\"Sessenta\" style=\"height:70px;width:150px;font-size:20px;background-color:#98c3ed;border-color:#98c3ed;color:black\" >60%</button\n</b>");
client.print("<p></p><button input name=\"Setenta\" style=\"height:70px;width:150px;font-size:20px;background-color:#98c3ed;border-color:#98c3ed;color:black\" >70%</button\n</b>");
client.print("<p></p><button input name=\"Oitenta\" style=\"height:70px;width:150px;font-size:20px;background-color:#98c3ed;border-color:#98c3ed;color:black\" >80%</button\n</b>");
client.print("<p></p><button input name=\"Noventa\" style=\"height:70px;width:150px;font-size:20px;background-color:#98c3ed;border-color:#98c3ed;color:black\" >90%</button\n</b>");
client.print("<p></p><button input name=\"Cem\" style=\"height:70px;width:150px;font-size:20px;background-color:#98c3ed;border-color:#98c3ed;color:black\" >100%</button\n</b>");
  client.print("<p></p>");
 client.print("<label for=\"dimerizacao manual\">Points (between 0 and 100):</label>ideia futura\n</b>");
 client.print("<input type=\"range\" id=\"points\" name=\"Points\" value=\"0\" min=\"0\" max=\"100\">");
 
//IDEIA FUTURA - AJUSTA DIMER BOTAO---------------------------------------------------------------





 client.print("</form>\n");
 client.print("</body>\n");
 client.print("<body style=\"background:#537C8E\"\n</b>");
    
  client.print("</html>");

 
 Serial.println(F("Disconnecting from client"));



}


 
