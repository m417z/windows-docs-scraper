typedef struct DXGI_ADAPTER_DESC1 {
  WCHAR  Description[128];
  UINT   VendorId;
  UINT   DeviceId;
  UINT   SubSysId;
  UINT   Revision;
  SIZE_T DedicatedVideoMemory;
  SIZE_T DedicatedSystemMemory;
  SIZE_T SharedSystemMemory;
  LUID   AdapterLuid;
  UINT   Flags;
} DXGI_ADAPTER_DESC1;