BOOL GopherGetAttributeA(
  [in]  HINTERNET                   hConnect,
  [in]  LPCSTR                      lpszLocator,
  [in]  LPCSTR                      lpszAttributeName,
  [out] LPBYTE                      lpBuffer,
  [in]  DWORD                       dwBufferLength,
  [out] LPDWORD                     lpdwCharactersReturned,
  [in]  GOPHER_ATTRIBUTE_ENUMERATOR lpfnEnumerator,
  [in]  DWORD_PTR                   dwContext
);