HRESULT MFCreateVideoMediaTypeFromVideoInfoHeader2(
  const KS_VIDEOINFOHEADER2 *pVideoInfoHeader,
  DWORD                     cbVideoInfoHeader,
  QWORD                     AdditionalVideoFlags,
  const GUID                *pSubtype,
  IMFVideoMediaType         **ppIVideoMediaType
);