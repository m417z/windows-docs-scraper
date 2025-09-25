# ITPhoneEvent::get_ButtonState

## Description

The
**get_ButtonState** method returns a
[PHONE_BUTTON_STATE](https://learn.microsoft.com/windows/desktop/api/tapi3if/ne-tapi3if-phone_button_state) value specifying the state to which the button has transitioned. This information is available only when the
[ITPhoneEvent::get_Event](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itphoneevent-get_event) method returns PE_BUTTON.

## Parameters

### `pState` [out]

Pointer to the
[PHONE_BUTTON_STATE](https://learn.microsoft.com/windows/desktop/api/tapi3if/ne-tapi3if-phone_button_state) descriptor of the button's current state.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method is available because some buttons do not support the PBS_DOWN button state, but instead momentarily report PBS_PRESSED. Additionally, the application can miss the button press on phones that do support PBS_DOWN if the button is pressed only for a short time and the call to the
[ITPhone::get_ButtonState](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itphone-get_buttonstate) method does not execute quickly enough.

## See also

[ITPhoneEvent](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itphoneevent)

[ITPhoneEvent::get_Event](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itphoneevent-get_event)