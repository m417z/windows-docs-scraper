# ITQueueEvent::get_Queue

## Description

The
**get_Queue** method gets a pointer to the queue on which the event occurred.

## Parameters

### `ppQueue` [out]

Pointer to
[ITQueue](https://learn.microsoft.com/windows/desktop/api/tapi3cc/nn-tapi3cc-itqueue) interface on which event occurred.

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_POINTER** | The *ppQueue* is not a valid pointer. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |

## Remarks

TAPI calls the **AddRef** method on the
[ITQueue](https://learn.microsoft.com/windows/desktop/api/tapi3cc/nn-tapi3cc-itqueue) interface returned by **ITQueueEvent::get_Queue**. The application must call **Release** on the
**ITQueue** interface to free resources associated with it.

## See also

[ITQueue](https://learn.microsoft.com/windows/desktop/api/tapi3cc/nn-tapi3cc-itqueue)

[ITQueueEvent](https://learn.microsoft.com/windows/desktop/api/tapi3cc/nn-tapi3cc-itqueueevent)