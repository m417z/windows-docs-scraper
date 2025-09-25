typedef struct DXGI_OUTPUT_DESC1 {
  WCHAR                 DeviceName[32];
  RECT                  DesktopCoordinates;
  BOOL                  AttachedToDesktop;
  DXGI_MODE_ROTATION    Rotation;
  HMONITOR              Monitor;
  UINT                  BitsPerColor;
  DXGI_COLOR_SPACE_TYPE ColorSpace;
  FLOAT                 RedPrimary[2];
  FLOAT                 GreenPrimary[2];
  FLOAT                 BluePrimary[2];
  FLOAT                 WhitePoint[2];
  FLOAT                 MinLuminance;
  FLOAT                 MaxLuminance;
  FLOAT                 MaxFullFrameLuminance;
} DXGI_OUTPUT_DESC1;