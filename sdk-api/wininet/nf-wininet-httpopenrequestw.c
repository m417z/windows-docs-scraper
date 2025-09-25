HINTERNET HttpOpenRequestW(
  [in] HINTERNET hConnect,
  [in] LPCWSTR   lpszVerb,
  [in] LPCWSTR   lpszObjectName,
  [in] LPCWSTR   lpszVersion,
  [in] LPCWSTR   lpszReferrer,
  [in] LPCWSTR   *lplpszAcceptTypes,
  [in] DWORD     dwFlags,
  [in] DWORD_PTR dwContext
);