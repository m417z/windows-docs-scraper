# ITAddressCapabilities::get_DeviceClasses

## Description

The
**get_DeviceClasses** method gets device classes. This method is provided for Automation client applications, such as those written in Visual Basic and scripting languages.

## Parameters

### `pVariant` [out]

Pointer to **VARIANT** containing
[device classes](https://learn.microsoft.com/windows/desktop/Tapi/tapi-device-classes).

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