## Description

Specifies the type of a per-service shared state directory.

## Constants

### `ServiceSharedDirectoryPersistentState:0`

Mutable, persistent service state. This state is both readable and writeable by the service and by local administrators. This state persists across reboots and OS updates.

## Remarks

All per-service state directory types have a lifetime that is scoped to the lifetime of the service installation.
Once the service is removed by calling [DeleteService](https://learn.microsoft.com/windows/win32/api/winsvc/nf-winsvc-deleteservice) the state directories are deleted too.

## See also

[GetSharedServiceDirectory](https://learn.microsoft.com/windows/win32/api/winsvc/nf-winsvc-getsharedservicedirectory)