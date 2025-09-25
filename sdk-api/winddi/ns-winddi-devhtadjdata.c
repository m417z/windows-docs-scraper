typedef struct _DEVHTADJDATA {
  DWORD      DeviceFlags;
  DWORD      DeviceXDPI;
  DWORD      DeviceYDPI;
  PDEVHTINFO pDefHTInfo;
  PDEVHTINFO pAdjHTInfo;
} DEVHTADJDATA, *PDEVHTADJDATA;