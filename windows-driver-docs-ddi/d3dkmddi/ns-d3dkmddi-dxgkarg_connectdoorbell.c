typedef struct _DXGKARG_CONNECTDOORBELL {
  HANDLE                        hHwQueue;
  DXGKARG_CONNECTDOORBELL_FLAGS Flags;
  PHYSICAL_ADDRESS              PhysicalAddress;
  PHYSICAL_ADDRESS              SecondaryPhysicalAddress;
  D3DDDI_DOORBELLSTATUS         Status;
} DXGKARG_CONNECTDOORBELL;