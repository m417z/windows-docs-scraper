# ITPhone::get_ButtonState

## Description

The
**get_ButtonState** method retrieves the button state associated with a particular button.

The application must call the
[ITPhone::Open](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itphone-open) method before invoking this method; otherwise, the invocation fails.

## Parameters

### `lButtonID` [in]

Button identifier.

### `pButtonState` [out]

The
[PHONE_BUTTON_STATE](https://learn.microsoft.com/windows/desktop/api/tapi3if/ne-tapi3if-phone_button_state) descriptor for the button's state.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ITPhone](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itphone)

[ITPhoneEvent::get_ButtonState](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itphoneevent-get_buttonstate)