HRESULT RequestAccessWithMessageForWindowAsync(
  [in]                   HWND     appWindow,
  [in]                   HSTRING  sourceIdentity,
  [in]                   HSTRING  targetIdentity,
                         IUnknown *auditInfoUnk,
  [in]                   HSTRING  messageFromApp,
  [iid_is] [out, retval] REFIID   riid,
                         void     **asyncOperation
);