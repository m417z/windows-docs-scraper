# ITAutomatedPhoneControl::get_AutoKeypadTones

## Description

The
**get_AutoKeypadTones** method gets the **AutoKeypadTones** property for this phone. When this feature is enabled, a digit tone is automatically played whenever a keypad button is pressed.

## Parameters

### `pfEnabled` [out]

VARIANT_TRUE if automatic phone keypad feedback tone generation is enabled for this phone. VARIANT_FALSE if automatic phone keypad feedback tone generation is disabled for this phone.

## Return value

If the method succeeds, it returns S_OK. Otherwise, it returns an error value.

## Remarks

If the phone device reports a button press as PBS_DOWN, then the tone is played until the phone device reports a PBS_UP event or until the minimum duration has expired, whichever is longer. (The minimum duration is determined by the **AutoKeypadTonesMinimumDuration** property.)

Keypad tone generation will occur only when the phone is offhook. If another tone, such as ringback, is currently playing, the keypad tone will interrupt that tone and automatically restore it after the keypad tone has finished.

The **AutoKeypadTones** property functions only when the value of the **PhoneHandlingEnabled** property is VARIANT_TRUE. You can set the **AutoKeypadTones** property at any time. The reconfiguration takes effect the next time the phone keypad button is pressed.

## See also

[ITAutomatedPhoneControl](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itautomatedphonecontrol)

[put_AutoKeypadTones](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itautomatedphonecontrol-put_autokeypadtones)

[put_AutoKeypadTonesMinimumDuration](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itautomatedphonecontrol-put_autokeypadtonesminimumduration)

[put_PhoneHandlingEnabled](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itautomatedphonecontrol-put_phonehandlingenabled)