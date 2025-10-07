# LdrDisableThreadCalloutsForDll function

\[This function may be changed or removed from Windows without further notice.\]

Disables thread attach and detach callouts to a DLL.

## Parameters

*DllHandle* `[in]`

Supplies a handle to a loaded DLL.

## Return value

Returns an `NTSTATUS` value indicating success or failure of the function.

## Remarks

This function should not be called with the data table lock held with shared access.

## Requirements

| Requirement | Value |
|----------------|-------------------------------------|
| DLL | Ntdll.dll<br>Vertdll.dll |

## See also

[Enclaves APIs available in Vertdll](https://learn.microsoft.com/windows/win32/trusted-execution/enclaves-available-in-vertdll)