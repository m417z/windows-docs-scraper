# ITfContext::InWriteSession

## Description

Determines if a client has a read/write lock on the context.

## Parameters

### `tid` [in]

Contains a **TfClientID** value that identifies the client.

### `pfWriteSession` [out]

Pointer to a **BOOL** that receives a nonzero value if the client has a read/write lock on the context. Receives zero if the client does not have an edit session or has a read-only edit session.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_INVALIDARG** | *pfWriteSession* is invalid. |

## Remarks

A client uses this method, from inside a notification callback, to determine if it must make the change.

## See also

[ITfContext interface](https://learn.microsoft.com/windows/win32/api/msctf/nn-msctf-itfcontext)