# ITAutomatedPhoneControl::StartTone

## Description

The
**StartTone** method sends control tones.

## Parameters

### `Tone` [in]

[PHONE_TONE](https://learn.microsoft.com/windows/desktop/api/tapi3if/ne-tapi3if-phone_tone) descriptor of the type of tone to send, such as PT_KEYPADONE.

### `lDuration` [in]

Duration, in milliseconds, of the tone being sent.

## Return value

If the method succeeds, it returns S_OK. Otherwise, it returns an error value.

## See also

[ITAutomatedPhoneControl](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itautomatedphonecontrol)