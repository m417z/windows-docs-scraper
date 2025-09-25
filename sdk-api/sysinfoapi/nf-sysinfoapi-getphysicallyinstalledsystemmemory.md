# GetPhysicallyInstalledSystemMemory function

## Description

Retrieves the amount of RAM that is physically installed on the computer.

## Parameters

### `TotalMemoryInKilobytes` [out]

A pointer to a
variable that receives the amount of physically installed RAM, in kilobytes.

## Return value

If the function succeeds, it returns **TRUE** and sets the
*TotalMemoryInKilobytes* parameter to a nonzero value.

If the function fails, it returns **FALSE** and does not modify the
*TotalMemoryInKilobytes* parameter. To get extended error information, use the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function. Common errors are listed in the following table.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | The *TotalMemoryInKilobytes* parameter is **NULL**. |
| **ERROR_INVALID_DATA** | The System Management BIOS (SMBIOS) data is malformed. |

## Remarks

The **GetPhysicallyInstalledSystemMemory** function retrieves the amount of physically installed RAM from the computer's SMBIOS firmware tables. This can differ from the amount reported by the [GlobalMemoryStatusEx](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-globalmemorystatusex) function, which sets the **ullTotalPhys** member of the [MEMORYSTATUSEX](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/ns-sysinfoapi-memorystatusex) structure to the amount of physical memory that is available for the operating system to use. The amount of memory available to the operating system can be less than the amount of memory physically installed in the computer because the BIOS and some drivers may reserve memory as I/O regions for memory-mapped devices, making the memory unavailable to the operating system and applications.

The amount of physical memory retrieved by the **GetPhysicallyInstalledSystemMemory** function must be equal to or greater than the amount reported by the [GlobalMemoryStatusEx](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-globalmemorystatusex) function; if it is less, the SMBIOS data is malformed and the function fails with **ERROR_INVALID_DATA**. Malformed SMBIOS data may indicate a problem with the user's computer.

## See also

[EnumSystemFirmwareTables](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-enumsystemfirmwaretables)

[GetSystemFirmwareTable](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-getsystemfirmwaretable)

[GlobalMemoryStatusEx](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-globalmemorystatusex)