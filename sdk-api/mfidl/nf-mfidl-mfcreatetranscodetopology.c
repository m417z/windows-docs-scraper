HRESULT MFCreateTranscodeTopology(
  [in]  IMFMediaSource      *pSrc,
  [in]  LPCWSTR             pwszOutputFilePath,
  [in]  IMFTranscodeProfile *pProfile,
  [out] IMFTopology         **ppTranscodeTopo
);