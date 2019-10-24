#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>

int main ()
{
  const char *path = "./tmp";
	DIR *dir = opendir(path);

	if (dir == NULL) {
		perror("Couldn't open dir");
		exit(1);
	}
	struct dirent *ent;
	struct stat st;
	char buf[1024];
  ino_t inode_number[10] = {0};
  int index = 0;
	while ((ent = readdir(dir)) != NULL) {
  	snprintf(buf, sizeof(buf), "%s/%s", path , ent->d_name);
  	if (stat(buf, &st) < 0) {
  		perror("stat");
  		continue;
  	}
    int flag = 0;
    for (size_t i = 0; i < 10; i++) {
      if (inode_number[i] == st.st_ino){
        flag = 1;
        break;
      }
    }

    if (flag) continue;

    if (!S_ISREG(st.st_mode)) continue;
    if (st.st_nlink > 1) {
      inode_number[index] = st.st_ino;
      printf("%llu has %d hard links\n", inode_number[index], st.st_nlink);
    } else { continue; }

    struct stat st_new;
    struct dirent *ent_new;
    char buf_new[1024];
    DIR *dir_2 = opendir(path);
  	while ((ent_new = readdir(dir_2)) != NULL) {
      snprintf(buf_new, sizeof(buf_new), "%s/%s", path , ent_new->d_name);
      stat(buf_new, &st_new);
      if (inode_number[index] == st_new.st_ino){
        printf("\t- %s\n", ent_new->d_name);
      }
    }
    closedir(dir_2);

    index++;
	}
	closedir(dir);

	return 0;
}
