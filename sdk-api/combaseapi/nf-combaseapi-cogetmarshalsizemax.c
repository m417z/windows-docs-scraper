HRESULT CoGetMarshalSizeMax(
  [out]          ULONG     *pulSize,
  [in]           REFIID    riid,
  [in]           LPUNKNOWN pUnk,
  [in]           DWORD     dwDestContext,
  [in, optional] LPVOID    pvDestContext,
  [in]           DWORD     mshlflags
);