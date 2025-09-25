DWORD NetworkIsolationGetEnterpriseIdAsync(
  [in]           LPCWSTR                    wszServerName,
  [in]           DWORD                      dwFlags,
  [in, optional] void                       *context,
  [in]           PNETISO_EDP_ID_CALLBACK_FN callback,
  [out]          HANDLE                     *hOperation
);