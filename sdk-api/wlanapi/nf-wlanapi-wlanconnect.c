DWORD WlanConnect(
  [in] HANDLE                            hClientHandle,
  [in] const GUID                        *pInterfaceGuid,
  [in] const PWLAN_CONNECTION_PARAMETERS pConnectionParameters,
       PVOID                             pReserved
);