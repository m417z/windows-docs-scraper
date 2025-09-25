# phoneSetGain function

## Description

The
**phoneSetGain** function sets the gain of the microphone of the specified hookswitch device to the specified gain level.

## Parameters

### `hPhone`

Handle to the open phone device. The application must be the owner of the phone.

### `dwHookSwitchDev`

Hookswitch device whose microphone's gain is to be set. This parameter uses one and only one of the
[PHONEHOOKSWITCHDEV_ Constants](https://learn.microsoft.com/windows/desktop/Tapi/phonehookswitchdev--constants).

### `dwGain`

Pointer to a **DWORD** containing the new gain setting of the device. The *dwGain* parameter specifies the gain level of the hookswitch device. This is a number in the range 0x00000000 (silence) to 0x0000FFFF (maximum volume). The actual granularity and quantization of gain settings in this range are service provider-specific. A value for *dwGain* that is out of range is set to the nearest value in the range.

## Return value

Returns a positive request identifier if the function is completed asynchronously or a negative error number if an error occurs. The *dwParam2* parameter of the corresponding [PHONE_REPLY](https://learn.microsoft.com/windows/desktop/Tapi/phone-reply) message is zero if the function succeeds or it is a negative error number if an error occurs. Possible return values are:

PHONEERR_INVALPHONEHANDLE, PHONEERR_NOMEM, PHONEERR_NOTOWNER, PHONEERR_RESOURCEUNAVAIL, PHONEERR_INVALPHONESTATE, PHONEERR_OPERATIONFAILED, PHONEERR_INVALHOOKSWITCHDEV, PHONEERR_UNINITIALIZED, PHONEERR_OPERATIONUNAVAIL.

## See also

[PHONE_REPLY](https://learn.microsoft.com/windows/desktop/Tapi/phone-reply)

[Supplementary Phone Service Functions](https://learn.microsoft.com/windows/desktop/Tapi/supplementary-phone-service-functions)

[TAPI 2.2 Reference Overview](https://learn.microsoft.com/windows/desktop/Tapi/tapi-2-2-reference)