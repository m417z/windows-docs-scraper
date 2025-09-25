typedef struct _DXGKARG_GPUP_WRITE_VIRTUALIZED_MSIX {
  UINT                       vfIndex;
  INT16                      InterruptTableIndex;
  DXGK_INTERRUPT_TABLE_ENTRY WriteValue;
} DXGKARG_GPUP_WRITE_VIRTUALIZED_MSIX;