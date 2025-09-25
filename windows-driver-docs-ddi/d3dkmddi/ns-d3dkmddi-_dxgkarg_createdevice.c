typedef struct _DXGKARG_CREATEDEVICE {
  HANDLE hDevice;
  union {
    DXGK_CREATEDEVICEFLAGS Flags;
    DXGK_DEVICEINFO        *pInfo;
  };
  ULONG  Pasid;
  HANDLE hKmdProcess;
} DXGKARG_CREATEDEVICE;