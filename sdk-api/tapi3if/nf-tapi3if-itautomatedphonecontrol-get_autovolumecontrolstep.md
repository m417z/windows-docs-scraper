# ITAutomatedPhoneControl::get_AutoVolumeControlStep

## Description

The
**get_AutoVolumeControlStep** method retrieves the current value of the **AutoVolumeControlStep** property. The property determines the amount that the phone volume is adjusted when the volume button is pressed.

## Parameters

### `plStepSize` [out]

Volume control step. The default value of the **AutoVolumeControlStep** property is 4096.

## Return value

If the method succeeds, it returns S_OK. Otherwise, it returns an error value.

## See also

[ITAutomatedPhoneControl](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itautomatedphonecontrol)

[put_AutoKeypadTones](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itautomatedphonecontrol-put_autokeypadtones)

[put_AutoVolumeControlStep](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itautomatedphonecontrol-put_autovolumecontrolstep)