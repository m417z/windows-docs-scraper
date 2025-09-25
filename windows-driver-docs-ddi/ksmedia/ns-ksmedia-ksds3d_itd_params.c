typedef struct {
  LONG  Channel;
  FLOAT VolSmoothScale;
  FLOAT TotalDryAttenuation;
  FLOAT TotalWetAttenuation;
  LONG  SmoothFrequency;
  LONG  Delay;
} KSDS3D_ITD_PARAMS, *PKSDS3D_ITD_PARAMS;