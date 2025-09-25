# phoneSetRing function

## Description

The
**phoneSetRing** function rings the specified open phone device using the specified ring mode and volume.

## Parameters

### `hPhone`

Handle to the open phone device. The application must be the owner of the phone device.

### `dwRingMode`

Ringing pattern with which to ring the phone. This parameter must be within the range of zero to the value of the **dwNumRingModes** member in the
[PHONECAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-phonecaps) structure. If **dwNumRingModes** is zero, the ring mode of the phone cannot be controlled; if **dwNumRingModes** is 1, a value of 0 for *dwRingMode* indicates that the phone should not be rung (silence), and other values from 1 to **dwNumRingModes** are valid ring modes for the phone device.

### `dwVolume`

Volume level with which the phone is ringing. This is a number in the range 0x00000000 (silence) to 0x0000FFFF (maximum volume). The actual granularity and quantization of volume settings in this range are service provider-specific. A value for *dwVolume* that is out of range is set to the nearest value in the range.

## Return value

Returns a positive request identifier if the function is completed asynchronously or a negative error number if an error occurs. The *dwParam2* parameter of the corresponding
[PHONE_REPLY](https://learn.microsoft.com/windows/desktop/Tapi/phone-reply) message is zero if the function succeeds or it is a negative error number if an error occurs. Possible return values are:

PHONEERR_INVALPHONEHANDLE, PHONEERR_NOMEM, PHONEERR_NOTOWNER, PHONEERR_RESOURCEUNAVAIL, PHONEERR_INVALPHONESTATE, PHONEERR_OPERATIONFAILED, PHONEERR_INVALRINGMODE, PHONEERR_UNINITIALIZED, PHONEERR_OPERATIONUNAVAIL.

## Remarks

The service provider defines the actual audible ringing patterns corresponding to each of the phone's ring modes.

## See also

[PHONECAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-phonecaps)

[PHONE_REPLY](https://learn.microsoft.com/windows/desktop/Tapi/phone-reply)

[Supplementary Phone Service Functions](https://learn.microsoft.com/windows/desktop/Tapi/supplementary-phone-service-functions)

[TAPI 2.2 Reference Overview](https://learn.microsoft.com/windows/desktop/Tapi/tapi-2-2-reference)