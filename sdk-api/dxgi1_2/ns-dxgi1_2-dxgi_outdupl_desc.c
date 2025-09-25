typedef struct DXGI_OUTDUPL_DESC {
  DXGI_MODE_DESC     ModeDesc;
  DXGI_MODE_ROTATION Rotation;
  BOOL               DesktopImageInSystemMemory;
} DXGI_OUTDUPL_DESC;