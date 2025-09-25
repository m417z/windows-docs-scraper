typedef struct _PEP_COMPONENT_PLATFORM_CONSTRAINTS {
  [in] PEPHANDLE DeviceHandle;
  [in] ULONG     Component;
  [in] PULONG    MinimumFStates;
  [in] ULONG     PlatformStateCount;
} PEP_COMPONENT_PLATFORM_CONSTRAINTS, *PPEP_COMPONENT_PLATFORM_CONSTRAINTS;