typedef struct _TRANSDATA {
  BYTE  ubCodePageID;
  BYTE  ubType;
  union {
    SHORT sCode;
    BYTE  ubCode;
    BYTE  ubPairs[2];
  } uCode;
} TRANSDATA, *PTRANSDATA;