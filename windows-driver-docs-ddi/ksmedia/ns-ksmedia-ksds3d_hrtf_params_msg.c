typedef struct {
  ULONG Size;
  ULONG Enabled;
  BOOL  SwapChannels;
  BOOL  ZeroAzimuth;
  BOOL  CrossFadeOutput;
  ULONG FilterSize;
} KSDS3D_HRTF_PARAMS_MSG, *PKSDS3D_HRTF_PARAMS_MSG;