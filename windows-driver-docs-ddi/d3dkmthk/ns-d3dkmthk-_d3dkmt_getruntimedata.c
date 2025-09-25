typedef struct _D3DKMT_GETRUNTIMEDATA {
  [in]      D3DKMT_HANDLE hAdapter;
  [in]      D3DKMT_HANDLE hGlobalShare;
  [in, out] VOID          *pRuntimeData;
  [in]      UINT          RuntimeDataSize;
} D3DKMT_GETRUNTIMEDATA;