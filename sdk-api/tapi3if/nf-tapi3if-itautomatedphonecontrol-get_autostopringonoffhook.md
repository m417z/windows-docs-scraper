# ITAutomatedPhoneControl::get_AutoStopRingOnOffHook

## Description

The
**get_AutoStopRingOnOffHook** method retrieves the current value of the **AutoStopRingOnOffHook** property. When this feature is enabled, the phone going offhook results in the termination of any incoming ring produced on the phone (via a call to
[ITAutomatedPhoneControl::StopRinger](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itautomatedphonecontrol-stopringer)).

## Parameters

### `pfEnabled` [out]

If VARIANT_TRUE, automatic incoming ring termination when the phone goes offhook is enabled. If VARIANT_FALSE, automatic incoming ring termination when the phone goes offhook is disabled.

## Return value

If the method succeeds, it returns S_OK. Otherwise, it returns an error value.

## Remarks

The **AutoStopRingOnOffHook** property functions only when the value of the **PhoneHandlingEnabled** property is VARIANT_TRUE. You can set the **AutoStopRingOnOffHook** property at any time. The reconfiguration takes effect the next time the phone goes offhook.

## See also

[ITAutomatedPhoneControl](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itautomatedphonecontrol)

[ITAutomatedPhoneControl::StopRinger](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itautomatedphonecontrol-stopringer)

[put_AutoStopRingOnOffHook](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itautomatedphonecontrol-put_autostopringonoffhook)

[put_PhoneHandlingEnabled](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itautomatedphonecontrol-put_phonehandlingenabled)