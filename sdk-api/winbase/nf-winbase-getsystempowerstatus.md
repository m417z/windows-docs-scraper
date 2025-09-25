# GetSystemPowerStatus function

## Description

Retrieves the power status of the system. The status indicates whether the system is running on AC or DC power, whether the battery is currently charging, how much battery life remains, and if battery saver is on or off.

## Parameters

### `lpSystemPowerStatus` [out]

A pointer to a
[SYSTEM_POWER_STATUS](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-system_power_status) structure that receives status information.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

To compile an application that uses this function, define the _WIN32_WINNT macro as 0x0400 or later. For more information, see
[Using the Windows Headers](https://learn.microsoft.com/windows/desktop/WinProg/using-the-windows-headers).

## See also

[Power Management Functions](https://learn.microsoft.com/windows/desktop/Power/power-management-functions)

[SYSTEM_POWER_STATUS](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-system_power_status)

[System Power Status](https://learn.microsoft.com/windows/desktop/Power/system-power-status)