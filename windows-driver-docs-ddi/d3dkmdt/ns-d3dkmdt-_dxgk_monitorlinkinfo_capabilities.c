typedef union _DXGK_MONITORLINKINFO_CAPABILITIES {
  struct {
    UINT Stereo : 1;
    UINT WideColorSpace : 1;
    UINT HighColorSpace : 1;
    UINT DynamicColorSpace : 1;
    UINT DynamicBitsPerColorChannel : 1;
    UINT DynamicColorEncodingFormat : 1;
    UINT DedicatedTimingGeneration : 1;
    UINT TargetIndependentPrimary : 1;
    UINT SyncLockIdentical : 1;
    UINT Hdr10Plus : 1;
    UINT DolbyVisionLowLatency : 1;
    UINT VariableRefresh : 1;
#if ...
    UINT Reserved : 20;
#elif
    UINT Reserved : 21;
#elif
    UINT Reserved : 22;
#elif
    UINT Reserved : 25;
#else
    UINT Reserved : 29;
#endif
  };
  UINT   Value;
} DXGK_MONITORLINKINFO_CAPABILITIES, *PDXGK_MONITORLINKINFO_CAPABILITIES;