# ImmGetVirtualKey function

## Description

Retrieves the original virtual key value associated with a key input message that the IME has already processed.

## Parameters

### `HWND` [in]

Handle to the window that receives the key message.

## Return value

If [TranslateMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-translatemessage) has been called by the application, **ImmGetVirtualKey** returns VK_PROCESSKEY; otherwise, it returns the virtual key.

## Remarks

Although the IME sets the virtual key value to VK_PROCESSKEY after processing a key input message, an application can recover the original virtual key value with the **ImmGetVirtualKey** function. This function is used only for key input messages containing the VK_PROCESSKEY value. Applications can only get the original virtual key by using this function after receiving

the [WM_KEYDOWN](https://learn.microsoft.com/windows/desktop/inputdev/wm-keydown) (VK_PROCESSKEY) message, and before [TranslateMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-translatemessage) is called in its own

message loop.

## See also

[Input Method Manager](https://learn.microsoft.com/windows/desktop/Intl/input-method-manager)

[Input Method Manager Functions](https://learn.microsoft.com/windows/desktop/Intl/input-method-manager-functions)