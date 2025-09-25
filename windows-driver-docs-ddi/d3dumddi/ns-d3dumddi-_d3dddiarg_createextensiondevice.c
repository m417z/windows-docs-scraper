typedef struct _D3DDDIARG_CREATEEXTENSIONDEVICE {
  [in]  const GUID          *pGuid;
  [in]  DXVADDI_PRIVATEDATA *pPrivate;
  [out] HANDLE              hExtension;
} D3DDDIARG_CREATEEXTENSIONDEVICE;