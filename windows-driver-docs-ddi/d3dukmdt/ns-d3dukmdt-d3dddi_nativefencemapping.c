typedef struct _D3DDDI_NATIVEFENCEMAPPING {
  VOID                                  *CurrentValueCpuVa;
  D3DKMT_ALIGN64 D3DGPU_VIRTUAL_ADDRESS CurrentValueGpuVa;
  D3DKMT_ALIGN64 D3DGPU_VIRTUAL_ADDRESS MonitoredValueGpuVa;
  D3DKMT_ALIGN64 BYTE                   Reserved[32];
} D3DDDI_NATIVEFENCEMAPPING;