# ITQueue::get_CurrentCallsQueued

## Description

The
**get_CurrentCallsQueued** method gets the number of incoming calls currently waiting.

## Parameters

### `plCalls` [out]

Pointer to the number of incoming calls in the queue.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_POINTER** | The *plCalls* is not a valid pointer. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |

## See also

[ITQueue](https://learn.microsoft.com/windows/desktop/api/tapi3cc/nn-tapi3cc-itqueue)