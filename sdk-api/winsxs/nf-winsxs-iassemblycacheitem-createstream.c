HRESULT CreateStream(
  [in]       DWORD          dwFlags,
  [in]       LPCWSTR        pszStreamName,
  [in]       DWORD          dwFormat,
  [in]       DWORD          dwFormatFlags,
             IStream        **ppIStream,
  [optional] ULARGE_INTEGER *puliMaxSize
);