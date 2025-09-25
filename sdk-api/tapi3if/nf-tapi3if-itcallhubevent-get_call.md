# ITCallHubEvent::get_Call

## Description

The
**get_Call** method returns a pointer to the
[ITCallInfo](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcallinfo) interface of the call on which the event occurred.

## Parameters

### `ppCall` [out]

**ITCallInfo** interface.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |
| **E_POINTER** | The *ppCallt* parameter is not a valid pointer. |

## Remarks

This method may return a **NULL** if the event is not associated with a call.

## See also

[CallHub Object](https://learn.microsoft.com/windows/desktop/Tapi/callhub-object)

[ITCallHubEvent](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcallhubevent)