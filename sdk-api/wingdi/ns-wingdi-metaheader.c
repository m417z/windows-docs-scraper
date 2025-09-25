typedef struct tagMETAHEADER {
  WORD  mtType;
  WORD  mtHeaderSize;
  WORD  mtVersion;
  DWORD mtSize;
  WORD  mtNoObjects;
  DWORD mtMaxRecord;
  WORD  mtNoParameters;
} METAHEADER, *PMETAHEADER, *LPMETAHEADER;