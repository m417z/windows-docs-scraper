DWORD WlanGetInterfaceCapability(
  [in]  HANDLE                     hClientHandle,
  [in]  const GUID                 *pInterfaceGuid,
        PVOID                      pReserved,
  [out] PWLAN_INTERFACE_CAPABILITY *ppCapability
);