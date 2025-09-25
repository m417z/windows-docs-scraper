# ITAutomatedPhoneControl::get_AutoDialtone

## Description

The
**get_AutoDialtone** method retrieves the current value of the **AutoDialtone** property. When this feature is enabled, the phone going offhook results in a dial tone produced on the audio render device associated with the phone. No dial tone is produced if the phone was ringing when it went offhook.

## Parameters

### `pfEnabled` [out]

If VARIANT_TRUE, auto dial tone is enabled. If VARIANT_FALSE, auto dial tone is disabled.

## Return value

If the method succeeds, it returns S_OK. Otherwise, it returns an error value.

## Remarks

The **AutoDialtone** property functions only when the value of the **PhoneHandlingEnabled** property is VARIANT_TRUE. You can set the **AutoDialtone** property at any time. The reconfiguration takes effect the next time the phone goes offhook.

All dial tone generation ceases when an invocation of
[ITAutomatedPhoneControl::SelectCall](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itautomatedphonecontrol-selectcall) succeeds; dial tone generation remains suspended until the call is unselected.

## See also

[ITAutomatedPhoneControl](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itautomatedphonecontrol)

[ITAutomatedPhoneControl::SelectCall](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itautomatedphonecontrol-selectcall)

[put_AutoDialtone](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itautomatedphonecontrol-put_autodialtone)

[put_PhoneHandlingEnabled](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itautomatedphonecontrol-put_phonehandlingenabled)