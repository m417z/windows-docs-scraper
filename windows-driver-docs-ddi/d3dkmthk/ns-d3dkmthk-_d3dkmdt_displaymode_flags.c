typedef struct _D3DKMDT_DISPLAYMODE_FLAGS {
#if ...
       BOOLEAN                     ValidatedAgainstMonitorCaps : 1;
#if ...
       BOOLEAN                     RoundedFakeMode : 1;
#if ...
  [in] D3DKMDT_MODE_PRUNING_REASON ModePruningReason : 4;
#if ...
       UINT                        Reserved : 28;
#else
       UINT                        ValidatedAgainstMonitorCaps : 1;
#endif
#else
       UINT                        RoundedFakeMode : 1;
#endif
#else
  [in] D3DKMDT_MODE_PRUNING_REASON ModePruningReason : 4;
#endif
  [in] UINT                        Stereo : 1;
  [in] UINT                        AdvancedScanCapable : 1;
#elif
       UINT                        Reserved : 26;
       UINT                        PreferredTiming : 1;
       UINT                        PhysicalModeSupported : 1;
#elif
       UINT                        Reserved : 24;
       UINT                        VirtualRefreshRate : 1;
#else
       UINT                        Reserved : 23;
#endif
} D3DKMDT_DISPLAYMODE_FLAGS;