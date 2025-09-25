void NetDeviceStoreResetDiagnostics(
  [_In_]                                   WDFDEVICE   Device,
  [_In_]                                   SIZE_T      ResetDiagnosticsSize,
  [_In_reads_bytes_(ResetDiagnosticsSize)] const UINT8 *ResetDiagnosticsBuffer
);