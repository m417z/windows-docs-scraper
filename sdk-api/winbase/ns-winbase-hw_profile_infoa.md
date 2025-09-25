# HW_PROFILE_INFOA structure

## Description

Contains information about a hardware profile. The
[GetCurrentHwProfile](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getcurrenthwprofilea) function uses this structure to retrieve the current hardware profile for the local computer.

## Members

### `dwDockInfo`

The reported docking state of the computer. This member can be a combination of the following bit values.

| Value | Meaning |
| --- | --- |
| **DOCKINFO_DOCKED**<br><br>0x2 | The computer is docked. |
| **DOCKINFO_UNDOCKED**<br><br>0x1 | The computer is undocked. This flag is always set for desktop systems that cannot be undocked. |
| **DOCKINFO_USER_SUPPLIED**<br><br>0x4 | If this flag is set, [GetCurrentHwProfile](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getcurrenthwprofilea) retrieved the current docking state from information provided by the user in the **Hardware Profiles** page of the **System** control panel application. <br><br>If there is no such value or the value is set to 0, this flag is set. |
| **DOCKINFO_USER_DOCKED**<br><br>0x5 | The computer is docked, according to information provided by the user. This value is a combination of the DOCKINFO_USER_SUPPLIED and DOCKINFO_DOCKED flags. |
| **DOCKINFO_USER_UNDOCKED**<br><br>0x6 | The computer is undocked, according to information provided by the user. This value is a combination of the DOCKINFO_USER_SUPPLIED and DOCKINFO_UNDOCKED flags. |

### `szHwProfileGuid`

The globally unique identifier (GUID) string for the current hardware profile. The string returned by
[GetCurrentHwProfile](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getcurrenthwprofilea) encloses the GUID in curly braces, {}; for example:

{12340001-4980-1920-6788-123456789012}

You can use this string as a registry subkey under your application's configuration settings key in **HKEY_CURRENT_USER**. This enables you to store settings for each hardware profile.

### `szHwProfileName`

The display name for the current hardware profile.

## See also

[GetCurrentHwProfile](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getcurrenthwprofilea)

## Remarks

> [!NOTE]
> The winbase.h header defines HW_PROFILE_INFO as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).