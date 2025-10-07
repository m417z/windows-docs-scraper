# FileIconInit function

Initializes or reinitializes the system image list.

## Parameters

*fRestoreCache* \[in\]

Type: **BOOL**

**TRUE** to restore the system image cache from disk; **FALSE** otherwise.

## Return value

Type: **BOOL**

**TRUE** if the cache was successfully refreshed, **FALSE** if the initialization failed.

## Remarks

If you are using system image lists in your own process, you must call **FileIconInit** at the following times:

- On launch.
- In response to a [**WM\_SETTINGCHANGE**](https://learn.microsoft.com/windows/win32/winmsg/wm-settingchange) message when the [**SPI\_SETNONCLIENTMETRICS**](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-systemparametersinfoa) flag is set.

**FileIconInit** is not included in a header file. You must call it directly from Shell32.dll, using ordinal 660.

## Requirements

| Requirement | Value |
|-------------------------------------|----------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows XP \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| DLL<br> | Shell32.dll |

