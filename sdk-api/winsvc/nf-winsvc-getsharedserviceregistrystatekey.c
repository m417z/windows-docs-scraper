DWORD GetSharedServiceRegistryStateKey(
  SC_HANDLE                          ServiceHandle,
  SERVICE_SHARED_REGISTRY_STATE_TYPE StateType,
  DWORD                              AccessMask,
  HKEY                               *ServiceStateKey
);