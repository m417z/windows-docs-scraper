HRESULT MFCreateSinkWriterFromURL(
  [in]  LPCWSTR       pwszOutputURL,
  [in]  IMFByteStream *pByteStream,
  [in]  IMFAttributes *pAttributes,
  [out] IMFSinkWriter **ppSinkWriter
);