typedef struct _INSERTPSUIPAGE_INFO {
  WORD      cbSize;
  BYTE      Type;
  BYTE      Mode;
  ULONG_PTR dwData1;
  ULONG_PTR dwData2;
  ULONG_PTR dwData3;
} INSERTPSUIPAGE_INFO, *PINSERTPSUIPAGE_INFO;