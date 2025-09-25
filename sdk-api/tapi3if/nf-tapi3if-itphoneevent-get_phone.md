# ITPhoneEvent::get_Phone

## Description

The
**get_Phone** method returns a pointer to the
[ITPhone](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itphone) interface on the phone object that fired this event.

## Parameters

### `ppPhone` [out]

Pointer to the
[ITPhone](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itphone) interface.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

TAPI calls the **AddRef** method on the
[ITPhone](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itphone) interface returned by **ITPhoneEvent::get_Phone**. The application must call **Release** on the
**ITPhone** interface to free resources associated with it.

## See also

[ITPhone](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itphone)

[ITPhoneEvent](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itphoneevent)