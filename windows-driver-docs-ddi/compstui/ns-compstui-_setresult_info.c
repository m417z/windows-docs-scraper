typedef struct _SETRESULT_INFO {
  WORD    cbSize;
  WORD    wReserved;
  HANDLE  hSetResult;
  LRESULT Result;
} SETRESULT_INFO, *PSETRESULT_INFO;