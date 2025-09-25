# ITAutomatedPhoneControl::put_AutoDialtone

## Description

The
**put_AutoDialtone** method sets the value of the **AutoDialtone** property. The method enables or disables automatic dial tone response for this phone. When this feature is enabled, the phone going offhook results in a dial tone produced on the audio render device associated with the phone. No dial tone is produced if the phone was ringing when it went offhook.

## Parameters

### `fEnabled` [in]

If VARIANT_TRUE, enables automatic dial tone. If VARIANT_FALSE, disables automatic dial tone. The default value is VARIANT_TRUE.

## Return value

If the method succeeds, it returns S_OK. Otherwise, it returns an error value.

## Remarks

The **AutoDialtone** property functions only when the value of the **PhoneHandlingEnabled** property is VARIANT_TRUE. You can set the **AutoDialtone** property at any time. The reconfiguration takes effect the next time the phone goes offhook.

All dial tone generation ceases when an invocation of
[ITAutomatedPhoneControl::SelectCall](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itautomatedphonecontrol-selectcall) succeeds; dial tone generation remains suspended until the call is unselected.

## See also

[ITAutomatedPhoneControl](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itautomatedphonecontrol)

[ITAutomatedPhoneControl::SelectCall](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itautomatedphonecontrol-selectcall)

[get_AutoDialtone](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itautomatedphonecontrol-get_autodialtone)

[put_PhoneHandlingEnabled](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itautomatedphonecontrol-put_phonehandlingenabled)