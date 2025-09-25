# ITCallMediaEvent::get_Cause

## Description

The
**get_Cause** method gets the cause of the call media event, such as a timeout on the renderer device.

## Parameters

### `pCause` [out]

Pointer to
[CALL_MEDIA_EVENT_CAUSE](https://learn.microsoft.com/windows/desktop/api/tapi3if/ne-tapi3if-call_media_event_cause).

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |
| **E_POINTER** | The *pCause* parameter is not a valid pointer. |

## See also

[CALL_MEDIA_EVENT_CAUSE](https://learn.microsoft.com/windows/desktop/api/tapi3if/ne-tapi3if-call_media_event_cause)

[Call Object](https://learn.microsoft.com/windows/desktop/Tapi/call-object)