# SHSendMessageBroadcastW function

## Description

[This function is available through Windows XP and Windows Server 2003. It might be altered or unavailable in subsequent versions of Windows.]

Sends a message to all top-level windows in the system.

## Parameters

### `uMsg` [in]

Type: **UINT**

The message to send.

### `wParam` [in]

Type: **WPARAM**

Additional message-specific information.

### `lParam` [in]

Type: **LPARAM**

Additional message-specific information.

## Return value

Type: **LRESULT**

The return value is not meaningful.

## Remarks

**SHSendMessageBroadcast** is equivalent to [SendMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-sendmessage) with **HWND_BROADCAST**. To avoid causing the Shell to become unresponsive in the case where there could be a window in the system that is not responding to messages, use **SHSendMessageBroadcast**.

**SHSendMessageBroadcast** is not exported by name. **SHSendMessageBroadcastA** is exported from Shlwapi.dll as ordinal 432. **SHSendMessageBroadcastW** is exported from Shlwapi.dll as ordinal 433.

> [!NOTE]
> The shlwapi.h header defines SHSendMessageBroadcast as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).