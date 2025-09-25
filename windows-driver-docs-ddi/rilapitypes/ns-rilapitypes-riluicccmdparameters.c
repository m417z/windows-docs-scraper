typedef struct RILUICCCMDPARAMETERS {
  DWORD           cbSize;
  DWORD           dwParams;
  RILUICCFILEPATH filePath;
  DWORD           dwParameter1;
  DWORD           dwParameter2;
  DWORD           dwParameter3;
} RILUICCCMDPARAMETERS, *LPRILUICCCMDPARAMETERS;