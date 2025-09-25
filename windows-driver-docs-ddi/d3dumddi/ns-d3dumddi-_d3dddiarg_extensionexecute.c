typedef struct _D3DDDIARG_EXTENSIONEXECUTE {
  [in] HANDLE                hExtension;
  [in] UINT                  Function;
  [in] DXVADDI_PRIVATEDATA   *pPrivateInput;
  [in] DXVADDI_PRIVATEDATA   *pPrivateOutput;
  [in] UINT                  NumBuffers;
       DXVADDI_PRIVATEBUFFER *pBuffers;
} D3DDDIARG_EXTENSIONEXECUTE;