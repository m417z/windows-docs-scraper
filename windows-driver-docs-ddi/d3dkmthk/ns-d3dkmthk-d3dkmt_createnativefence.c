typedef struct _D3DKMT_CREATENATIVEFENCE {
  D3DKMT_HANDLE                  hDevice;
  D3DKMT_HANDLE                  hSyncObject;
  BYTE                           PrivateDriverData[D3DDDI_NATIVE_FENCE_PDD_SIZE];
  D3DDDI_NATIVEFENCEINFO         Info;
  D3DKMT_CREATENATIVEFENCE_FLAGS Flags;
  BYTE                           Reserved[28];
} D3DKMT_CREATENATIVEFENCE;