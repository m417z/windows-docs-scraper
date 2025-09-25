# NPGetConnection3 function

## Description

Retrieves information about a network connection, even if it is currently disconnected.

## Parameters

### `lpLocalName` [in]

Pointer to the name of the local device the caller is interested in. The provider can assume that this is syntactically valid.

### `dwLevel` [in]

Value that specifies whether the network connection is currently connected or disconnected.

| Value | Meaning |
| --- | --- |
| **WNGETCON_CONNECTED** | The network connection is connected. |
| **WNGETCON_DISCONNECTED** | The network connection is disconnected. |

### `lpBuffer` [out]

Void pointer that receives a buffer that contains the requested information.

### `lpBufferSize` [in, out]

Pointer to the size, in characters, of the *lpBuffer* buffer. If the call fails because the buffer is not big enough, *lpBufferSize* is set to the required buffer size.

## Return value

If the function succeeds, it should return WN_SUCCESS.

If the function fails, it should return one of the following values.

| Return code | Description |
| --- | --- |
| **WN_NOT_CONNECTED** | The device specified by *lpLocalName* is not redirected by this provider. |
| **WN_MORE_DATA** | The buffer was too small to receive all of the data. |
| **WN_NO_NETWORK** | The network is not present. |

## Remarks

A network connection can exist in three states: connected, disconnected, and unavailable. The **NPGetConnection3** function cannot retrieve information about network connections that are currently unavailable. It can, however, retrieve information about network connections that are currently disconnected because Windows stores the connection information.