# NetWkstaTransportDel function

## Description

[This function is obsolete. To change the default settings for transport protocols manually, use the **Local Area Connection Properties** dialog box in the **Network and Dial-Up Connections** folder.]

Not supported.

The
**NetWkstaTransportDel** function unbinds the transport protocol from the redirector. (The redirector is the software on the client computer that generates file requests to the server computer.)

## Parameters

### `servername` [in]

Pointer to a string that specifies the DNS or NetBIOS name of the remote server on which the function is to execute. If this parameter is **NULL**, the local computer is used.

This string must begin with \\.

### `transportname` [in]

Pointer to a string that specifies the name of the transport protocol to disconnect from the redirector.

### `ucond` [in]

Specifies the level of force to use when disconnecting the transport protocol from the redirector. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **USE_NOFORCE** | Fail the disconnection if open files exist on the connection. |
| **USE_FORCE** | Fail the disconnection if open files exist on the connection. |
| **USE_LOTS_OF_FORCE** | Close any open files and delete the connection. |

## Return value

If the function succeeds, the return value is NERR_Success.

If the function fails, the return value can be one of the following error codes.

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | The user does not have access to the requested information. |
| **ERROR_INVALID_PARAMETER** | One of the function parameters is invalid. |
| **NERR_UseNotFound** | The network connection does not exist. |

## Remarks

Only members of the Administrators local group can successfully execute the
**NetWkstaTransportDel** function.