# ITAddressCapabilities::get_CompletionMessages

## Description

The
**get_CompletionMessages** gets completion messages. This method is provided for Automation client applications, such as those written in Visual Basic and scripting languages.

## Parameters

### `pVariant` [out]

Pointer to **VARIANT** containing completion messages.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_NOTIMPL** | Method not implemented. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |

## See also

[Address Object](https://learn.microsoft.com/windows/desktop/Tapi/address-object)

[ITAddressCapabilities](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itaddresscapabilities)