# ITransferDestination::Unadvise

## Description

Terminates an advisory connection.

## Parameters

### `dwCookie` [in]

Type: **DWORD**

A connection token previously returned from [ITransferDestination::Advise](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-itransferdestination-advise). Identifies the connection to be terminated.

## Return value

Type: **HRESULT**

Any HRESULTs other than those listed here indicate a failure.

| Return code | Description |
| --- | --- |
| **S_OK** | The connection was successfully terminated. |
| **CONNECT_E_NOCONNECTION** | The value in *dwCookie* does not represent a valid connection. |

## Remarks

Terminates an advisory connection previously established through the [ITransferDestination::Advise](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-itransferdestination-advise) method.