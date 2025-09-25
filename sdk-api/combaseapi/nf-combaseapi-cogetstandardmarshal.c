HRESULT CoGetStandardMarshal(
  [in]           REFIID    riid,
  [in]           LPUNKNOWN pUnk,
  [in]           DWORD     dwDestContext,
  [in, optional] LPVOID    pvDestContext,
  [in]           DWORD     mshlflags,
  [out]          LPMARSHAL *ppMarshal
);