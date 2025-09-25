typedef struct _AV_PCR {
  union {
    OPCR  oPCR;
    IPCR  iPCR;
    ULONG ulongData;
  };
} AV_PCR, *PAV_PCR;