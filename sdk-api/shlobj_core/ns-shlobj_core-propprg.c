typedef struct PROPPRG {
  WORD  flPrg;
  WORD  flPrgInit;
  CHAR  achTitle[PIFNAMESIZE];
  CHAR  achCmdLine[PIFSTARTLOCSIZE + PIFPARAMSSIZE + 1];
  CHAR  achWorkDir[PIFDEFPATHSIZE];
  WORD  wHotKey;
  CHAR  achIconFile[PIFDEFFILESIZE];
  WORD  wIconIndex;
  DWORD dwEnhModeFlags;
  DWORD dwRealModeFlags;
  CHAR  achOtherFile[PIFDEFFILESIZE];
  CHAR  achPIFFile[PIFMAXFILEPATH];
} PROPPRG;