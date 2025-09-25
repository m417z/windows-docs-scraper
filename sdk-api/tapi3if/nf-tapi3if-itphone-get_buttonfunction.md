# ITPhone::get_ButtonFunction

## Description

The
**get_ButtonFunction** method retrieves the button function associated with a particular button.

The application must call the
[ITPhone::Open](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itphone-open) method before invoking this method; otherwise, the method fails.

## Parameters

### `lButtonID` [in]

Button identifier.

### `pButtonFunction` [out]

The
[PHONE_BUTTON_FUNCTION](https://learn.microsoft.com/windows/desktop/api/tapi3if/ne-tapi3if-phone_button_function) descriptor for the button's function.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

See the description of the
[PHONE_BUTTON_FUNCTION](https://learn.microsoft.com/windows/desktop/api/tapi3if/ne-tapi3if-phone_button_function) enum for a list of possible button functions.

## See also

[ITPhone](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itphone)

[put_ButtonFunction](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itphone-put_buttonfunction)