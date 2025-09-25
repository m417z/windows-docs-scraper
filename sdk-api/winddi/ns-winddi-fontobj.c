typedef struct _FONTOBJ {
  ULONG     iUniq;
  ULONG     iFace;
  ULONG     cxMax;
  FLONG     flFontType;
  ULONG_PTR iTTUniq;
  ULONG_PTR iFile;
  SIZE      sizLogResPpi;
  ULONG     ulStyleSize;
  PVOID     pvConsumer;
  PVOID     pvProducer;
} FONTOBJ;