typedef struct _MFVideoInfo {
  DWORD                    dwWidth;
  DWORD                    dwHeight;
  MFRatio                  PixelAspectRatio;
  MFVideoChromaSubsampling SourceChromaSubsampling;
  MFVideoInterlaceMode     InterlaceMode;
  MFVideoTransferFunction  TransferFunction;
  MFVideoPrimaries         ColorPrimaries;
  MFVideoTransferMatrix    TransferMatrix;
  MFVideoLighting          SourceLighting;
  MFRatio                  FramesPerSecond;
  MFNominalRange           NominalRange;
  MFVideoArea              GeometricAperture;
  MFVideoArea              MinimumDisplayAperture;
  MFVideoArea              PanScanAperture;
  unsigned __int64         VideoFlags;
} MFVideoInfo;