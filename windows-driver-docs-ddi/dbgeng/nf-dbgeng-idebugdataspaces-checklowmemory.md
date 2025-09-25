# IDebugDataSpaces::CheckLowMemory

## Description

The **CheckLowMemory** method checks for memory corruption in the low 4 GB of memory.

## Return value

| Return code | Description |
| --- | --- |
| **S_OK** | No corruption was found. |
| **FACILITY_NT_BIT |*Page*** | Corruption was found on the memory page *Page*. |

This method can also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

## Remarks

This method is only available in [kernel-mode debugging](https://learn.microsoft.com/windows-hardware/drivers/debugger/k), and is only useful when the [kernel](https://learn.microsoft.com/windows-hardware/drivers/debugger/k) was booted using the **/nolowmem** option.

When the kernel is booted with the **/nolowmem** option, the kernel, drivers, operating system and applications are loaded in memory above 4 GB, while the low 4 GB of memory is filled with a unique pattern. The **CheckLowMemory** method checks this pattern for corruption.

This may be used to verify that a driver behaves well when using physical addresses greater than 32 bits in length. See *Physical Address Extension (PAE)*, **/pae**, and **/nolowmem** in the Windows Driver Kit.