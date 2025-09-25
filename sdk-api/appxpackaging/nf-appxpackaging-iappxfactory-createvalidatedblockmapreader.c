HRESULT CreateValidatedBlockMapReader(
  [in]          IStream             *blockMapStream,
  [in]          LPCWSTR             signatureFileName,
  [out, retval] IAppxBlockMapReader **blockMapReader
);