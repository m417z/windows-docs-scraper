# ITAutomatedPhoneControl::get_AutoVolumeControlRepeatDelay

## Description

The
**get_AutoVolumeControlRepeatDelay** method retrieves the current value of the **AutoVolumeControlRepeatDelay** property. The property specifies the delay, in milliseconds (ms), before a volume button starts repeating when it is held down.

## Parameters

### `plDelay` [out]

Delay, in milliseconds, of the volume repeat delay. The default value is 500 ms.

## Return value

If the method succeeds, it returns S_OK. Otherwise, it returns an error value.

## Remarks

The **AutoVolumeControlRepeatDelay** property is valid only if the value of the **AutoKeypadTones** property is VARIANT_TRUE.

## See also

[ITAutomatedPhoneControl](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itautomatedphonecontrol)

[put_AutoKeypadTones](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itautomatedphonecontrol-put_autokeypadtones)

[put_AutoVolumeControlRepeatDelay](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itautomatedphonecontrol-put_autovolumecontrolrepeatdelay)