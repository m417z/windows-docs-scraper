typedef struct _DXGK_BACKLIGHT_INFO {
  [out] OUT USHORT                        BacklightUsersetting;
  [out] OUT USHORT                        BacklightEffective;
  [out] OUT D3DDDI_GAMMA_RAMP_RGB256x3x16 GammaRamp;
} DXGK_BACKLIGHT_INFO;