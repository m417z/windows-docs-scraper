typedef struct tagMETARECORD {
  DWORD rdSize;
  WORD  rdFunction;
  WORD  rdParm[1];
} METARECORD, *PMETARECORD, *LPMETARECORD;