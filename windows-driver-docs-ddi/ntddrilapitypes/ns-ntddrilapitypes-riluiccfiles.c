typedef struct RILUICCFILES {
  DWORD           cbSize;
  DWORD           dwNumFiles;
  RILUICCFILEPATH filePath[1];
} RILUICCFILES, *LPRILUICCFILES;