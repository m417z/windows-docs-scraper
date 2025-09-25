HRESULT MFCreateVideoMediaTypeFromBitMapInfoHeaderEx(
  [in]  const BITMAPINFOHEADER *pbmihBitMapInfoHeader,
  [in]  UINT32                 cbBitMapInfoHeader,
        DWORD                  dwPixelAspectRatioX,
        DWORD                  dwPixelAspectRatioY,
        MFVideoInterlaceMode   InterlaceMode,
        QWORD                  VideoFlags,
        DWORD                  dwFramesPerSecondNumerator,
        DWORD                  dwFramesPerSecondDenominator,
        DWORD                  dwMaxBitRate,
  [out] IMFVideoMediaType      **ppIVideoMediaType
);