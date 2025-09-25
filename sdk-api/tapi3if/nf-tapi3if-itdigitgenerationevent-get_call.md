# ITDigitGenerationEvent::get_Call

## Description

The
**get_Call** method returns an
[ITCallInfo](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcallinfo) interface pointer for the call on which the event is required.

## Parameters

### `ppCallInfo` [out]

Pointer to
[ITCallInfo](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcallinfo) interface.

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |
| **E_POINTER** | The *ppCallInfo* parameter is not a valid pointer. |

## See also

[ITCallInfo](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcallinfo)

[ITDigitGenerationEvent](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itdigitgenerationevent)