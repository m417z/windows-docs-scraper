typedef struct tagFUNCDESC {
  MEMBERID   memid;
  SCODE      *lprgscode;
  ELEMDESC   *lprgelemdescParam;
  FUNCKIND   funckind;
  INVOKEKIND invkind;
  CALLCONV   callconv;
  SHORT      cParams;
  SHORT      cParamsOpt;
  SHORT      oVft;
  SHORT      cScodes;
  ELEMDESC   elemdescFunc;
  WORD       wFuncFlags;
} FUNCDESC, *LPFUNCDESC;