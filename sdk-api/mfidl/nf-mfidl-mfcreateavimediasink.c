HRESULT MFCreateAVIMediaSink(
  [in]           IMFByteStream *pIByteStream,
  [in]           IMFMediaType  *pVideoMediaType,
  [in, optional] IMFMediaType  *pAudioMediaType,
  [out]          IMFMediaSink  **ppIMediaSink
);