# ITDigitsGatheredEvent::get_Call

## Description

The
**get_Call** method gets a pointer to the call information interface for the call object on which the event occurred.

## Parameters

### `ppCallInfo` [out]

Pointer to the
[ITCallInfo](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcallinfo) interface.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_POINTER** | The *ppCallInfo* parameter is not a valid pointer. |

## See also

[ITDigitsGatheredEvent](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itdigitsgatheredevent)