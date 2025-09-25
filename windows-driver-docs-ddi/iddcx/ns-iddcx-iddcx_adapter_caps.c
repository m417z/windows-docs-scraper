struct IDDCX_ADAPTER_CAPS {
  UINT                           Size;
  IDDCX_ADAPTER_FLAGS            Flags;
  UINT64                         MaxDisplayPipelineRate;
  UINT                           MaxMonitorsSupported;
  IDDCX_ENDPOINT_DIAGNOSTIC_INFO EndPointDiagnostics;
  UINT                           StaticDesktopReencodeFrameCount;
};