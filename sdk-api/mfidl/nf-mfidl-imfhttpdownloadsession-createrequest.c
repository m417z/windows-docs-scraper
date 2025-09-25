HRESULT CreateRequest(
  [in]           LPCWSTR                szObjectName,
  [in]           BOOL                   fBypassProxyCache,
  [in]           BOOL                   fSecure,
  [in, optional] LPCWSTR                szVerb,
  [in, optional] LPCWSTR                szReferrer,
                 IMFHttpDownloadRequest **ppRequest
);