int main(int argc, char ** argv)

{

char buf[10] = "";

fd_set rdfds;//

struct timeval tv; //store timeout

int ret; // return val

FD_ZERO(&rdfds); //clear rdfds

FD_SET(1, &rdfds); //add stdin handle into rdfds

tv.tv_sec = 3;

tv.tv_usec = 500;

ret = select(1 + 1, &rdfds, NULL, NULL, &tv);

if(ret < 0)

perror("\nselect");

else if(ret == 0)

printf("\ntimeout");

else

{

printf("\nret=%d", ret);

}

if(FD_ISSET(1, &rdfds))

{

printf("\nreading");

fread(buf, 9, 1, stdin); // read form stdin

}

// read(0, buf, 9); /* read from stdin */

// fprintf(stdout, "%s\n", buf); /* write to stdout */

write(1, buf, strlen(buf)); //write to stdout

printf("\n%d\n", strlen(buf));

return 0;

} 
