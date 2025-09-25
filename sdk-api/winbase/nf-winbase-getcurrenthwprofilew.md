# GetCurrentHwProfileW function

## Description

Retrieves information about the current hardware profile for the local computer.

## Parameters

### `lpHwProfileInfo` [out]

A pointer to an
[HW_PROFILE_INFO](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-hw_profile_infoa) structure that receives information about the current hardware profile.

## Return value

If the function succeeds, the return value is a nonzero value.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The
**GetCurrentHwProfile** function retrieves the display name and globally unique identifier (GUID) string for the hardware profile. The function also retrieves the reported docking state for portable computers with docking stations.

The system generates a GUID for each hardware profile and stores it as a string in the registry. You can use
**GetCurrentHwProfile** to retrieve the GUID string to use as a registry subkey under your application's configuration settings key in **HKEY_CURRENT_USER**. This enables you to store each user's settings for each hardware profile. For example, the Colors control panel application could use the subkey to store each user's color preferences for different hardware profiles, such as profiles for the docked and undocked states. Applications that use this functionality can check the current hardware profile when they start up, and update their settings accordingly.

Applications can also update their settings when a system device message, such as
[DBT_CONFIGCHANGED](https://learn.microsoft.com/windows/desktop/DevIO/dbt-configchanged), indicates that the hardware profile has changed.

To compile an application that uses this function, define the _WIN32_WINNT macro as 0x0400 or later. For more information, see
[Using the Windows Headers](https://learn.microsoft.com/windows/desktop/WinProg/using-the-windows-headers).

#### Examples

```cpp
#include <windows.h>
#include <stdio.h>
#include <tchar.h>

void main(void)
{
   HW_PROFILE_INFO   HwProfInfo;
   if (!GetCurrentHwProfile(&HwProfInfo))
   {
      _tprintf(TEXT("GetCurrentHwProfile failed with error %lx\n"),
                 GetLastError());
      return;
   }
   _tprintf(TEXT("DockInfo = %d\n"), HwProfInfo.dwDockInfo);
   _tprintf(TEXT("Profile Guid = %s\n"), HwProfInfo.szHwProfileGuid);
   _tprintf(TEXT("Friendly Name = %s\n"), HwProfInfo.szHwProfileName);
}

```

> [!NOTE]
> The winbase.h header defines GetCurrentHwProfile as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[DBT_CONFIGCHANGED](https://learn.microsoft.com/windows/desktop/DevIO/dbt-configchanged)

[HW_PROFILE_INFO](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-hw_profile_infoa)

[System
Information Functions](https://learn.microsoft.com/windows/desktop/SysInfo/system-information-functions)