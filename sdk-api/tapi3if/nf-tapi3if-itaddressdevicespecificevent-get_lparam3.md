# ITAddressDeviceSpecificEvent::get_lParam3

## Description

The
**get_lParam3** method retrieves the third of three buffers specific to a given address device. The precise content and meaning of these buffers is defined by the provider.

## Parameters

### `pParam3` [out]

 Pointer to a **long** concerning information on the address device event.

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |
| **E_POINTER** | The *pParam3* parameter is not a valid pointer. |

## See also

[ITAddressDeviceSpecificEvent](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itaddressdevicespecificevent)

[Phone and Address Device-specific Events](https://learn.microsoft.com/windows/desktop/Tapi/phone-and-address-device-specific-events)