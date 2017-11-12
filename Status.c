
/*
    @PrinceMughal_
    mughalb9291@gmail.com
    Prince Mughal
    Date: 12-11-2017[DD-MM-YYYY]
    Time: 06:15:53[HH:MM:SS] PM Sunday 
    Permission is Granted ,
    You may remove my name , When You do Modification in Code . :) 


*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/* R= Read , W= Write , X= Execute 
   U= User , G= Group , O= Others */

#define S_IRWG    6
#define S_IRXG    5
#define S_IWXG    3
#define S_IRWU    6
#define S_IRXU    5
#define S_IWXU    3
#define S_IRWO    6
#define S_IRXO    5
#define S_IWXO    3

int main(int argc, char** argv){


/* Commandline Argument Handler */
if(argc > 2 || argc < 2){
    fprintf(stderr,"Error: Invalid Option. \n");
    fprintf(stdout,"USAGE: %s pathname\n",argv[0]);
    exit(EXIT_FAILURE);}
/* File Status Buffer */
struct stat Status;
/* Check Status */
if(stat(argv[1],&Status)){
    fprintf(stdout,"Error: stat() Failed.\n");
    exit(EXIT_FAILURE);}
/* Print Out All Attribute(s) */
fprintf(stdout," -: FILE STATUS :- \n");
fprintf(stdout,"Device ID         :  %ld         \n", (long)      Status.st_dev);
fprintf(stdout,"-> MAJOR_ID[%u] -> MINOR_ID[%u] \n",major(Status.st_dev),minor(Status.st_dev));
fprintf(stdout,"Inode NUM         :  %ld         \n", (long)      Status.st_ino);
fprintf(stdout,"Mode PROT         :  %lo         \n", (long)      Status.st_mode);
/* File Type Handler */
switch(Status.st_mode & S_IFMT){
    case S_IFSOCK:
        fprintf(stdout,"-> FILE_TYPE[`SOCKET`]\n");
    break;
    case S_IFLNK:
        fprintf(stdout,"-> FILE_TYPE[`SYMBOLIC LINK`]\n");
    break;
    case S_IFREG:
        fprintf(stdout,"-> FILE_TYPE[`REGULAR`]\n");
    break;
    case S_IFBLK:
        fprintf(stdout,"-> FILE_TYPE[`BLOCK`]\n");
    break;
    case S_IFDIR:
        fprintf(stdout,"-> FILE_TYPE[`DIRECTORY`]\n");
    break;
    case S_IFCHR:
        fprintf(stdout,"-> FILE_TYPE[`CHARACTER`]\n");
    break;
    case S_IFIFO:
        fprintf(stdout,"-> FILE_TYPE[`PIPE`]\n");
    break;
    default:
        fprintf(stderr,"Error: Unknow File Type.\n");}
/* USER Permission Handler */
switch(000700 & Status.st_mode){
    case S_IRWXU:
        fprintf(stdout,"-> USER: Read, Write and Execute Permission\n");
    break;
    case S_IRUSR:
        fprintf(stdout,"-> USER: Read Only Permission\n");
    break;
    case S_IWUSR:
        fprintf(stdout,"-> USER: Write Only Permission\n");
    break;
    case S_IXUSR:
        fprintf(stdout,"-> USER: Execute Only Permission\n");
    break;
    case S_IRWU:
        fprintf(stdout,"-> USER: Read and Write Only Permission\n");
    break;
    case S_IRXU:
        fprintf(stdout,"-> USER: Read and Execute Only Permission\n");
    break;
    case S_IWXU:
        fprintf(stdout,"-> USER: Write and Execute Onlye Permission\n");
    break;}
/* Group Permission Handler */
switch(000070 & Status.st_mode){
    case S_IRWXG:
        fprintf(stdout,"-> GROUP: Read, Write and Execute Permission\n");
    break;
    case S_IRGRP:
        fprintf(stdout,"-> GROUP: Read Only Permission\n");
    break;
    case S_IWGRP:
        fprintf(stdout,"-> GROUP: Write Only Permission\n");
    break;
    case S_IXGRP:
        fprintf(stdout,"-> GROUP: Execute Only Permission\n");
    break;
    case S_IRWG:
        fprintf(stdout,"-> GROUP: Read and Write Only Permission\n");
    break;
    case S_IRXG:
        fprintf(stdout,"-> GROUP: Read and Execute Only Permission\n");
    break;
    case S_IWXG:
        fprintf(stdout,"-> GROUP: Write and Execute Onlye Permission\n");
    break;}

/* Others Permission Handler  */
long OTHER = (Status.st_mode & 000007);
switch(OTHER){
    case S_IRWXO:
        fprintf(stdout,"-> OTHER: Read, Write and Execute Permission\n");
    break;
    case S_IROTH:
        fprintf(stdout,"-> OTHER: Read Only Permission\n");
    break;
    case S_IWOTH:
        fprintf(stdout,"-> OTHER: Write Only Permission\n");
    break;
    case S_IXOTH:
        fprintf(stdout,"-> OTHER: Execute Only Permission\n");
    break;
    case S_IRWO:
        fprintf(stdout,"-> OTHER: Read and Write Only Permission\n");
    break;
    case S_IRXO:
        fprintf(stdout,"-> OTHER: Read and Execute Only Permission\n");
    break;
    case S_IWXO:
        fprintf(stdout,"-> OTHER: Write and Execute Onlye Permission\n");
    break;}

fprintf(stdout,"NUM Of Link       :  %ld         \n", (long)      Status.st_nlink);
fprintf(stdout,"User ID           :  %ld         \n", (long)      Status.st_uid);
fprintf(stdout,"Group ID          :  %ld         \n", (long)      Status.st_gid);
fprintf(stdout,"Device ID         :  %ld         \n", (long)      Status.st_rdev);
fprintf(stdout,"File Size         :  %lld Byte(s)\n", (long long) Status.st_size);
fprintf(stdout,"Block Size        :  %ld  Byte(s)\n", (long)      Status.st_blksize);
fprintf(stdout,"NUM Of Block(s)   :  %lld\n", (long long) Status.st_blocks);
fprintf(stdout,"Access Time       :  %s          \n",             ctime(&Status.st_atime));
fprintf(stdout,"Modification Time :  %s          \n",             ctime(&Status.st_mtime));
fprintf(stdout,"Change Time       :  %s          \n",             ctime(&Status.st_ctime));

return 0;}/* END MAIN*/
