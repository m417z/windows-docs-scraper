typedef struct tagMETHODDATA {
  OLECHAR   *szName;
  PARAMDATA *ppdata;
  DISPID    dispid;
  UINT      iMeth;
  CALLCONV  cc;
  UINT      cArgs;
  WORD      wFlags;
  VARTYPE   vtReturn;
} METHODDATA, *LPMETHODDATA;