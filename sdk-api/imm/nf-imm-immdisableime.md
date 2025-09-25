# ImmDisableIME function

## Description

Disables the IME for a thread or for all threads in a process.

## Parameters

### `DWORD` [in]

Identifier of the thread for which to disable the IME. The thread must be in the same process as the application calling this function. The application sets this parameter to 0 to disable the IME for the current thread. The application specifies -1 to disable the IME for all threads in the current process.

## Return value

Returns **TRUE** if successful or **FALSE** otherwise.

## Remarks

The application must call this function before the first top-level window in the thread receives the [WM_CREATE](https://learn.microsoft.com/windows/desktop/winmsg/wm-create) message. Thus, the application must call this function in one of the following places:

* Any time before calling [CreateWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-createwindowa) to create the first top-level window
* In the [WM_NCCREATE](https://learn.microsoft.com/windows/desktop/winmsg/wm-nccreate) handler for first top-level window

## See also

[Input Method Manager](https://learn.microsoft.com/windows/desktop/Intl/input-method-manager)

[Input Method Manager Functions](https://learn.microsoft.com/windows/desktop/Intl/input-method-manager-functions)