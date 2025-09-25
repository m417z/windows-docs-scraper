# ITCallMediaEvent::get_Stream

## Description

The
**get_Stream** method gets a pointer to the
[ITStream](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itstream) interface associated with the call media event.

## Parameters

### `ppStream` [out]

Pointer to
[ITStream](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itstream) interface pointer.

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |
| **E_POINTER** | The *ppStream* parameter is not a valid pointer. |

## Remarks

TAPI calls the **AddRef** method on the
[ITStream](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itstream) interface returned by **ITCallMediaEvent::get_Stream**. The application must call **Release** on
**ITStream** to free resources associated with it.

## See also

[Call Object](https://learn.microsoft.com/windows/desktop/Tapi/call-object)

[ITCallMediaEvent](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcallmediaevent)

[ITStream](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itstream)