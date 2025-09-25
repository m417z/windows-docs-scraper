HRESULT RegisterProfile(
  [in] REFCLSID    rclsid,
  [in] LANGID      langid,
  [in] REFGUID     guidProfile,
       const WCHAR *pchDesc,
  [in] ULONG       cchDesc,
       const WCHAR *pchIconFile,
  [in] ULONG       cchFile,
  [in] ULONG       uIconIndex,
  [in] HKL         hklsubstitute,
  [in] DWORD       dwPreferredLayout,
  [in] BOOL        bEnabledByDefault,
  [in] DWORD       dwFlags
);