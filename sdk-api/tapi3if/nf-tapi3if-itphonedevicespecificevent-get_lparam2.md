# ITPhoneDeviceSpecificEvent::get_lParam2

## Description

The
**get_lParam2** method retrieves the second of three buffers specific to a given phone device. The precise content and meaning of these buffers is defined by the provider.

## Parameters

### `pParam2` [out]

Pointer to a **long** concerning information on the phone device event.

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |
| **E_POINTER** | The *pParam2* parameter is not a valid pointer. |

## See also

[ITPhoneDeviceSpecificEvent](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itphonedevicespecificevent)

[Phone and Address Device-specific Events](https://learn.microsoft.com/windows/desktop/Tapi/phone-and-address-device-specific-events)