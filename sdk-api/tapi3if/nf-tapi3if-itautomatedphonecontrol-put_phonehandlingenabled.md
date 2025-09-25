# ITAutomatedPhoneControl::put_PhoneHandlingEnabled

## Description

The
**put_PhoneHandlingEnabled** method sets the **PhoneHandlingEnabled** property. Setting the property enables or disables all the automatic phone interaction features for this phone. Features include automated control of a phone's tones and rings, and automated call handling based on a phone's hookswitch state.

## Parameters

### `fEnabled` [in]

If VARIANT_TRUE, phone handling is enabled. If VARIANT_FALSE, phone handling is disabled. The default value is VARIANT_FALSE.

## Return value

If the method succeeds, it returns S_OK. Otherwise, it returns an error value.

## Remarks

Typically, an application sets other properties on the
[ITAutomatedPhoneControl](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itautomatedphonecontrol) interface (to configure the details of the automatic phone interaction features required) before setting the **PhoneHandlingEnabled** property to VARIANT_TRUE. However, you can also adjust the properties after you call the
**put_PhoneHandlingEnabled** method to enable the features.

When the phone is closed with a call to the
[ITPhone::Close](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itphone-close) method, the **PhoneHandlingEnabled** property is automatically reset to VARIANT_FALSE.

If you set the **PhoneHandlingEnabled** property to VARIANT_TRUE, and the phone doesn't have a ringer device, the ringing sound plays on the default audio device for the system; for example, on sound card speakers. For more information, see
[PHONECAPS_LONG](https://learn.microsoft.com/windows/desktop/api/tapi3if/ne-tapi3if-phonecaps_long).

For a list of property methods that get and set the automatic phone interaction features, see
[ITAutomatedPhoneControl](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itautomatedphonecontrol).

## See also

[ITAutomatedPhoneControl](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itautomatedphonecontrol)

[ITPhone::Close](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itphone-close)

[get_PhoneHandlingEnabled](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itautomatedphonecontrol-get_phonehandlingenabled)