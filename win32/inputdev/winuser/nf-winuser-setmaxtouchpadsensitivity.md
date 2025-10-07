# SetMaxTouchpadSensitivity function

SetMaxTouchpadSensitivity allows the system to handle touchpad input when the current process is in foreground as if the user had selected “Most Sensitive” for the touchpad’s sensitivity setting, resulting in the touchpad input being unaffected by any simultaneous keyboard input that may be occurring.

## Parameters

`[in] maxSensitivity`

Type: **BOOL**

If TRUE, the system will use the maximum touchpad sensitivity setting while the foreground window is owned by the current process. If FALSE, the user’s setting will be used.

Note that the last value of maxSensitivity is respected (as opposed to incrementing or decrementing a count that determines if the touchpad sensitivity is set to max).

## Return value

Type: **BOOL**

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

> [!TIP]
> At this time, this function does not have an associated header file or library file. Your application can call [**LoadLibrary**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibrarya) with the DLL name (`User32.dll`) to obtain a module handle. It can then call [**GetProcAddress**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-getprocaddress) with the module handle and the name of this function to get the function address.

## Requirements

|   |   |
| ---- |:---- |
| **Minimum supported client** | Windows 11 [desktop apps only] |
| **Target Platform** | Windows |
| **Header** | None |
| **Library** | None |
| **DLL** | User32.dll |

## See also

[TOUCHPAD_SENSITIVITY_LEVEL enumeration](https://learn.microsoft.com/windows/win32/api/winuser/ne-winuser-touchpad_sensitivity_level)