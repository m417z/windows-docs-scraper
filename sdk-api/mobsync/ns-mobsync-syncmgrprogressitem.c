typedef struct _tagSYNCMGRPROGRESSITEM {
  DWORD   cbSize;
  UINT    mask;
  LPCWSTR lpcStatusText;
  DWORD   dwStatusType;
  int     iProgValue;
  int     iMaxValue;
} SYNCMGRPROGRESSITEM, *LPSYNCMGRPROGRESSITEM;