typedef struct tagEMRGLSRECORD {
  EMR   emr;
  DWORD cbData;
  BYTE  Data[1];
} EMRGLSRECORD, *PEMRGLSRECORD;