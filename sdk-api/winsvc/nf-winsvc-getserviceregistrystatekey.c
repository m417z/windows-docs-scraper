DWORD GetServiceRegistryStateKey(
  SERVICE_STATUS_HANDLE       ServiceStatusHandle,
  SERVICE_REGISTRY_STATE_TYPE StateType,
  DWORD                       AccessMask,
  HKEY                        *ServiceStateKey
);