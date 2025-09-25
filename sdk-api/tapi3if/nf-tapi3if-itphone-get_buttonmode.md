# ITPhone::get_ButtonMode

## Description

The
**get_ButtonMode** method retrieves the button mode associated with a particular button.

The application must call
[ITPhone::Open](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itphone-open) before invoking this method; otherwise, the invocation fails.

## Parameters

### `lButtonID` [in]

Button identifier. For more information, see the following Remarks section.

### `pButtonMode` [out]

The
[PHONE_BUTTON_MODE](https://learn.microsoft.com/windows/desktop/api/tapi3if/ne-tapi3if-phone_button_mode) descriptor for the button's mode.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

See the description of the
[PHONE_BUTTON_MODE](https://learn.microsoft.com/windows/desktop/api/tapi3if/ne-tapi3if-phone_button_mode) enum and the TAPI 2.*x* documentation for more information about button modes.

The two following
[PHONE_BUTTON_MODE](https://learn.microsoft.com/windows/desktop/api/tapi3if/ne-tapi3if-phone_button_mode) values are of particular interest:

1. If the
   [PHONE_BUTTON_MODE](https://learn.microsoft.com/windows/desktop/api/tapi3if/ne-tapi3if-phone_button_mode) value is PBM_FEATURE, the application should call the
   [get_ButtonFunction](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itphone-get_buttonfunction) to retrieve the specific meaning of the button.
2. If the
   [PHONE_BUTTON_MODE](https://learn.microsoft.com/windows/desktop/api/tapi3if/ne-tapi3if-phone_button_mode) value is PBM_KEYPAD, the button is a keypad button whose value is indicated by the value of the *lButtonID* parameter. For example, if *lButtonID* == 10 then the button is the * (star) key on the keypad.

## See also

[ITPhone](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itphone)

[get_ButtonFunction](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itphone-get_buttonfunction)

[put_ButtonMode](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itphone-put_buttonmode)