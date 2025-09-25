typedef struct _D3DKMT_VA_RANGE_DESC {
  [in]  D3DKMT_ALIGN64 UINT64 VadAddress;
  [in]  UINT                  VaRangeIndex;
  [in]  UINT                  PhysicalAdapterIndex;
  [out] D3DKMT_ALIGN64 UINT64 StartAddress;
  [out] D3DKMT_ALIGN64 UINT64 EndAddress;
  [out] D3DKMT_ALIGN64 UINT64 DriverProtection;
  [out] UINT                  OwnerType;
  [out] D3DKMT_ALIGN64 UINT64 pOwner;
  [out] D3DKMT_ALIGN64 UINT64 OwnerOffset;
  [out] UINT                  Protection;
} D3DKMT_VA_RANGE_DESC;