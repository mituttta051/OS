//Create a struct File which represents a file with the fields (id:
//unique number assigned to each file, name: name of the file, size:
//current size of the file data, data: the actual textual content of
//the file as a string, directory: the directory of type struct
//Directory where the file is in). The structure supports the
//following operations on files:
//overwrite to file(struct File* file, const char* str) which
//overwrites the file content f ile with the new content str.
//append to file(struct File* file, const char* str) which
//appends the new content str to the end of the file f ile.
//printp file(struct File* file) prints to stdout the path of file file.

//Create a struct Directory which represents a directory with the
//fields (name: the directory name,files: array of files, directories:
//array of sub-directories, nf: number of files in the directory, nd:
//number of sub-directories in the current directory, path: the
//absolute path of this directory). It supports the following
//operations on directories:

struct Directory {
    char name[256];
    struct File* files;
	struct Directory* directories;
	int nf;
	int nd;
	char path[256];
};

struct File {
    int id;
    char name[256];
    int size;
    char data[256];




}