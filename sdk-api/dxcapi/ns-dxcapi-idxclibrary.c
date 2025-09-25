struct IDxcLibrary : IUnknown {
  HRESULT SetMalloc(
    IMalloc *pMalloc
  );
  HRESULT CreateBlobFromBlob(
    IDxcBlob *pBlob,
    UINT32   offset,
    UINT32   length,
    IDxcBlob **ppResult
  );
  HRESULT CreateBlobFromFile(
    LPCWSTR          pFileName,
    UINT32           *codePage,
    IDxcBlobEncoding **pBlobEncoding
  );
  HRESULT CreateBlobWithEncodingFromPinned(
    LPCVOID          pText,
    UINT32           size,
    UINT32           codePage,
    IDxcBlobEncoding **pBlobEncoding
  );
  HRESULT CreateBlobWithEncodingOnHeapCopy(
    LPCVOID          pText,
    UINT32           size,
    UINT32           codePage,
    IDxcBlobEncoding **pBlobEncoding
  );
  HRESULT CreateBlobWithEncodingOnMalloc(
    LPCVOID          pText,
    IMalloc          *pIMalloc,
    UINT32           size,
    UINT32           codePage,
    IDxcBlobEncoding **pBlobEncoding
  );
  HRESULT CreateIncludeHandler(
    IDxcIncludeHandler **ppResult
  );
  HRESULT CreateStreamFromBlobReadOnly(
    IDxcBlob *pBlob,
    IStream  **ppStream
  );
  HRESULT GetBlobAsUtf8(
    IDxcBlob         *pBlob,
    IDxcBlobEncoding **pBlobEncoding
  );
  HRESULT GetBlobAsWide(
    IDxcBlob         *pBlob,
    IDxcBlobEncoding **pBlobEncoding
  );
  HRESULT GetBlobAsUtf16(
    IDxcBlob         *pBlob,
    IDxcBlobEncoding **pBlobEncoding
  );
};