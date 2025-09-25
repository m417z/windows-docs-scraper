# ITAddressDeviceSpecificEvent::get_Call

## Description

The
**get_Call** method gets a pointer to the
[ITCallInfo](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcallinfo) interface pointer for the call object involved in the event.

## Parameters

### `ppCall` [out]

Pointer to the
[ITCallInfo](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcallinfo) interface.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |
| **E_POINTER** | The *ppCall* parameter is not a valid pointer. |

## See also

[ITAddressDeviceSpecificEvent](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itaddressdevicespecificevent)

[ITCallInfo](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcallinfo)