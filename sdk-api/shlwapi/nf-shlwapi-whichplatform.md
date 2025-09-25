# WhichPlatform function

## Description

[**WhichPlatform** is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

Retrieves a value that indicates the type of Shell32.dll that the platform contains.

## Return value

Type: **UINT**

| Return code | Description |
| --- | --- |
| **PLATFORM_UNKNOWN** | The function was unable to determine the Shell32.dll version. |
| **PLATFORM_IE3** | Obsolete: Use PLATFORM_BROWSERONLY. |
| **PLATFORM_BROWSERONLY** | The Shell32.dll version is browser-only, with no new shell. |
| **PLATFORM_INTEGRATED** | The platform contains an integrated shell. |

## Remarks

This function always returns PLATFORM_INTEGRATED because Windows XP comes with an integrated shell.

## See also

[Shell and Common Controls Versions](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/bb776779(v=vs.85))