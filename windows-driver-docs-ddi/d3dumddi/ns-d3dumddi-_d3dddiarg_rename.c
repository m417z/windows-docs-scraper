typedef struct _D3DDDIARG_RENAME {
  [in] HANDLE                 hResource;
  [in] UINT                   SubResourceIndex;
  [in] HANDLE                 hCookie;
       D3DGPU_VIRTUAL_ADDRESS GpuVirtualAddress;
} D3DDDIARG_RENAME;