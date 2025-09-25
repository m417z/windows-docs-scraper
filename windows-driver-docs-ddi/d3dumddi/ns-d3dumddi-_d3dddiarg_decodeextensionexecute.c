typedef struct _D3DDDIARG_DECODEEXTENSIONEXECUTE {
  [in]  HANDLE                hDecode;
  [in]  UINT                  Function;
  [in]  DXVADDI_PRIVATEDATA   *pPrivateInput;
  [out] DXVADDI_PRIVATEDATA   *pPrivateOutput;
  [in]  UINT                  NumBuffers;
        DXVADDI_PRIVATEBUFFER *pBuffers;
} D3DDDIARG_DECODEEXTENSIONEXECUTE;