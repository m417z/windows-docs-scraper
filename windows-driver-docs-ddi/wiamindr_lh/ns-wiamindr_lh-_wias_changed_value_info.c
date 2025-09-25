typedef struct _WIAS_CHANGED_VALUE_INFO {
  BOOL  bChanged;
  LONG  vt;
  union {
    LONG  lVal;
    FLOAT fltVal;
    BSTR  bstrVal;
    GUID  guidVal;
  } Old;
  union {
    LONG  lVal;
    FLOAT fltVal;
    BSTR  bstrVal;
    GUID  guidVal;
  } Current;
} WIAS_CHANGED_VALUE_INFO, *PWIAS_CHANGED_VALUE_INFO;