typedef struct _DXGK_SEGMENTDESCRIPTOR {
  [out] PHYSICAL_ADDRESS  BaseAddress;
  [out] PHYSICAL_ADDRESS  CpuTranslatedAddress;
  [out] SIZE_T            Size;
  [out] UINT              NbOfBanks;
  [out] SIZE_T            *pBankRangeTable;
  [out] SIZE_T            CommitLimit;
  [out] DXGK_SEGMENTFLAGS Flags;
} DXGK_SEGMENTDESCRIPTOR;