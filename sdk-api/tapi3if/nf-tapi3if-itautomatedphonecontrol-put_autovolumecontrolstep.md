# ITAutomatedPhoneControl::put_AutoVolumeControlStep

## Description

The
**put_AutoVolumeControlStep** method sets the **AutoVolumeControlStep** property. The property determines the amount that the phone volume is adjusted when the volume button is pressed.

## Parameters

### `lStepSize` [in]

Volume control step, in milliseconds. The default value of the **AutoVolumeControlStep** property is 4096.

## Return value

If the method succeeds, it returns S_OK. Otherwise, it returns an error value.

## Remarks

The **AutoVolumeControlRepeatDelay** property is valid only if the value of the **AutoKeypadTones** property is VARIANT_TRUE.

## See also

[ITAutomatedPhoneControl](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itautomatedphonecontrol)

[get_AutoVolumeControlStep](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itautomatedphonecontrol-get_autovolumecontrolstep)

[put_AutoKeypadTones](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itautomatedphonecontrol-put_autokeypadtones)