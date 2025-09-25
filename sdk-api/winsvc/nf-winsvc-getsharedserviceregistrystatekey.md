## Description

Returns a handle for a registry key for a service and associated programs to read and/or write state to.

## Parameters

### `ServiceStatusHandle`

A handle to the service. This handle is returned by the [OpenService](https://learn.microsoft.com/windows/win32/api/winsvc/nf-winsvc-openservicea) function.

### `StateType`

A member of the [SERVICE_SHARED_REGISTRY_STATE_TYPE](https://learn.microsoft.com/windows/win32/api/winsvc/ne-winsvc-service_shared_registry_state_type) specifying the shared state type for which the service registry key is retrieved.

### `AccessMask`

The access mask with which to attempt to open the state key. For more information, see
[Registry Key Security and Access Rights](https://learn.microsoft.com/windows/desktop/SysInfo/registry-key-security-and-access-rights).

### `ServiceStateKey`

Receives the output registry key handle.

## Return value

ERROR_SUCCESS when all operations complete successfully; otherwise, a Win32 error code.

## Remarks

For **ServiceSharedRegistryStatePersistent**, the security of the directory is set to only provide write access to the local system account, the service SID, and local administrators. Ensure service SIDs are enabled for any service that calls this API. For more information, see [SERVICE_SID_INFO](https://learn.microsoft.com/windows/win32/api/winsvc/ns-winsvc-service_sid_info).

For a similar API that provides service state exclusively for use by the service itself, see [GetServiceRegistryStateKey](https://learn.microsoft.com/windows/win32/api/winsvc/nf-winsvc-getserviceregistrystatekey).

All service state registry keys are deleted by the service control manager once the service is uninstalled.

## See also

[OpenService](https://learn.microsoft.com/windows/win32/api/winsvc/nf-winsvc-openservicea)

[GetServiceRegistryStateKey](https://learn.microsoft.com/windows/win32/api/winsvc/nf-winsvc-getserviceregistrystatekey)

[SERVICE_SID_INFO](https://learn.microsoft.com/windows/win32/api/winsvc/ns-winsvc-service_sid_info)