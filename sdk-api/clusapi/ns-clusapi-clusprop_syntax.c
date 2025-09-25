typedef union CLUSPROP_SYNTAX {
  DWORD  dw;
  struct {
    WORD wFormat;
    WORD wType;
  } DUMMYSTRUCTNAME;
} CLUSPROP_SYNTAX, *PCLUSPROP_SYNTAX;