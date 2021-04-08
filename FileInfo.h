#include"StudentStructure.h"
int  getRollNofile();
int getIndexFile();
int  getDataFile();
void setRollNofile(int);
int getNlines();
void setIndexFile();
int setDataFile(stud *s1, char *fileName );
int getDataFile(stud *s1,char *srch_key);
int deleteDateFile(stud *s1,char *del_key);
int deleteIndex(char *keyword);
int setBackUpIndexFile(char *del_key);
char** getAllIndices();