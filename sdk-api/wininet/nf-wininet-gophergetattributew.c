BOOL GopherGetAttributeW(
  [in]  HINTERNET                   hConnect,
  [in]  LPCWSTR                     lpszLocator,
  [in]  LPCWSTR                     lpszAttributeName,
  [out] LPBYTE                      lpBuffer,
  [in]  DWORD                       dwBufferLength,
  [out] LPDWORD                     lpdwCharactersReturned,
  [in]  GOPHER_ATTRIBUTE_ENUMERATOR lpfnEnumerator,
  [in]  DWORD_PTR                   dwContext
);