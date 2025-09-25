typedef struct _D3COLD_AUX_POWER_AND_TIMING_INTERFACE {
  USHORT                          Size;
  USHORT                          Version;
  PVOID                           Context;
  PINTERFACE_REFERENCE            InterfaceReference;
  PINTERFACE_DEREFERENCE          InterfaceDereference;
  PD3COLD_REQUEST_CORE_POWER_RAIL RequestCorePowerRail;
  PD3COLD_REQUEST_AUX_POWER       RequestAuxPower;
  PD3COLD_REQUEST_PERST_DELAY     RequestPerstDelay;
} D3COLD_AUX_POWER_AND_TIMING_INTERFACE, *PD3COLD_AUX_POWER_AND_TIMING_INTERFACE;