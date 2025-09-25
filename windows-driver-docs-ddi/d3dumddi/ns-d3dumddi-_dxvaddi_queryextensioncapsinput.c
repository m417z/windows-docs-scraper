typedef struct _DXVADDI_QUERYEXTENSIONCAPSINPUT {
  [in] const GUID          *pGuid;
  [in] UINT                CapType;
  [in] DXVADDI_PRIVATEDATA *pPrivate;
} DXVADDI_QUERYEXTENSIONCAPSINPUT;