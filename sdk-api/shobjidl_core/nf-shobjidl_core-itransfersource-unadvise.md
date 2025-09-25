# ITransferSource::Unadvise

## Description

Terminates an advisory connection.

## Parameters

### `dwCookie` [in]

Type: **DWORD**

The connection token previously returned from method [ITransferSource::Advise](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-itransfersource-advise).

## Return value

Type: **HRESULT**

Any HRESULTs other than listed indicate a failure.

| Return code | Description |
| --- | --- |
| **S_OK** | The connection was successfully terminated. |
| **CONNECT_E_NOCONNECTION** | The value in dwCookie does not represent a valid connection. |

## Remarks

Terminates an advisory connection previously established through method [ITransferSource::Advise](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-itransfersource-advise). The *dwCookie* parameter identifies the connection to terminate.