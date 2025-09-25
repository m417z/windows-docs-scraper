# ITAutomatedPhoneControl::put_AutoVolumeControl

## Description

The
**put_AutoVolumeControl** method sets the **AutoVolumeControl** property for this phone. When this feature is enabled, the phone's wave output volume is automatically adjusted whenever a volume button is pressed. The volume is adjusted by the amount indicated by the **AutoVolumeControlStep** property.

## Parameters

### `fEnabled` [in]

If VARIANT_TRUE, enables automatic volume control. If VARIANT_FALSE, disables automatic volume control. The default value is VARIANT_TRUE.

## Return value

If the method succeeds, it returns S_OK. Otherwise, it returns an error value.

## Remarks

The **AutoVolumeControl** property functions only when the value of the **PhoneHandlingEnabled** property is VARIANT_TRUE. You can set the **AutoVolumeControl** property at any time. The reconfiguration takes effect the next time a volume button is pressed.

## See also

[ITAutomatedPhoneControl](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itautomatedphonecontrol)

[get_AutoVolumeControl](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itautomatedphonecontrol-get_autovolumecontrol)

[put_AutoVolumeControlStep](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itautomatedphonecontrol-put_autovolumecontrolstep)

[put_PhoneHandlingEnabled](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itautomatedphonecontrol-put_phonehandlingenabled)