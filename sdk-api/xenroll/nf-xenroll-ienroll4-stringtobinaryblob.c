HRESULT stringToBinaryBlob(
  [in]  LONG             Flags,
  [in]  LPCWSTR          pwszString,
  [out] PCRYPT_DATA_BLOB pblobBinary,
  [out] LONG             *pdwSkip,
  [out] LONG             *pdwFlags
);