struct IDxcBlobEncoding : IDxcBlob {
  HRESULT GetEncoding(
    BOOL   *pKnown,
    UINT32 *pCodePage
  );
};