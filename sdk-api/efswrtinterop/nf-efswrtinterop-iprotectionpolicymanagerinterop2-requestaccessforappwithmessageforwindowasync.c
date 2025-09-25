HRESULT RequestAccessForAppWithMessageForWindowAsync(
  [in]                   HWND     appWindow,
  [in]                   HSTRING  sourceIdentity,
  [in]                   HSTRING  appPackageFamilyName,
  [in]                   IUnknown *auditInfoUnk,
  [in]                   HSTRING  messageFromApp,
  [iid_is] [out, retval] REFIID   riid,
                         void     **asyncOperation
);