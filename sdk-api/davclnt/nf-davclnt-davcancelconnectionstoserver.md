# DavCancelConnectionsToServer function

## Description

Closes all connections to a WebDAV server or a remote file or directory on a WebDAV server.

## Parameters

### `lpName` [in]

Pointer to a null-terminated Unicode string that contains the name of the remote file or server. This string must be in one of the following formats:

* http://*server*/*path*
* \\*server*\*path*
* *server*

where *server* is the name of a WebDAV server, and *path* is the path to a remote file or directory on the server.

### `fForce`

A Boolean value that specifies whether the connection should be closed if there are open files. Set this parameter to **FALSE** if the connection should be closed only if there are no open files. Set this parameter to **TRUE** if the connection should be closed even if there are open files.

## Return value

If the function succeeds, the return value is ERROR_SUCCESS.

If the function fails, the return value is a [system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) or network error code such as one of the following values.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | The *lpName* parameter contained a value that was not valid. |
| **WN_BAD_NETNAME** | The *lpName* parameter contained a value that was not a valid remote file name. |
| **WN_NOT_CONNECTED** | No connections to the remote file or server were found. |
| **WN_OPEN_FILES** | There are open files on the connection, and *fForce* parameter was set to **FALSE**. |