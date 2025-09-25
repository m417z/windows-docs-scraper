typedef struct _DXGK_BUILDPAGINGBUFFER_UPDATEPAGETABLE {
  UINT                        PageTableLevel;
  HANDLE                      hAllocation;
  DXGK_PAGETABLEUPDATEADDRESS PageTableAddress;
  DXGK_PTE                    *pPageTableEntries;
  UINT                        StartIndex;
  UINT                        NumPageTableEntries;
  UINT                        Reserved0;
  DXGK_UPDATEPAGETABLEFLAGS   Flags;
  UINT64                      DriverProtection;
  UINT64                      AllocationOffsetInBytes;
  HANDLE                      hProcess;
  DXGK_PAGETABLEUPDATEMODE    UpdateMode;
  DXGK_PTE                    *pPageTableEntries64KB;
  D3DGPU_VIRTUAL_ADDRESS      FirstPteVirtualAddress;
} DXGK_BUILDPAGINGBUFFER_UPDATEPAGETABLE;