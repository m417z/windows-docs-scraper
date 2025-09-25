HRESULT RequestAccessForAppWithAuditingInfoForWindowAsync(
  [in]                   HWND     appWindow,
  [in]                   HSTRING  sourceIdentity,
  [in]                   HSTRING  appPackageFamilyName,
  [in]                   IUnknown *auditInfoUnk,
  [iid_is] [out, retval] REFIID   riid,
  [out]                  void     **asyncOperation
);