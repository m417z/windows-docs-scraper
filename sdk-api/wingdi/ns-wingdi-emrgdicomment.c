typedef struct tagEMRGDICOMMENT {
  EMR   emr;
  DWORD cbData;
  BYTE  Data[1];
} EMRGDICOMMENT, *PEMRGDICOMMENT;