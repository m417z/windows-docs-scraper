# ITAutomatedPhoneControl::get_Tone

## Description

The
**get_Tone** method returns a
[PHONE_TONE](https://learn.microsoft.com/windows/desktop/api/tapi3if/ne-tapi3if-phone_tone) enum value indicating the type of tone, if any, that the phone is currently playing. If no tone is currently being played, the
**PHONE_TONE** value returned is PT_SILENCE. This method has knowledge only of tones initiated by the
[StartTone](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itautomatedphonecontrol-starttone) method on this interface.

## Parameters

### `pTone` [out]

[PHONE_TONE](https://learn.microsoft.com/windows/desktop/api/tapi3if/ne-tapi3if-phone_tone) descriptor of tone being played.

## Return value

If the method succeeds, it returns S_OK. Otherwise, it returns an error value.

## See also

[ITAutomatedPhoneControl](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itautomatedphonecontrol)

[StartTone](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itautomatedphonecontrol-starttone)