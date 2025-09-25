typedef struct _PEP_DEVICE_PLATFORM_CONSTRAINTS {
  [in] PEPHANDLE           DeviceHandle;
  [in] PDEVICE_POWER_STATE MinimumDStates;
  [in] ULONG               PlatformStateCount;
} PEP_DEVICE_PLATFORM_CONSTRAINTS, *PPEP_DEVICE_PLATFORM_CONSTRAINTS;