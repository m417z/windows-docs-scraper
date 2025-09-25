typedef struct _D3DDDIARG_CREATEVIDEOPROCESSDEVICE {
  [in]     const GUID        *pVideoProcGuid;
  [in]     DXVADDI_VIDEODESC VideoDesc;
  [in]     D3DDDIFORMAT      RenderTargetFormat;
  [in]     UINT              MaxSubStreams;
  [in/out] HANDLE            hVideoProcess;
} D3DDDIARG_CREATEVIDEOPROCESSDEVICE;