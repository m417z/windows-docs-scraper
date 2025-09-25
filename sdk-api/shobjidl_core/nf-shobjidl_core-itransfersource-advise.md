# ITransferSource::Advise

## Description

Sets up an advisory connection for notifications on the status of file operations.

## Parameters

### `psink` [in]

Type: **[ITransferAdviseSink](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-itransferadvisesink)***

A pointer to notification interface [ITransferAdviseSink](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-itransferadvisesink) to update the calling application using methods on this interface.

### `pdwCookie` [out]

Type: **DWORD***

A pointer to a returned token that uniquely identifies this connection. The calling application uses this token later to delete the connection by passing it to the [ITransferSource::Unadvise](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-itransfersource-unadvise) method. If the connection was not successfully established, this value is zero.

## Return value

Type: **HRESULT**

Any HRESULTs other than listed indicate a failure.

| Return code | Description |
| --- | --- |
| **S_OK** | The Interface successfully associated. |
| **E_UNEXPECTED** | The handler can only handle one sink interface. |

## Remarks

Call **ITransferSource::Advise** before calling any other methods in this interface to enable an advisory session. If not set, the handler should consider it an indication that no feedback is available and to do the "default" operation without consulting the calling application.