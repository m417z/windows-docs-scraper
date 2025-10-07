# RtlGetSystemGlobalData function

\[This function may be changed or removed from Windows without further notice.\]

Gets the Shared User Data for a given DataId.

## Parameters

*DataId* `[in]`

Supplies an ID of the features being queried from the Shared User Data.

*Buffer* `[in][out]`

A buffer in which to store the data.

*Size* `[in]`

The size of the buffer.

## Return value

Returns an `NTSTATUS` value indicating success or failure of the function.

## Remarks

## Requirements

| Requirement | Value |
|----------------|-------------------------------------|
| DLL | Ntdll.dll<br>Vertdll.dll |

## See also

[Enclaves APIs available in Vertdll](https://learn.microsoft.com/windows/win32/trusted-execution/enclaves-available-in-vertdll)