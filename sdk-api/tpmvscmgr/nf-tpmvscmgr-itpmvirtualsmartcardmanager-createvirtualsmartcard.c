HRESULT CreateVirtualSmartCard(
  [in]           LPCWSTR                                   pszFriendlyName,
  [in]           BYTE                                      bAdminAlgId,
  [in]           const BYTE                                *pbAdminKey,
  [in]           DWORD                                     cbAdminKey,
  [in, optional] const BYTE                                *pbAdminKcv,
  [in]           DWORD                                     cbAdminKcv,
  [in, optional] const BYTE                                *pbPuk,
  [in]           DWORD                                     cbPuk,
  [in]           const BYTE                                *pbPin,
  [in]           DWORD                                     cbPin,
  [in]           BOOL                                      fGenerate,
  [in, optional] ITpmVirtualSmartCardManagerStatusCallback *pStatusCallback,
  [out]          LPWSTR                                    *ppszInstanceId,
  [out]          BOOL                                      *pfNeedReboot
);