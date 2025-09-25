typedef struct tagRPC_EE_INFO_PARAM {
  ExtendedErrorParamTypes ParameterType;
  union {
    LPSTR       AnsiString;
    LPWSTR      UnicodeString;
    long        LVal;
    short       SVal;
    ULONGLONG   PVal;
    BinaryParam BVal;
  } u;
} RPC_EE_INFO_PARAM;