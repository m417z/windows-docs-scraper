typedef struct tagPROPSPEC {
  ULONG ulKind;
  union {
    PROPID   propid;
    LPOLESTR lpwstr;
  } DUMMYUNIONNAME;
} PROPSPEC;