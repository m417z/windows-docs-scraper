# WPUPostMessage function

## Description

The
**WPUPostMessage** function performs the standard Windows [PostMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-postmessagea) function in a way that maintains backward compatibility with older versions of WSOCK32.dll.

## Parameters

### `hWnd` [in]

Handle to the window that will receive the message.

### `Msg` [in]

Message that will be posted.

### `wParam` [in]

First parameter containing additional message-specific information.

### `lParam` [in]

Second parameter containing additional message-specific information.

## Return value

If no error occurs,
**WPUPostMessage** returns the **TRUE** value. Otherwise, the **FALSE** value is returned.