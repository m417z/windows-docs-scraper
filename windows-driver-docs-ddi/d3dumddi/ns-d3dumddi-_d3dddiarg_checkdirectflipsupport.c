typedef struct _D3DDDIARG_CHECKDIRECTFLIPSUPPORT {
  [in]  HANDLE hAppSwapchainResource;
  [in]  HANDLE hDWMSwapchainResource;
  [in]  UINT   CheckDirectFlipFlags;
  [out] BOOL   Supported;
} D3DDDIARG_CHECKDIRECTFLIPSUPPORT;