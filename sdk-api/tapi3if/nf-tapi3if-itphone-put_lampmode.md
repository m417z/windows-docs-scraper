# ITPhone::put_LampMode

## Description

The
**put_LampMode** method sets the current lamp mode for the given lamp.

## Parameters

### `lLampID` [in]

Lamp identifier.

### `LampMode` [in]

The
[PHONE_LAMP_MODE](https://learn.microsoft.com/windows/desktop/api/tapi3if/ne-tapi3if-phone_lamp_mode) descriptor for the phone's lamp status.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ITPhone](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itphone)

[get_LampMode](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itphone-get_lampmode)