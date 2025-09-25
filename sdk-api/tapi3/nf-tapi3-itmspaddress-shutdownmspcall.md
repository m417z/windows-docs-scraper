# ITMSPAddress::ShutdownMSPCall

## Description

The
**ShutdownMSPCall** method is called when the call object is being destroyed.

## Parameters

### `pStreamControl` [in]

Pointer to [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) interface for the call's
[ITStreamControl](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itstreamcontrol).

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_POINTER** | The *pStreamControl* parameter is not a valid pointer. |
| **E_INVALIDARG** | The *pStreamControl* parameter does not point to a valid [ITStreamControl](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itstreamcontrol) interface. |

## Remarks

This method is not automatically invoked when a call enters the disconnect state. The paired TSP of the MSP should notify the MSP of this call state change, but, because applications may retain the call object for information logging purposes after a disconnect, shutdown should not be called until the call object itself is released.

## See also

[ITMSPAddress](https://learn.microsoft.com/windows/desktop/api/msp/nn-msp-itmspaddress)

[Media Service Provider Interface (MSPI)](https://learn.microsoft.com/windows/desktop/Tapi/media-service-provider-interface-mspi-)