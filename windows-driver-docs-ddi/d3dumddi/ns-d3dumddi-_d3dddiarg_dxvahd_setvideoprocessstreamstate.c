typedef struct _D3DDDIARG_DXVAHD_SETVIDEOPROCESSSTREAMSTATE {
  [in] HANDLE                 hVideoProcessor;
  [in] UINT                   StreamNumber;
  [in] DXVAHDDDI_STREAM_STATE State;
  [in] UINT                   DataSize;
  [in] const VOID             *pData;
} D3DDDIARG_DXVAHD_SETVIDEOPROCESSSTREAMSTATE;