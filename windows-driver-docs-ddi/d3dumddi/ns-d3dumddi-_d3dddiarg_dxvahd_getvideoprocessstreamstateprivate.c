typedef struct _D3DDDIARG_DXVAHD_GETVIDEOPROCESSSTREAMSTATEPRIVATE {
  [in]     HANDLE                              hVideoProcessor;
  [in]     UINT                                StreamNumber;
  [in/out] DXVAHDDDI_STREAM_STATE_PRIVATE_DATA *pData;
} D3DDDIARG_DXVAHD_GETVIDEOPROCESSSTREAMSTATEPRIVATE;