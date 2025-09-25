HRESULT MFCreateMuxSink(
  [in]  GUID          guidOutputSubType,
  [in]  IMFAttributes *pOutputAttributes,
  [in]  IMFByteStream *pOutputByteStream,
  [out] IMFMediaSink  **ppMuxSink
);