typedef struct tagVARDESC {
  MEMBERID memid;
  LPOLESTR lpstrSchema;
  union {
    ULONG   oInst;
    VARIANT *lpvarValue;
  } DUMMYUNIONNAME;
  ELEMDESC elemdescVar;
  WORD     wVarFlags;
  VARKIND  varkind;
} VARDESC, *LPVARDESC;