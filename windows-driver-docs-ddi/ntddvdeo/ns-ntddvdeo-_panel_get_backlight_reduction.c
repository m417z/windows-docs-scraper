typedef struct _PANEL_GET_BACKLIGHT_REDUCTION {
  USHORT                         BacklightUsersetting;
  USHORT                         BacklightEffective;
  BACKLIGHT_REDUCTION_GAMMA_RAMP GammaRamp;
} PANEL_GET_BACKLIGHT_REDUCTION, *PPANEL_GET_BACKLIGHT_REDUCTION;