# ITAutomatedPhoneControl::put_AutoVolumeControlRepeatPeriod

## Description

The
**put_AutoVolumeControlRepeatPeriod** method sets the **AutoVolumeControlRepeatPeriod** property. The property controls the period, in milliseconds (ms), of button repeats when a volume button is held down.

## Parameters

### `lPeriod` [in]

Period, in milliseconds (ms), of button repeats when a volume button is held down. The default value is 100 ms.

## Return value

If the method succeeds, it returns S_OK. Otherwise, it returns an error value.

## Remarks

The **AutoVolumeControlRepeatDelay** property is valid only if the value of the **AutoKeypadTones** property is VARIANT_TRUE.

## See also

[ITAutomatedPhoneControl](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itautomatedphonecontrol)

[get_AutoVolumeControlRepeatPeriod](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itautomatedphonecontrol-get_autovolumecontrolrepeatperiod)

[put_AutoKeypadTones](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itautomatedphonecontrol-put_autokeypadtones)