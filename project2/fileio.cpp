#include<cstdio>
#include<cstring>
#include<iostream>
#include<fstream>

int main(int argc, char** argv){
	if(argc<2){
		std::cout <<"need file name" << std::endl;
		return 0;
	
	}
	FILE* plyFile=  fopen(argv[1],"r");
	if(plyFile==NULL){
		std::cout << "invalid file name" << std::endl;
		return 0;
	}
	fseek(plyFile, 0, SEEK_END);
	long flength = ftell(plyFile);
	rewind(plyFile);

	std::cout << flength << std::endl;

	char* buffer=new char[flength];
	long ret_code= fread(buffer, sizeof *buffer, flength, plyFile);
	if(ret_code == flength){
		std::cout << "read success" << std::endl;
	}else if (feof(plyFile)){
		std::cout << "unexcepted EOF" << std::endl;
	}else if (ferror(plyFile)){
		std::cout << "error in reading file" << std::endl;
	}

	char* tokenedOnce = strtok(buffer, "\n");
	
	while(strcmp(tokenedOnce,"end_header")){
		tokenedOnce = strtok(NULL, "\n");	
	}

	//skip end_header;	
	tokenedOnce+= 11;
	
	float* vertex = new float[1105352*4];
	memcpy( vertex, tokenedOnce, sizeof(float) * 1105352);

	tokenedOnce += 1105352*4*3;
	
	char* buffer2= tokenedOnce;
	for(int i = 0; i != 100000; i++){
		printf("%c",buffer2);
		buffer2+= 13;
		
	}
	
	printf("%s %s", tokenedOnce, buffer);
	

}
