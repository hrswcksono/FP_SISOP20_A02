#include "types.h"
#include "user.h"
#include "fcntl.h"
#include "stat.h"

int main(int argc, char *argv[])
{
  if(argc < 3)
  {
    printf(1, "chmod memakai 3 argumen, contoh = 'chmod' '(numeric chmod)' '(nama folder/file)'\n");
    exit();
  }

  if(argc > 2)
  {
    if((atoo(argv[1]) > 0 && atoo(argv[1]) < 1778) || atoi(argv[1]) == 0)
      if(chmod(argv[2], atoo(argv[1])))
        printf(1, "chmod %s tidak berhasil\n", argv[2]);
      else
        printf(1, "Updating permissions...\n");
    else
        printf(1, "argument salah untuk chmod...\n");
  }
  exit();
}
