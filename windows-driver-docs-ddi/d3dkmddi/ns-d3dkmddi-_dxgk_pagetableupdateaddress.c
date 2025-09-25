typedef struct _DXGK_PAGETABLEUPDATEADDRESS {
  union {
    PVOID                   CpuVirtual;
    D3DGPU_PHYSICAL_ADDRESS GpuPhysical;
    D3DGPU_VIRTUAL_ADDRESS  GpuVirtual;
  };
} DXGK_PAGETABLEUPDATEADDRESS;