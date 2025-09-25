# ITAutomatedPhoneControl::get_PhoneHandlingEnabled

## Description

The
**get_PhoneHandlingEnabled** method retrieves the current value of the **PhoneHandlingEnabled** property. Setting the property enables or disables all the automatic phone interaction features for this phone. Features include automated control of a phone's tones and rings, and automated call handling based on a phone's hookswitch state.

## Parameters

### `pfEnabled` [out]

VARIANT_TRUE if automated phone handling is enabled, VARIANT_FALSE if automated phone handling is not enabled. The default value is VARIANT_FALSE.

## Return value

If the method succeeds, it returns S_OK. Otherwise, it returns an error value.

## Remarks

Typically, an application sets other properties on the
[ITAutomatedPhoneControl](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itautomatedphonecontrol) interface (to configure the details of the automatic phone interaction features required) before setting the **PhoneHandlingEnabled** property to VARIANT_TRUE. However, you can also adjust the properties after you call the
[put_PhoneHandlingEnabled](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itautomatedphonecontrol-put_phonehandlingenabled) method to enable the features.

When the phone is closed with a call to the
[ITPhone::Close](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itphone-close) method, the **PhoneHandlingEnabled** property is automatically reset to VARIANT_FALSE.

For a list of property methods that get and set the automatic phone interaction features, see
[ITAutomatedPhoneControl](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itautomatedphonecontrol).

## See also

[ITAutomatedPhoneControl](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itautomatedphonecontrol)

[ITPhone::Close](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itphone-close)

[put_PhoneHandlingEnabled](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itautomatedphonecontrol-put_phonehandlingenabled)