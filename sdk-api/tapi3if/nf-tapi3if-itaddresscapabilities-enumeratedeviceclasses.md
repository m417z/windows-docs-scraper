# ITAddressCapabilities::EnumerateDeviceClasses

## Description

The
**EnumerateDeviceClasses** method gets device classes. This method is provided for applications written in C/C++ and Java.

## Parameters

### `ppEnumDeviceClass` [out]

Pointer to enumeration of
[device classes](https://learn.microsoft.com/windows/desktop/Tapi/tapi-device-classes).

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_NOTIMPL** | Method not implemented. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |

## Remarks

TAPI calls the **AddRef** method on the
[IEnumBstr](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-ienumbstr) interface returned by **ITAddressCapabilities::EnumerateDeviceClasses**. The application must call **Release** on the
**IEnumBstr** interface to free resources associated with it.

## See also

[Address Object](https://learn.microsoft.com/windows/desktop/Tapi/address-object)

[IEnumBstr](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-ienumbstr)

[ITAddressCapabilities](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itaddresscapabilities)