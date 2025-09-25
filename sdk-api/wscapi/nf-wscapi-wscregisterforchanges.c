HRESULT WscRegisterForChanges(
  [in]  LPVOID                 Reserved,
  [out] PHANDLE                phCallbackRegistration,
  [in]  LPTHREAD_START_ROUTINE lpCallbackAddress,
  [in]  PVOID                  pContext
);