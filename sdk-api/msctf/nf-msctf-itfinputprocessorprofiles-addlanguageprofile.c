HRESULT AddLanguageProfile(
  [in] REFCLSID    rclsid,
  [in] LANGID      langid,
  [in] REFGUID     guidProfile,
  [in] const WCHAR *pchDesc,
  [in] ULONG       cchDesc,
  [in] const WCHAR *pchIconFile,
  [in] ULONG       cchFile,
  [in] ULONG       uIconIndex
);