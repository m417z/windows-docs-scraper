# ITQOSEvent::get_Event

## Description

The
**get_Event** method gets the
[QOS_EVENT](https://learn.microsoft.com/windows/desktop/api/tapi3if/ne-tapi3if-qos_event) indicator.

## Parameters

### `pQosEvent` [out]

Indicator of the QOS event type.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_POINTER** | The *pQosEvent* parameter is not a valid pointer. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |

## See also

[ITQOSEvent](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itqosevent)

[QOS_EVENT](https://learn.microsoft.com/windows/desktop/api/tapi3if/ne-tapi3if-qos_event)