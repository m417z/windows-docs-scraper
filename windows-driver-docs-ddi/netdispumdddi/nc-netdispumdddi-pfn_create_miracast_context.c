PFN_CREATE_MIRACAST_CONTEXT PfnCreateMiracastContext;

NTSTATUS PfnCreateMiracastContext(
  [in]  HANDLE hMiracastDeviceHandle,
  [in]  MIRACAST_CALLBACKS *pMiracastCallbacks,
  [out] PVOID *ppMiracastContext
)
{...}