typedef struct _DXGKARG_SWITCHTOHWCONTEXTLIST {
  HANDLE hHwContextFirst;
  HANDLE hHwContextSecond;
  UINT   NodeOrdinal;
  UINT   EngineOrdinal;
} DXGKARG_SWITCHTOHWCONTEXTLIST;