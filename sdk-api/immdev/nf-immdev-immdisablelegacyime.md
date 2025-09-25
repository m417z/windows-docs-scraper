# ImmDisableLegacyIME function

## Description

Indicates that this thread is a Windows Store app UI thread.

## Return value

Returns **TRUE** if successful; otherwise, **FALSE**.

## Remarks

Windows Store app brokers such as explorer.exe should call this function in Windows Store app UI threads to ensure that only IMEs that are compatible with Windows Store apps are made available. Those Windows Store app threads that don't require IME input should call [ImmDisableIME](https://learn.microsoft.com/windows/desktop/api/imm/nf-imm-immdisableime) to disable IMM entirely for that thread.

The app must call this function before the first top-level window in the thread receives the [WM_CREATE](https://learn.microsoft.com/windows/desktop/winmsg/wm-create) message. Thus, the app must call this function in one of the following places:

* Any time before [CreateWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-createwindowa) is called to create the first top-level window.
* In the [WM_NCCREATE](https://learn.microsoft.com/windows/desktop/winmsg/wm-nccreate) handler for the first top-level window.

## See also

[Input Method Manager](https://learn.microsoft.com/windows/desktop/Intl/input-method-manager)

[Input Method Manager Functions](https://learn.microsoft.com/windows/desktop/Intl/input-method-manager-functions)