typedef struct _DXVADDI_VIDEOPROCESSORINPUT {
  [in] const GUID        *pVideoProcGuid;
  [in] DXVADDI_VIDEODESC VideoDesc;
  [in] D3DDDIFORMAT      RenderTargetFormat;
} DXVADDI_VIDEOPROCESSORINPUT;