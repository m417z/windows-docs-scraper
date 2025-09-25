# ShutdownTextServices function

## Description

Disconnects a host from a text services instance.

## Parameters

### `pTextServices` [in]

Type: **[IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown)***

A text services instance created by a previous call to the [CreateTextServices](https://learn.microsoft.com/windows/desktop/api/textserv/nf-textserv-createtextservices) function.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the text services object was created successfully, the return value is S_OK.

If the function fails, one of the following COM error codes are returned. For more information on COM error codes, see [Error Handling in COM](https://learn.microsoft.com/windows/desktop/com/error-handling-in-com).

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | The *pTextServices* parameter is not valid. |

## Remarks

A host calls this function when the host is being freed. Calling this function is necessary because all text services instances maintain a host pointer for which the [AddRef](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref) method has not been called. This function calls the [Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) method on the text services instance and, if this is not the last reference to the text services object, nulls out the host pointer in the text services object and prepares the control to handle failed operations that require host services. This function allows any other outstanding references to the text services object to work or fail gracefully depending on the service required.

## See also

[CreateTextServices](https://learn.microsoft.com/windows/desktop/api/textserv/nf-textserv-createtextservices)