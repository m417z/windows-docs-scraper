typedef struct _D3DDDIARG_DXVAHD_SETVIDEOPROCESSBLTSTATE {
  [in] HANDLE              hVideoProcessor;
  [in] DXVAHDDDI_BLT_STATE State;
  [in] UINT                DataSize;
  [in] const VOID          *pData;
} D3DDDIARG_DXVAHD_SETVIDEOPROCESSBLTSTATE;