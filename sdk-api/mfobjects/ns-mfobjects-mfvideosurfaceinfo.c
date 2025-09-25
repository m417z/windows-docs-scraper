typedef struct _MFVideoSurfaceInfo {
  DWORD          Format;
  DWORD          PaletteEntries;
  MFPaletteEntry Palette[1];
} MFVideoSurfaceInfo;