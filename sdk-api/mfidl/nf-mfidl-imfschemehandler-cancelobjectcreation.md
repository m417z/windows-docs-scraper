# IMFSchemeHandler::CancelObjectCreation

## Description

Cancels the current request to create an object from a URL.

## Parameters

### `pIUnknownCancelCookie` [in]

Pointer to the **IUnknown** interface that was returned in the *ppIUnknownCancelCookie* parameter of the [IMFSchemeHandler::BeginCreateObject](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfschemehandler-begincreateobject) method.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

You can use this method to cancel a previous call to [BeginCreateObject](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfschemehandler-begincreateobject). Because that method is asynchronous, however, it might be completed before the operation can be canceled. Therefore, your callback might still be invoked after you call this method.

The operation cannot be canceled if [BeginCreateObject](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfschemehandler-begincreateobject) returns **NULL** in the *ppIUnknownCancelCookie* parameter.

## See also

[IMFSchemeHandler](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfschemehandler)

[Scheme Handlers and Byte-Stream Handlers](https://learn.microsoft.com/windows/desktop/medfound/scheme-handlers-and-byte-stream-handlers)