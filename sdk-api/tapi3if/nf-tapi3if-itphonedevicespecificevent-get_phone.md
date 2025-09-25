# ITPhoneDeviceSpecificEvent::get_Phone

## Description

The
**get_Phone** method retrieves the
[ITPhone](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itphone) interface pointer for a phone device event.

## Parameters

### `ppPhone` [out]

Pointer to the
[ITPhone](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itphone) interface for the phone object involved in the event.

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |
| **E_POINTER** | The *ppPhone* parameter is not a valid pointer. |

## See also

[ITPhone](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itphone)

[ITPhoneDeviceSpecificEvent](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itphonedevicespecificevent)