# ITCallMediaEvent::get_Event

## Description

The
**get_Event** method gets the call media event indicator.

## Parameters

### `pCallMediaEvent` [out]

Pointer to
[CALL_MEDIA_EVENT](https://learn.microsoft.com/windows/desktop/api/tapi3if/ne-tapi3if-call_media_event) indicator.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |
| **E_POINTER** | The *pCallMediaEvent* parameter is not a valid pointer. |

## Remarks

Call media events are a crucial indicator of whether certain operations can be performed. For example, when
**IVideoWindow** is exposed on the
[Terminal object](https://learn.microsoft.com/windows/desktop/Tapi/terminal-object), until the CME_STREAM_ACTIVE is received only the
**put_Visible** method will succeed. For more information about **IVideoWindow** and **put_Visible**, see the DirectX documentation.

## See also

[CALL_MEDIA_EVENT](https://learn.microsoft.com/windows/desktop/api/tapi3if/ne-tapi3if-call_media_event)

[Call Object](https://learn.microsoft.com/windows/desktop/Tapi/call-object)

[ITCallMediaEvent](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcallmediaevent)