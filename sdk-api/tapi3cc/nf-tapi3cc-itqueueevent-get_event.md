# ITQueueEvent::get_Event

## Description

The
**get_Event** method gets the descriptor of the event that occurred.

## Parameters

### `pEvent` [out]

Pointer to
[ACDQUEUE_EVENT](https://learn.microsoft.com/windows/desktop/api/tapi3/ne-tapi3-acdqueue_event) descriptor of event.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_POINTER** | The *pEvent* is not a valid pointer. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |

## See also

[ACDQUEUE_EVENT](https://learn.microsoft.com/windows/desktop/api/tapi3/ne-tapi3-acdqueue_event)

[ITQueueEvent](https://learn.microsoft.com/windows/desktop/api/tapi3cc/nn-tapi3cc-itqueueevent)