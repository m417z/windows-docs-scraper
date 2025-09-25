typedef struct _D3DKMT_TRIMPROCESSCOMMITMENT {
  ULONG                              cbSize;
  HANDLE                             hProcess;
  D3DKMT_TRIMPROCESSCOMMITMENT_FLAGS Flags;
  D3DKMT_ALIGN64 UINT64              DecommitRequested;
  D3DKMT_ALIGN64 UINT64              NumBytesDecommitted;
} D3DKMT_TRIMPROCESSCOMMITMENT;