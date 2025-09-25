## Description

Specifies a state type for a service registry key.

## Constants

### `ServiceRegistryStateParameters:0`

Immutable service state, populated by INF to the Parameters subkey.

### `ServiceRegistryStatePersistent:1`

Mutable, persistent service state. This state is both readable and writable by the service, and is inaccessible outside of the service. This state persists across reboots and OS updates.

### `MaxServiceRegistryStateType:2`

Reserved. Represents the maximum value of the enumeration.

## Remarks

All per-service registry state types have a lifetime that is scoped to the lifetime of the service installation.
Once the service is removed by calling [DeleteService](https://learn.microsoft.com/windows/win32/api/winsvc/nf-winsvc-deleteservice) the registry state is deleted too.

## See also

[GetServiceRegistryStateKey](https://learn.microsoft.com/windows/win32/api/winsvc/nf-winsvc-getserviceregistrystatekey)