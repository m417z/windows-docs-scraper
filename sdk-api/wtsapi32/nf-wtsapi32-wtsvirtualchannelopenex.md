# WTSVirtualChannelOpenEx function

## Description

Creates a virtual channel in a manner similar to
[WTSVirtualChannelOpen](https://learn.microsoft.com/windows/desktop/api/wtsapi32/nf-wtsapi32-wtsvirtualchannelopen).

This API supports both static virtual channel (SVC) and dynamic virtual channel (DVC) creation. If the
*flags* parameter is zero, it behaves the same as
[WTSVirtualChannelOpen](https://learn.microsoft.com/windows/desktop/api/wtsapi32/nf-wtsapi32-wtsvirtualchannelopen). A DVC can be opened
by specifying the appropriate flag. After a DVC is created, you can use the same functions for Read, Write, Query,
or Close that are used for the SVC.

## Parameters

### `SessionId` [in]

A Remote Desktop Services session identifier. To indicate the current session, specify
**WTS_CURRENT_SESSION**. You can use the
[WTSEnumerateSessions](https://learn.microsoft.com/windows/desktop/api/wtsapi32/nf-wtsapi32-wtsenumeratesessionsa) function to retrieve
the identifiers of all sessions on a specified RD Session Host server.

To be able to open a virtual channel on another user's session, you must have the Virtual Channels
permission. For more information, see
[Remote Desktop Services Permissions](https://learn.microsoft.com/windows/desktop/TermServ/terminal-services-permissions).
To modify permissions on a session, use the Remote Desktop Services Configuration administrative tool.

### `pVirtualName` [in]

In the case of an SVC, points to a null-terminated string that contains the virtual channel name. The length
of an SVC name is limited to **CHANNEL_NAME_LEN** characters, not including the
terminating null.

In the case of a DVC, points to a null-terminated string that contains the endpoint name of the listener. The
length of a DVC name is limited to **MAX_PATH** characters.

### `flags` [in]

To open the channel as an SVC, specify zero for this parameter. To open the channel as a DVC, specify
**WTS_CHANNEL_OPTION_DYNAMIC**.

When opening a DVC, you can specify a priority setting for the data that is being transferred by specifying
one of the **WTS_CHANNEL_OPTION_DYNAMIC_PRI_*XXX*** values in
combination with the **WTS_CHANNEL_OPTION_DYNAMIC** value.

#### WTS_CHANNEL_OPTION_DYNAMIC_NO_COMPRESS

Disables compression for this DVC. You must specify this value in combination with the
**WTS_CHANNEL_OPTION_DYNAMIC** value.

#### WTS_CHANNEL_OPTION_DYNAMIC_PRI_LOW (default)

Low priority. The data will be sent on both sides with low priority. Use this priority level for block
transfers of all sizes, where the transfer speed is not important. In almost all (95%) cases, the channel
should be opened with this flag.

#### WTS_CHANNEL_OPTION_DYNAMIC_PRI_MED

Medium priority. Use this priority level to send short control messages that must have priority over the
data in the low priority channels.

#### WTS_CHANNEL_OPTION_DYNAMIC_PRI_HIGH

High priority. Use this priority level for data that is critical and directly affects the user
experience. The transfer size may vary. Display data falls into this category.

#### WTS_CHANNEL_OPTION_DYNAMIC_PRI_REAL

Real-time priority. Use this priority level only in cases where the data transfer is absolutely critical.
The data transfer size should be limited to a few hundred bytes per message.

## Return value

**NULL** on error with
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) set.

## See also

[DVC Server APIs](https://learn.microsoft.com/windows/desktop/TermServ/dvc-server-apis)

[Dynamic Virtual Channels Reference](https://learn.microsoft.com/windows/desktop/TermServ/dynamic-virtual-channels-reference)

[WTSVirtualChannelOpen](https://learn.microsoft.com/windows/desktop/api/wtsapi32/nf-wtsapi32-wtsvirtualchannelopen)