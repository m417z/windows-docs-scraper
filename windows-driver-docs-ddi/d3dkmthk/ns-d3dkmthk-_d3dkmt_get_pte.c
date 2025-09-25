typedef struct _D3DKMT_GET_PTE {
  UINT     PhysicalAdapterIndex;
  UINT     PageTableLevel;
  UINT     PageTableIndex[DXGK_MAX_PAGE_TABLE_LEVEL_COUNT];
  BOOLEAN  b64KBPte;
  UINT     NumPtes;
  DXGK_PTE Pte[D3DKMT_GET_PTE_MAX];
  UINT     NumValidEntries;
} D3DKMT_GET_PTE;