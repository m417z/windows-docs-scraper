typedef struct _OPTPARAM {
  WORD      cbSize;
  BYTE      Flags;
  BYTE      Style;
  LPTSTR    pData;
  ULONG_PTR IconID;
  LPARAM    lParam;
  ULONG_PTR dwReserved[2];
} OPTPARAM, *POPTPARAM;