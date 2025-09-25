void NET_DEVICE_RESET_CAPABILITIES_INIT(
  [_Out_] NET_DEVICE_RESET_CAPABILITIES            *ResetCapabilities,
  [_In_]  GUID                                     ResetDiagnosticsGuid,
  [_In_]  PFN_NET_DEVICE_COLLECT_RESET_DIAGNOSTICS EvtNetDeviceCollectResetDiagnostics
);