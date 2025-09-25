typedef struct _D3DKMT_VAD_DESC {
  UINT                  VadIndex;
  D3DKMT_ALIGN64 UINT64 VadAddress;
  UINT                  NumMappedRanges;
  UINT                  VadType;
  D3DKMT_ALIGN64 UINT64 StartAddress;
  D3DKMT_ALIGN64 UINT64 EndAddress;
} D3DKMT_VAD_DESC;