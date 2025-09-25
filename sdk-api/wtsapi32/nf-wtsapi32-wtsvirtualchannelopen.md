# WTSVirtualChannelOpen function

## Description

Opens a handle to the server end of a specified virtual channel.

This function is obsolete. Instead, use the [WTSVirtualChannelOpenEx](https://learn.microsoft.com/windows/desktop/api/wtsapi32/nf-wtsapi32-wtsvirtualchannelopenex) function.

## Parameters

### `hServer` [in]

This parameter must be WTS_CURRENT_SERVER_HANDLE.

### `SessionId` [in]

A Remote Desktop Services session identifier. To indicate the current session, specify **WTS_CURRENT_SESSION**. You can use the
[WTSEnumerateSessions](https://learn.microsoft.com/windows/desktop/api/wtsapi32/nf-wtsapi32-wtsenumeratesessionsa) function to retrieve the identifiers of all sessions on a specified RD Session Host server.

To open a virtual channel on another user's session, you need to have permission from the Virtual Channel. For more information, see
[Remote Desktop Services Permissions](https://learn.microsoft.com/windows/desktop/TermServ/terminal-services-permissions). To modify permissions on a session, use the Remote Desktop Services Configuration administrative tool.

### `pVirtualName` [in]

A pointer to a **null**-terminated string containing the virtual channel name. Note that this is an ANSI string even when UNICODE is defined. The virtual channel name consists of one to CHANNEL_NAME_LEN characters, not including the terminating **null**.

## Return value

If the function succeeds, the return value is a handle to the specified virtual channel.

If the function fails, the return value is **NULL**. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

When you have finished using the handle, release it by calling the [WTSVirtualChannelClose](https://learn.microsoft.com/windows/desktop/api/wtsapi32/nf-wtsapi32-wtsvirtualchannelclose) function.

For an example that shows how to gain access to a virtual channel file handle that can be used for asynchronous I/O, see
[WTSVirtualChannelQuery](https://learn.microsoft.com/windows/desktop/api/wtsapi32/nf-wtsapi32-wtsvirtualchannelquery).

If you try to use this function to open the same virtual channel multiple times, it can cause a 10-second delay and disrupt the established channel.

## See also

[WTSEnumerateSessions](https://learn.microsoft.com/windows/desktop/api/wtsapi32/nf-wtsapi32-wtsenumeratesessionsa)

[WTSOpenServer](https://learn.microsoft.com/windows/desktop/api/wtsapi32/nf-wtsapi32-wtsopenservera)

[WTSVirtualChannelClose](https://learn.microsoft.com/windows/desktop/api/wtsapi32/nf-wtsapi32-wtsvirtualchannelclose)