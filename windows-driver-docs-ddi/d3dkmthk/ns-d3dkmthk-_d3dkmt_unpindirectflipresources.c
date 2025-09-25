typedef struct _D3DKMT_UNPINDIRECTFLIPRESOURCES {
  [in] D3DKMT_HANDLE hDevice;
  [in] UINT          ResourceCount;
  [in] D3DKMT_HANDLE *pResourceList;
} D3DKMT_UNPINDIRECTFLIPRESOURCES;