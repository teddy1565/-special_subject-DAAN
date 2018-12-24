#include <Keypad.h>    // 引用Keypad程式庫
#define KEY_ROWS 4 // 按鍵模組的列數
#define KEY_COLS 4 // 按鍵模組的行數
char keymap[KEY_ROWS][KEY_COLS] = { // 依照行、列排列的按鍵字元（二維陣列）
   {'1', '2', '3', 'A'},
   {'4', '5', '6', 'B'},
   {'7', '8', '9', 'C'},
   {'*', '0', '#', 'D'}
};
byte colPins[KEY_COLS] = {28,30,32,34};     // 按鍵模組，行1~4接腳。
byte rowPins[KEY_ROWS] = {36,22,24,26}; // 按鍵模組，列1~4接腳。 
// 初始化Keypad物件
// 語法：Keypad(makeKeymap(按鍵字元的二維陣列), 模組列接腳, 模組行接腳, 模組列數, 模組行數)
Keypad myKeypad = Keypad(makeKeymap(keymap), rowPins, colPins, KEY_ROWS, KEY_COLS);
//定義井字遊戲相關變數
int jin[3][3] = {{0,0,0},{0,0,0},{0,0,0}}; //宣告井字格
int the_round = 0;//輪到誰下棋,0為玩家1為電腦
int enableBOT = 0;//是否開啟電腦對手(默認關閉)
int gameover = false;//遊戲是否結束
int BOT_value[3][3] = {{0,0,0},{0,0,0},{0,0,0}};
int player_value[3][3] = {{0,0,0},{0,0,0},{0,0,0}};
int test = 0;
int pin[10] = {0,1,2,3,4,5,6,7,8,9};//宣告LED陣列
int color[10] = {0,0,0,0,0,0,0,0,0,0};//宣告LED顯示燈色陣列
void setup(){
	Serial.begin(9600);
	pinMode(31,OUTPUT);
	pinMode(33,OUTPUT);
	pinMode(35,OUTPUT);
	pinMode(37,OUTPUT);
	pinMode(39,OUTPUT);
	pinMode(41,OUTPUT);
	pinMode(43,OUTPUT);
	pinMode(45,OUTPUT);
	pinMode(47,OUTPUT);
}
void loop(){
	int key;
	key = get_key(); //在loop中取得選擇的位置,若沒選擇則回傳0
	
	int *thecolor = &color[key]; //選擇要改變哪個LED燈的狀態
	if(*thecolor == 0){
		int lamp = chess(key,&the_round);
		*thecolor = lamp;
	}
	
	for(int i=1;i<10;i++){
		display_led(&pin[i],&color[i]);
	}
	
}
int get_key(){  // 透過Keypad物件的getKey()function讀取按鍵的字元
    char key = myKeypad.getKey();
	int thekey;
	if(key == '1'){
		thekey = 1 ;
	}else if(key == '2'){
		thekey = 2 ;
	}else if(key == '3'){
		thekey = 3 ;
	}else if(key == '4'){
		thekey = 4 ;
	}else if(key == '5'){
		thekey = 5 ;
	}else if(key == '6'){
		thekey = 6 ;
	}else if(key == '7'){
		thekey = 7 ;
	}else if(key == '8'){
		thekey = 8 ;
	}else if(key == '9'){
		thekey = 9 ;
	}else if(key == 'A'){
		thekey = 10 ;
	}else{
		thekey = 0 ;
	}
	return thekey;
}
//確認現在是哪一方下棋
int chess(int key,int *the_round){
	if(*the_round == 0 && key!=0){
		*the_round = (*the_round+1)%2 ;
	}else if(*the_round == 1 && key!=0){
		*the_round = (*the_round+1)%2 ;
	}
	if (*the_round == 1){return 1;}else{return 2;}
}

//R = 1/G = 2
//掃描
void display_led(int *tpin,int *tcolor){
	int pin = *tpin;
	int color = *tcolor;
	if(pin == 3){
		if(color == 1){
			digitalWrite(31,LOW);
			digitalWrite(43,LOW);
			digitalWrite(37,HIGH);
			digitalWrite(35,HIGH);
			digitalWrite(33,HIGH);
			digitalWrite(45,LOW);
			digitalWrite(39,LOW);
			digitalWrite(47,LOW);
			digitalWrite(41,LOW);
			delay(1);
		}else if(color == 2){
			digitalWrite(31,LOW);
			digitalWrite(43,HIGH);
			digitalWrite(37,LOW);
			digitalWrite(35,HIGH);
			digitalWrite(33,HIGH);
			digitalWrite(45,LOW);
			digitalWrite(39,LOW);
			digitalWrite(47,LOW);
			digitalWrite(41,LOW);
			delay(1);
		}else if(color == 0){
			digitalWrite(31,LOW);
			digitalWrite(37,LOW);
			digitalWrite(43,LOW);
			digitalWrite(35,LOW);
			digitalWrite(33,LOW);
			digitalWrite(45,LOW);
			digitalWrite(39,LOW);
			digitalWrite(47,LOW);
			digitalWrite(41,LOW);
			delay(1);
		}
	}else if(pin == 2){
		if(color == 1){
			digitalWrite(31,HIGH);
			digitalWrite(43,LOW);
			digitalWrite(37,HIGH);
			digitalWrite(35,LOW);
			digitalWrite(33,HIGH);
			digitalWrite(45,LOW);
			digitalWrite(39,LOW);
			digitalWrite(47,LOW);
			digitalWrite(41,LOW);
			delay(1);
		}else if(color == 2){
			digitalWrite(31,HIGH);
			digitalWrite(43,HIGH);
			digitalWrite(37,LOW);
			digitalWrite(35,LOW);
			digitalWrite(33,HIGH);
			digitalWrite(45,LOW);
			digitalWrite(39,LOW);
			digitalWrite(47,LOW);
			digitalWrite(41,LOW);
			delay(1);
		}else if(color == 0){
			digitalWrite(31,LOW);
			digitalWrite(37,LOW);
			digitalWrite(43,LOW);
			digitalWrite(35,LOW);
			digitalWrite(33,LOW);
			digitalWrite(45,LOW);
			digitalWrite(39,LOW);
			digitalWrite(47,LOW);
			digitalWrite(41,LOW);
			delay(1);
			
		}
	}else if(pin == 1){
		if(color == 1){
			digitalWrite(31,HIGH);
			digitalWrite(43,LOW);
			digitalWrite(37,HIGH);
			digitalWrite(35,HIGH);
			digitalWrite(33,LOW);
			digitalWrite(45,LOW);
			digitalWrite(39,LOW);
			digitalWrite(47,LOW);
			digitalWrite(41,LOW);
			delay(1);
		}else if(color == 2){
			digitalWrite(31,HIGH);
			digitalWrite(43,HIGH);
			digitalWrite(37,LOW);
			digitalWrite(35,HIGH);
			digitalWrite(33,LOW);
			digitalWrite(45,LOW);
			digitalWrite(39,LOW);
			digitalWrite(47,LOW);
			digitalWrite(41,LOW);
			delay(1);
		}else if(color == 0){
			digitalWrite(31,LOW);
			digitalWrite(37,LOW);
			digitalWrite(43,LOW);
			digitalWrite(35,LOW);
			digitalWrite(33,LOW);
			digitalWrite(45,LOW);
			digitalWrite(39,LOW);
			digitalWrite(47,LOW);
			digitalWrite(41,LOW);
			delay(1);
		}
	}else if(pin == 6){
		if(color == 1){
			digitalWrite(31,LOW);
			digitalWrite(45,LOW);
			digitalWrite(39,HIGH);
			digitalWrite(35,HIGH);
			digitalWrite(33,HIGH);
			digitalWrite(43,LOW);
			digitalWrite(37,LOW);
			digitalWrite(47,LOW);
			digitalWrite(41,LOW);
			delay(1);
		}else if(color == 2){
			digitalWrite(31,LOW);
			digitalWrite(45,HIGH);
			digitalWrite(39,LOW);
			digitalWrite(35,HIGH);
			digitalWrite(33,HIGH);
			digitalWrite(43,LOW);
			digitalWrite(37,LOW);
			digitalWrite(47,LOW);
			digitalWrite(41,LOW);
			delay(1);
		}else if(color == 0){
			digitalWrite(31,LOW);
			digitalWrite(39,LOW);
			digitalWrite(45,LOW);
			digitalWrite(35,LOW);
			digitalWrite(33,LOW);
			digitalWrite(43,LOW);
			digitalWrite(37,LOW);
			digitalWrite(47,LOW);
			digitalWrite(41,LOW);
			delay(1);
		}
	}else if(pin == 5){
		if(color == 1){
			digitalWrite(31,HIGH);
			digitalWrite(45,LOW);
			digitalWrite(39,HIGH);
			digitalWrite(35,LOW);
			digitalWrite(33,HIGH);
			digitalWrite(43,LOW);
			digitalWrite(37,LOW);
			digitalWrite(47,LOW);
			digitalWrite(41,LOW);
			delay(1);
		}else if(color == 2){
			digitalWrite(31,HIGH);
			digitalWrite(45,HIGH);
			digitalWrite(39,LOW);
			digitalWrite(35,LOW);
			digitalWrite(33,HIGH);
			digitalWrite(43,LOW);
			digitalWrite(37,LOW);
			digitalWrite(47,LOW);
			digitalWrite(41,LOW);
			delay(1);
		}else if(color == 0){
			digitalWrite(31,LOW);
			digitalWrite(39,LOW);
			digitalWrite(45,LOW);
			digitalWrite(35,LOW);
			digitalWrite(33,LOW);
			digitalWrite(43,LOW);
			digitalWrite(37,LOW);
			digitalWrite(47,LOW);
			digitalWrite(41,LOW);
			delay(1);
		}
	}else if(pin == 4){
		if(color == 1){
			digitalWrite(31,HIGH);
			digitalWrite(45,LOW);
			digitalWrite(39,HIGH);
			digitalWrite(35,HIGH);
			digitalWrite(33,LOW);
			digitalWrite(43,LOW);
			digitalWrite(37,LOW);
			digitalWrite(47,LOW);
			digitalWrite(41,LOW);
			delay(1);
		}else if(color == 2){
			digitalWrite(31,HIGH);
			digitalWrite(45,HIGH);
			digitalWrite(39,LOW);
			digitalWrite(35,HIGH);
			digitalWrite(33,LOW);
			digitalWrite(43,LOW);
			digitalWrite(37,LOW);
			digitalWrite(47,LOW);
			digitalWrite(41,LOW);
			delay(1);
		}else if(color == 0){
			digitalWrite(31,LOW);
			digitalWrite(39,LOW);
			digitalWrite(45,LOW);
			digitalWrite(35,LOW);
			digitalWrite(33,LOW);
			digitalWrite(43,LOW);
			digitalWrite(37,LOW);
			digitalWrite(47,LOW);
			digitalWrite(41,LOW);
			delay(1);
		}
	}else if(pin == 9){
		if(color == 1){
			digitalWrite(31,LOW);
			digitalWrite(47,LOW);
			digitalWrite(41,HIGH);
			digitalWrite(35,HIGH);
			digitalWrite(33,HIGH);
			digitalWrite(43,LOW);
			digitalWrite(37,LOW);
			digitalWrite(45,LOW);
			digitalWrite(39,LOW);
			delay(1);
		}else if(color == 2){
			digitalWrite(31,LOW);
			digitalWrite(47,HIGH);
			digitalWrite(41,LOW);
			digitalWrite(35,HIGH);
			digitalWrite(33,HIGH);
			digitalWrite(43,LOW);
			digitalWrite(37,LOW);
			digitalWrite(45,LOW);
			digitalWrite(39,LOW);
			delay(1);
		}else if(color == 0){
			digitalWrite(31,LOW);
			digitalWrite(41,LOW);
			digitalWrite(47,LOW);
			digitalWrite(35,LOW);
			digitalWrite(33,LOW);
			digitalWrite(43,LOW);
			digitalWrite(37,LOW);
			digitalWrite(45,LOW);
			digitalWrite(39,LOW);
			delay(1);
		}
	}else if(pin == 8){
		if(color == 1){
			digitalWrite(31,HIGH);
			digitalWrite(47,LOW);
			digitalWrite(41,HIGH);
			digitalWrite(35,LOW);
			digitalWrite(33,HIGH);
			digitalWrite(43,LOW);
			digitalWrite(37,LOW);
			digitalWrite(45,LOW);
			digitalWrite(39,LOW);
			delay(1);
		}else if(color == 2){
			digitalWrite(31,HIGH);
			digitalWrite(47,HIGH);
			digitalWrite(41,LOW);
			digitalWrite(35,LOW);
			digitalWrite(33,HIGH);
			digitalWrite(43,LOW);
			digitalWrite(37,LOW);
			digitalWrite(45,LOW);
			digitalWrite(39,LOW);
			delay(1);
		}else if(color == 0){
			digitalWrite(31,LOW);
			digitalWrite(41,LOW);
			digitalWrite(47,LOW);
			digitalWrite(35,LOW);
			digitalWrite(33,LOW);
			digitalWrite(43,LOW);
			digitalWrite(37,LOW);
			digitalWrite(45,LOW);
			digitalWrite(39,LOW);
			delay(1);
		}
	}else if(pin == 7){
		if(color == 1){
			digitalWrite(31,HIGH);
			digitalWrite(47,LOW);
			digitalWrite(41,HIGH);
			digitalWrite(35,HIGH);
			digitalWrite(33,LOW);
			digitalWrite(43,LOW);
			digitalWrite(37,LOW);
			digitalWrite(45,LOW);
			digitalWrite(39,LOW);
			delay(1);
		}else if(color == 2){
			digitalWrite(31,HIGH);
			digitalWrite(47,HIGH);
			digitalWrite(41,LOW);
			digitalWrite(35,HIGH);
			digitalWrite(33,LOW);
			digitalWrite(43,LOW);
			digitalWrite(37,LOW);
			digitalWrite(45,LOW);
			digitalWrite(39,LOW);
			delay(1);
		}else if(color == 0){
			digitalWrite(31,LOW);
			digitalWrite(41,LOW);
			digitalWrite(47,LOW);
			digitalWrite(35,LOW);
			digitalWrite(33,LOW);
			digitalWrite(43,LOW);
			digitalWrite(37,LOW);
			digitalWrite(45,LOW);
			digitalWrite(39,LOW);
			delay(1);
		}
	}
}
