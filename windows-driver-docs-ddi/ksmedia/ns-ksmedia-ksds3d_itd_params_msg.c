typedef struct {
  ULONG             Enabled;
  KSDS3D_ITD_PARAMS LeftParams;
  KSDS3D_ITD_PARAMS RightParams;
  ULONG             Reserved;
} KSDS3D_ITD_PARAMS_MSG, *PKSDS3D_ITD_PARAMS_MSG;