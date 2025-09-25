typedef struct tagINTERFACEINFO {
  IUnknown *pUnk;
  IID      iid;
  WORD     wMethod;
} INTERFACEINFO, *LPINTERFACEINFO;