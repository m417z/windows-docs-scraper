HRESULT RequestAccessForWindowAsync(
  [in]                   HWND    appWindow,
  [in]                   HSTRING sourceIdentity,
  [in]                   HSTRING targetIdentity,
  [iid_is] [out, retval] REFIID  riid,
                         void    **asyncOperation
);