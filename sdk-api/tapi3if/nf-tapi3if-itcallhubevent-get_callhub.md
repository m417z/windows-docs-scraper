# ITCallHubEvent::get_CallHub

## Description

The
**get_CallHub** method returns a pointer to the
[ITCallHub](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcallhub) interface on which the event occurred.

## Parameters

### `ppCallHub` [out]

Pointer to
[ITCallHub](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcallhub) interface.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |
| **E_POINTER** | The *pCallHubState* parameter is not a valid pointer. |

## See also

[CallHub Object](https://learn.microsoft.com/windows/desktop/Tapi/callhub-object)

[ITCallHubEvent](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcallhubevent)