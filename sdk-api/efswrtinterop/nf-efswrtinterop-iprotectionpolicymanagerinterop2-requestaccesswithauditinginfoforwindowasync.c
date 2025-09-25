HRESULT RequestAccessWithAuditingInfoForWindowAsync(
  [in] [in]              HWND     appWindow,
  [in] [in]              HSTRING  sourceIdentity,
  [in] [in]              HSTRING  targetIdentity,
  [in]                   IUnknown *auditInfoUnk,
  [iid_is] [out, retval] REFIID   riid,
                         void     **asyncOperation
);