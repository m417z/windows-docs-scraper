## Description

> [!NOTE]
> This API was added to the 19041 SDK in an update released in November 2020.

Sets dynamic enforced CETCOMPAT ranges for the specified process.

## Parameters

### `Process`

A handle to the process. This handle must have the **PROCESS_SET_INFORMATION** access right.
For more information, see [Process Security and Access Rights](https://learn.microsoft.com/windows/desktop/ProcThread/process-security-and-access-rights).

### `NumberOfRanges`

Supplies the number of dynamic enforced CETCOMPAT ranges to set.

### `Ranges`

A pointer to an array of dynamic enforced CETCOMPAT ranges. For more information on this structure, see [PROCESS_DYNAMIC_ENFORCED_ADDRESS_RANGE](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-process_dynamic_enforced_address_range).

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).
Note that even if the function fails, a portion of the supplied CETCOMPAT ranges may have been successfully processed.
The caller needs to check the flags in each individual CETCOMPAT range specified via *Ranges* to determine if it was successfully processed.

## Remarks

User-mode Hardware-enforced Stack Protection (HSP) is a security feature where the CPU verifies function return addresses at runtime by employing a shadow stack mechanism, if supported by the hardware.
In HSP compatibility mode, only shadow stack violations occurring in modules that are considered compatible with shadow stacks (CETCOMPAT) are fatal.
For a module to be considered CETCOMPAT, it needs to be either compiled with [CETCOMPAT](https://learn.microsoft.com/cpp/build/reference/cetcompat) for binaries, or marked using *SetProcessDynamicEnforcedCetCompatibleRanges* for dynamic code.
In HSP strict mode, all shadow stack violations are fatal.

## See also