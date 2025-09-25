typedef struct _DXGKARG_CONNECTDOORBELL {
  HANDLE                        hDoorbell;
  DXGKARG_CONNECTDOORBELL_FLAGS Flags;
  void                          *KernelCpuVirtualAddress;
  void                          *SecondaryKernelCpuVirtualAddress;
  D3DDDI_DOORBELLSTATUS         Status;
} DXGKARG_CONNECTDOORBELL;