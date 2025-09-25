typedef struct _DXVADDI_QUERYFILTERPROPERTYRANGEINPUT {
  [in] const GUID        *pVideoProcGuid;
  [in] DXVADDI_VIDEODESC VideoDesc;
  [in] D3DDDIFORMAT      RenderTargetFormat;
  [in] UINT              FilterSetting;
} DXVADDI_QUERYFILTERPROPERTYRANGEINPUT;