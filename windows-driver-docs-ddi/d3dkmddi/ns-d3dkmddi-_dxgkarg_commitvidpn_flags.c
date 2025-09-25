typedef struct _DXGKARG_COMMITVIDPN_FLAGS {
  UINT PathPowerTransition : 1;
  UINT PathPoweredOff : 1;
  UINT Reserved : 30;
} DXGKARG_COMMITVIDPN_FLAGS;