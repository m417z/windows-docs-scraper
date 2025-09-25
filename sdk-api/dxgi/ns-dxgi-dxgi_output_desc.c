typedef struct DXGI_OUTPUT_DESC {
  WCHAR              DeviceName[32];
  RECT               DesktopCoordinates;
  BOOL               AttachedToDesktop;
  DXGI_MODE_ROTATION Rotation;
  HMONITOR           Monitor;
} DXGI_OUTPUT_DESC;