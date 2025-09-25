HRESULT MFCreateFMPEG4MediaSink(
  [in]  IMFByteStream *pIByteStream,
  [in]  IMFMediaType  *pVideoMediaType,
  [in]  IMFMediaType  *pAudioMediaType,
  [out] IMFMediaSink  **ppIMediaSink
);