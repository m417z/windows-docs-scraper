HRESULT CoMarshalInterface(
  [in]           LPSTREAM  pStm,
  [in]           REFIID    riid,
  [in]           LPUNKNOWN pUnk,
  [in]           DWORD     dwDestContext,
  [in, optional] LPVOID    pvDestContext,
  [in]           DWORD     mshlflags
);