# GetPwrDiskSpindownRange function

## Description

[**GetPwrDiskSpindownRange** is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. See Remarks.]

Retrieves the disk spindown range.

## Parameters

### `puiMax` [out]

The maximum disk spindown time, in seconds.

### `puiMin` [out]

The minimum disk spindown time, in seconds.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

Starting with Windows Vista, power management configuration of the system's hard disk drives is controlled through the GUID_DISK_SUBGROUP power settings subgroup. Use the [PowerEnumerate](https://learn.microsoft.com/windows/desktop/api/powrprof/nf-powrprof-powerenumerate) function to enumerate individual settings.

For more information on using PowrProf.h, see [Power Schemes](https://learn.microsoft.com/windows/desktop/Power/power-schemes).

## See also

[CallNtPowerInformation](https://learn.microsoft.com/windows/desktop/api/powerbase/nf-powerbase-callntpowerinformation)

[Power Management Functions](https://learn.microsoft.com/windows/desktop/Power/power-management-functions)