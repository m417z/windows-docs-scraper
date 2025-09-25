# ITAutomatedPhoneControl::put_AutoKeypadTonesMinimumDuration

## Description

The
**put_AutoKeypadTonesMinimumDuration** method sets the value of the **AutoKeypadTonesMinimumDuration** property. The property specifies how long to play keypad tones on PBS_DOWN.

## Parameters

### `lDuration` [in]

Minimum duration of keypad tones, in milliseconds (ms). The default value is 250 ms. If the minimum duration elapses without a PBS_UP event, the keypad tone continues until the PBS_UP event is received.

## Return value

If the method succeeds, it returns S_OK. Otherwise, it returns an error value.

## Remarks

The **AutoKeypadTonesMinimumDuration** property is valid only if the value of the **AutoKeypadTones** property is VARIANT_TRUE.

## See also

[ITAutomatedPhoneControl](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itautomatedphonecontrol)

[get_AutoKeypadTonesMinimumDuration](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itautomatedphonecontrol-get_autokeypadtonesminimumduration)

[put_AutoKeypadTones](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itautomatedphonecontrol-put_autokeypadtones)