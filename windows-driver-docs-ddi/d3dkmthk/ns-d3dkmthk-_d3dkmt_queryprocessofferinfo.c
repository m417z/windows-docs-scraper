typedef struct _D3DKMT_QUERYPROCESSOFFERINFO {
  ULONG                 cbSize;
  HANDLE                hProcess;
  D3DKMT_ALIGN64 UINT64 DecommitUniqueness;
  D3DKMT_ALIGN64 UINT64 DecommittableBytes;
} D3DKMT_QUERYPROCESSOFFERINFO;