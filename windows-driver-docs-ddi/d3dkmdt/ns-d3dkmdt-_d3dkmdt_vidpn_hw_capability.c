typedef struct _D3DKMDT_VIDPN_HW_CAPABILITY {
  UINT DriverRotation : 1;
  UINT DriverScaling : 1;
  UINT DriverCloning : 1;
  UINT DriverColorConvert : 1;
  UINT DriverLinkedAdapaterOutput : 1;
  UINT DriverRemoteDisplay : 1;
  UINT Reserved : 26;
} D3DKMDT_VIDPN_HW_CAPABILITY;