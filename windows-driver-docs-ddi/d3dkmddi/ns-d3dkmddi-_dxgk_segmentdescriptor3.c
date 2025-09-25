typedef struct _DXGK_SEGMENTDESCRIPTOR3 {
  [out] DXGK_SEGMENTFLAGS Flags;
  [out] PHYSICAL_ADDRESS  BaseAddress;
  [out] PHYSICAL_ADDRESS  CpuTranslatedAddress;
  [out] SIZE_T            Size;
  [out] UINT              NbOfBanks;
  [out] SIZE_T            *pBankRangeTable;
  [out] SIZE_T            CommitLimit;
        SIZE_T            SystemMemoryEndAddress;
        SIZE_T            Reserved;
} DXGK_SEGMENTDESCRIPTOR3;