HRESULT RequestAccessForAppWithWindowAsync(
  [in]                   HWND    appWindow,
  [in]                   HSTRING sourceIdentity,
  [in]                   HSTRING appPackageFamilyName,
  [iid_is] [out, retval] REFIID  riid,
                         void    **asyncOperation
);