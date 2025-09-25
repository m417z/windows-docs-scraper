HRESULT CreateBlobWithEncodingOnMalloc(
  LPCVOID          pText,
  IMalloc          *pIMalloc,
  UINT32           size,
  UINT32           codePage,
  IDxcBlobEncoding **pBlobEncoding
);