# NPGetConnection function

## Description

Retrieves information about a connection.

## Parameters

### `lpLocalName` [in]

Pointer to the name of the local device the caller is interested in. The network provider can assume this name is syntactically valid.

### `lpRemoteName` [out]

Pointer to a buffer that will receive the remote name used to make the connection. This buffer is allocated by the caller.

### `lpnBufferLen` [in, out]

Pointer to the size, in characters, of the *lpRemoteName* buffer. If the call fails because the buffer is not big enough, *lpBufferSize* is set to the required buffer size.

## Return value

If the function succeeds, it should return WN_SUCCESS. Otherwise, it should return an error code, which can be one of the following:

| Return code | Description |
| --- | --- |
| **WN_NOT_CONNECTED** | The device specified by *lpLocalName* is not redirected by this provider. |
| **WN_MORE_DATA** | The buffer was too small to receive all of the data. |
| **WN_NO_NETWORK** | The network is not present. |

## Remarks

The **NPGetConnection** function can return information only about a network connection that is currently connected. To retrieve information about a network connection that is currently disconnected, use
[NPGetConnection3](https://learn.microsoft.com/windows/desktop/api/npapi/nf-npapi-npgetconnection3).