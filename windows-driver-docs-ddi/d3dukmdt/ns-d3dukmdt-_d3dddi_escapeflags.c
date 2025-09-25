typedef struct _D3DDDI_ESCAPEFLAGS {
  union {
    struct {
      UINT HardwareAccess : 1;
      UINT DeviceStatusQuery : 1;
      UINT ChangeFrameLatency : 1;
      UINT NoAdapterSynchronization : 1;
#if ...
      UINT Reserved : 1;
      UINT VirtualMachineData : 1;
      UINT DriverKnownEscape : 1;
      UINT DriverCommonEscape : 1;
#if ...
      UINT Reserved2 : 24;
#else
      UINT Reserved2 : 26;
#endif
#elif
      UINT Reserved : 28;
#elif
      UINT Reserved : 29;
#else
      UINT Reserved : 31;
#endif
    };
    UINT Value;
  };
} D3DDDI_ESCAPEFLAGS;