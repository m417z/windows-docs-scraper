typedef enum MFVideoAspectRatioMode {
  MFVideoARMode_None = 0,
  MFVideoARMode_PreservePicture = 0x1,
  MFVideoARMode_PreservePixel = 0x2,
  MFVideoARMode_NonLinearStretch = 0x4,
  MFVideoARMode_Mask = 0x7
} ;