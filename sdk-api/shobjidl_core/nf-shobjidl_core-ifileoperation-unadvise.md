# IFileOperation::Unadvise

## Description

Terminates an advisory connection previously established through [IFileOperation::Advise](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ifileoperation-advise).

## Parameters

### `dwCookie` [in]

Type: **DWORD**

The connection token that identifies the connection to delete. This value was originally retrieved by [Advise](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ifileoperation-advise) when the connection was made.

## Return value

Type: **HRESULT**

Any value other than those listed here indicate a failure.

| Return code | Description |
| --- | --- |
| **S_OK** | The connection was terminated successfully. |
| **CONNECT_E_NOCONNECTION** | The value in *dwCookie* does not represent a valid connection. |

## See also

[IFileOperation](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ifileoperation)

[IFileOperation::Advise](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ifileoperation-advise)