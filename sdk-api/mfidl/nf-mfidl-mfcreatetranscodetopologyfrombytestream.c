HRESULT MFCreateTranscodeTopologyFromByteStream(
  [in]  IMFMediaSource      *pSrc,
  [in]  IMFByteStream       *pOutputStream,
  [in]  IMFTranscodeProfile *pProfile,
  [out] IMFTopology         **ppTranscodeTopo
);