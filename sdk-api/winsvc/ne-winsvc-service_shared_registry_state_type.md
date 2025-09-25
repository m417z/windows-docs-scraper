## Description

Specifies a state type for a shared service registry key.

## Constants

### `ServiceSharedRegistryPersistentState:0`

Mutable, persistent service state. This state is readable and writeable by the service and by local administrators. This state persists across reboots and OS updates.

## Remarks

All per-service registry state types have a lifetime that is scoped to the lifetime of the service installation.
Once the service is removed by calling [DeleteService](https://learn.microsoft.com/windows/win32/api/winsvc/nf-winsvc-deleteservice) the registry state is deleted too.

## See also

[GetSharedServiceRegistryStateKey](https://learn.microsoft.com/windows/win32/api/winsvc/nf-winsvc-getsharedserviceregistrystatekey)