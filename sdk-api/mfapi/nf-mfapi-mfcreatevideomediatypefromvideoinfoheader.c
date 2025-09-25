HRESULT MFCreateVideoMediaTypeFromVideoInfoHeader(
  const KS_VIDEOINFOHEADER *pVideoInfoHeader,
  DWORD                    cbVideoInfoHeader,
  DWORD                    dwPixelAspectRatioX,
  DWORD                    dwPixelAspectRatioY,
  MFVideoInterlaceMode     InterlaceMode,
  QWORD                    VideoFlags,
  const GUID               *pSubtype,
  IMFVideoMediaType        **ppIVideoMediaType
);