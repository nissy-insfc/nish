#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

//入力受付
char *getCmd(void){
	int c;//入力された文字
	static char buf [96];//文字バッファ用配列
	int count = 0;//文字数位置カウンタ

	while(1){
		c = getchar();//1文字ずつ取得
		buf[count] = c;//バッファに溜める
		
		if(c == EOF || c == '\n'){//EOFまたはエンター入力時
			buf[count] = '\0';//文字列を閉じる
			return buf;//取得した文字列を返す
		}

		count++;//カウンタ加算
	
		if(count>=96){//文字数超過時
			exit(1);//異常終了
		}
	}

}


//パース
char *parseCmd(char *line){
	static char psdLine[96];
	static char *pPsdLine,*pLine;

	pLine = line;
	pPsdLine = pLine;

	return pPsdLine;
}


int execCmd(char *usrCmd){
	pid_t pid, wpid;
	int status;

	if (usrCmd == NULL){
		return 1;
	}else{
		char *const args[]={
			usrCmd,
			NULL
			};

		pid=fork();
		
		if(pid==0){
			if(execvp(args[0],args)==-1){
				perror("exec error");
			}
		}else{
			wait(&status);
		}
		
		return 0;
	}
}


int main(){
	char *line;
	char *cmd;
	char *usrCmd;

	printf(">>>");

	line = getCmd();
	usrCmd = parseCmd(line);
	execCmd(usrCmd);

//	printf("%s world!\n",usrCmd);
	
	return 0;
}
