typedef struct _DXGK_INTERRUPT_TABLE_ENTRY {
  UINT64 MessageAddress;
  UINT32 MessageData;
  UINT32 VectorControl;
} DXGK_INTERRUPT_TABLE_ENTRY;