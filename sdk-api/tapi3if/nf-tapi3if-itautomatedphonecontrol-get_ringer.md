# ITAutomatedPhoneControl::get_Ringer

## Description

The
**get_Ringer** method returns a Boolean value indicating whether the phone is currently performing an incoming ring that was initiated by the
[StartRinger](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itautomatedphonecontrol-startringer) method on this interface.

## Parameters

### `pfRinging` [out]

If VARIANT_TRUE, the phone is currently ringing.

## Return value

If the method succeeds, it returns S_OK. Otherwise, it returns an error value.

## See also

[ITAutomatedPhoneControl](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itautomatedphonecontrol)

[StartRinger](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itautomatedphonecontrol-startringer)