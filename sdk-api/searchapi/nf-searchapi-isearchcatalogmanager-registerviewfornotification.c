HRESULT RegisterViewForNotification(
  [in]  LPCWSTR                pszView,
  [in]  ISearchViewChangedSink *pViewChangedSink,
  [out] DWORD                  *pdwCookie
);