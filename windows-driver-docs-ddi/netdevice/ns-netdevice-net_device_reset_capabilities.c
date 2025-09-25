typedef struct _NET_DEVICE_RESET_CAPABILITIES {
  ULONG                                    Size;
  GUID                                     ResetDiagnosticsGuid;
  PFN_NET_DEVICE_COLLECT_RESET_DIAGNOSTICS EvtNetDeviceCollectResetDiagnostics;
} NET_DEVICE_RESET_CAPABILITIES;