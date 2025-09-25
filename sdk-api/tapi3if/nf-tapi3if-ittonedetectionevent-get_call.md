# ITToneDetectionEvent::get_Call

## Description

The
**get_Call** method gets a pointer to the call information interface for the call object on which the tone detection event occurred.

## Parameters

### `ppCallInfo` [out]

Pointer to the
[ITCallInfo](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcallinfo) interface.

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_POINTER** | The *ppCallInfo* parameter is not a valid pointer. |

## Remarks

TAPI calls the **AddRef** method on the
[ITCallInfo](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcallinfo) interface returned by **ITToneDetectionEvent::get_Call**. The application must call **Release** on the
**ITCallInfo** interface to free resources associated with it.

## See also

[ITCallInfo](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcallinfo)

[ITToneDetectionEvent](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-ittonedetectionevent)