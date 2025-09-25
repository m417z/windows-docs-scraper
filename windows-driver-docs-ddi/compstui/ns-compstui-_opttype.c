typedef struct _OPTTYPE {
  WORD      cbSize;
  BYTE      Type;
  BYTE      Flags;
  WORD      Count;
  WORD      BegCtrlID;
  POPTPARAM pOptParam;
  WORD      Style;
  WORD      wReserved[3];
  ULONG_PTR dwReserved[3];
} OPTTYPE, *POPTTYPE;