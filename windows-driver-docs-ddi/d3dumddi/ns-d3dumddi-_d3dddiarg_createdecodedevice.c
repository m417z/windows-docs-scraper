typedef struct _D3DDDIARG_CREATEDECODEDEVICE {
  [in]     const GUID                  *pGuid;
  [in]     DXVADDI_VIDEODESC           VideoDesc;
  [in]     DXVADDI_CONFIGPICTUREDECODE *pConfig;
  [in/out] HANDLE                      hDecode;
} D3DDDIARG_CREATEDECODEDEVICE;