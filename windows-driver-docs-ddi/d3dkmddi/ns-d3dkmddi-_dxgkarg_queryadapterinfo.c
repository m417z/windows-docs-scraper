typedef struct _DXGKARG_QUERYADAPTERINFO {
  [in]  DXGK_QUERYADAPTERINFOTYPE  Type;
  [in]  VOID                       *pInputData;
  [in]  UINT                       InputDataSize;
  [out] VOID                       *pOutputData;
  [in]  UINT                       OutputDataSize;
  [in]  DXGK_QUERYADAPTERINFOFLAGS Flags;
  [in]  HANDLE                     hKmdProcessHandle;
} DXGKARG_QUERYADAPTERINFO;