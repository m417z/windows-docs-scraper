typedef struct tagEMRCREATEMONOBRUSH {
  EMR   emr;
  DWORD ihBrush;
  DWORD iUsage;
  DWORD offBmi;
  DWORD cbBmi;
  DWORD offBits;
  DWORD cbBits;
} EMRCREATEMONOBRUSH, *PEMRCREATEMONOBRUSH;