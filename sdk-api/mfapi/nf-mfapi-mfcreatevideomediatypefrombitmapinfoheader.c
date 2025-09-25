HRESULT MFCreateVideoMediaTypeFromBitMapInfoHeader(
  const BITMAPINFOHEADER *pbmihBitMapInfoHeader,
  DWORD                  dwPixelAspectRatioX,
  DWORD                  dwPixelAspectRatioY,
  MFVideoInterlaceMode   InterlaceMode,
  QWORD                  VideoFlags,
  QWORD                  qwFramesPerSecondNumerator,
  QWORD                  qwFramesPerSecondDenominator,
  DWORD                  dwMaxBitRate,
  IMFVideoMediaType      **ppIVideoMediaType
);