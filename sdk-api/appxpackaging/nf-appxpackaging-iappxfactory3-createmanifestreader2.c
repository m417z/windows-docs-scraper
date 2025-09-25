HRESULT CreateManifestReader2(
  [in]          IStream             *inputStream,
  [in,optional] LPCWSTR             expectedDigest,
  [out]         IAppxManifestReader **manifestReader
);