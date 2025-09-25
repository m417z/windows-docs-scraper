typedef enum _NPEM_CONTROL_STANDARD_CONTROL_BIT {
  InitiateReset,
  OkControl,
  LocateControl,
  FailControl,
  RebuildControl,
  PFAControl,
  HotSpareControl,
  InACriticalArrayControl,
  InAFailedArrayControl,
  InvalidDeviceTypeControl,
  DisabledControl
} NPEM_CONTROL_STANDARD_CONTROL_BIT, *PNPEM_CONTROL_STANDARD_CONTROL_BIT;