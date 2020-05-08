#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"
#include "fs.h"

#define M_DEFAULT 0
#define M_NAME 1

char *getFileName(char *s) {
	char *filename = s;
	char *temp = s;
	int i;
	for (i = strlen(temp); i >= 0; i--) {
		if (temp[i] == '/') {
			filename = &temp[i+1];
			break;
		}
	}
	return filename;
}

void find(char  *dir, char *key) {
	int fd;
	char buf[512], *p;
	struct stat st;
	struct dirent de;

	fd = open(dir, O_RDONLY);

	fstat(fd, &st);
		memset(&buf,'\0',sizeof(buf));		
		strcpy(buf, dir);
		p = buf+strlen(buf);
		*p = '/';
		p++;

		while (read(fd, &de, sizeof(de)) == sizeof(de)) {
			if(de.inum == 0 || !strcmp(de.name, ".") || !strcmp(de.name, ".."))
				continue;
			memmove(p, de.name, strlen(de.name));
			p[strlen(de.name)] = 0;
			//char bb[100];
			fstat(open(buf, O_RDONLY), &st);
			
			if (st.type == T_FILE){
				//if (!strcmp(getFileName(buf), getFileName(key))){
					printf(1, "%s\n", buf);
			}
			else if (st.type == T_DIR) {
				find(buf, key);
			}
		}
}

int main(int argc, char *argv[]) {
	if (argc < 2){
		exit();
	}
	int a,b=0;
	int c = argc -1;
	if(!strcmp(argv[argc-2],"-d")){
		for(a=0;a<argc;a++){
			if(strcmp(argv[b],"-n")){
				find(argv[c] , argv[b+1]);
				uptime();
			}
			b++;
		}
		uptime();
	}
	else{
	}
	exit();
}
