# ITAutomatedPhoneControl::get_AutoVolumeControl

## Description

The
**get_AutoVolumeControl** method retrieves the current value of the **AutoVolumeControl** property. When this feature is enabled, the phone's wave output volume is automatically adjusted whenever a volume button is pressed. The volume is adjusted by the amount indicated by the **AutoVolumeControlStep** property.

## Parameters

### `fEnabled` [out]

VARIANT_TRUE indicates that automatic volume control is enabled. VARIANT_FALSE indicates that automatic volume control is disabled.

## Return value

If the method succeeds, it returns S_OK. Otherwise, it returns an error value.

## Remarks

You can set the **AutoVolumeControl** property at any time. The reconfiguration takes effect the next time a volume button is pressed.

The **AutoVolumeControl** property functions only when the value of the **PhoneHandlingEnabled** property is VARIANT_TRUE.

## See also

[ITAutomatedPhoneControl](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itautomatedphonecontrol)

[put_AutoVolumeControl](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itautomatedphonecontrol-put_autovolumecontrol)

[put_AutoVolumeControlStep](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itautomatedphonecontrol-put_autovolumecontrolstep)

[put_PhoneHandlingEnabled](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itautomatedphonecontrol-put_phonehandlingenabled)