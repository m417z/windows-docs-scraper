typedef struct _DXVADDI_QUERYPROCAMPINPUT {
  [in] const GUID        *pVideoProcGuid;
  [in] DXVADDI_VIDEODESC VideoDesc;
  [in] D3DDDIFORMAT      RenderTargetFormat;
  [in] UINT              ProcAmpCap;
} DXVADDI_QUERYPROCAMPINPUT;