# ITAutomatedPhoneControl::put_AutoVolumeControlRepeatDelay

## Description

The
**put_AutoVolumeControlRepeatDelay** method sets the **AutoVolumeControlRepeatDelay** property. The property specifies the delay, in milliseconds (ms), before a volume button starts repeating when it is held down.

## Parameters

### `lDelay` [in]

Delay, in milliseconds (ms), before the volume button starts repeating. The default value is 500 ms.

## Return value

If the method succeeds, it returns S_OK. Otherwise, it returns an error value.

## Remarks

The **AutoVolumeControlRepeatDelay** property is valid only if the value of the **AutoKeypadTones** property is VARIANT_TRUE.

## See also

[ITAutomatedPhoneControl](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itautomatedphonecontrol)

[get_AutoVolumeControlRepeatDelay](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itautomatedphonecontrol-get_autovolumecontrolrepeatdelay)

[put_AutoKeypadTones](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itautomatedphonecontrol-put_autokeypadtones)