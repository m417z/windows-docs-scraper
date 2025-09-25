HRESULT DestroyVirtualSmartCard(
  [in]           LPCWSTR                                   pszInstanceId,
  [in, optional] ITpmVirtualSmartCardManagerStatusCallback *pStatusCallback,
  [out]          BOOL                                      *pfNeedReboot
);