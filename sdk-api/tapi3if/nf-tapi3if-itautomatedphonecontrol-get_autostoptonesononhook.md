# ITAutomatedPhoneControl::get_AutoStopTonesOnOnHook

## Description

The
**get_AutoStopTonesOnOnHook** method retrieves the current value of the **AutoStopTonesOnOnHook** property. When this feature is enabled, the phone going onhook results in the termination of any tone produced on the audio render device associated with the phone (via a call to
[ITAutomatedPhoneControl::StopTone](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itautomatedphonecontrol-stoptone)).

## Parameters

### `pfEnabled` [out]

If VARIANT_TRUE, automatic stop of tone generation upon onhook is enabled. If VARIANT_FALSE, automatic stop of tone generation upon onhook is disabled.

## Return value

If the method succeeds, it returns S_OK. Otherwise, it returns an error value.

## Remarks

The **AutoStopTonesOnOnHook** property functions only when the value of the **PhoneHandlingEnabled** property is VARIANT_TRUE. You can set the **AutoStopTonesOnOnHook** property at any time. The reconfiguration takes effect the next time the phone goes onhook.

## See also

[ITAutomatedPhoneControl](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itautomatedphonecontrol)

[ITAutomatedPhoneControl::StopTone](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itautomatedphonecontrol-stoptone)

[put_AutoStopTonesOnOnHook](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itautomatedphonecontrol-put_autostoptonesononhook)

[put_PhoneHandlingEnabled](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itautomatedphonecontrol-put_phonehandlingenabled)