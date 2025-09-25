## Description

Specifies the type of a per-service state directory.

## Constants

### `ServiceDirectoryPersistentState:0`

Mutable, persistent service state. This state is both readable and writable by the service, and is inaccessible outside of the service. This state persists across reboots and OS updates.

### `ServiceDirectoryTypeMax:1`

Reserved. Represents the maximum value of the enumeration.

## Remarks

All per-service state directory types have a lifetime that is scoped to the lifetime of the service installation.
Once the service is removed by calling [DeleteService](https://learn.microsoft.com/windows/win32/api/winsvc/nf-winsvc-deleteservice) the state directories are deleted too.

## See also

[GetServiceDirectory](https://learn.microsoft.com/windows/win32/api/winsvc/nf-winsvc-getservicedirectory)