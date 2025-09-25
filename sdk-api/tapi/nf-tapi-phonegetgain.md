# phoneGetGain function

## Description

The
**phoneGetGain** function returns the gain setting of the microphone of the specified phone's hookswitch device.

## Parameters

### `hPhone`

Handle to the open phone device.

### `dwHookSwitchDev`

Hookswitch device whose gain level is queried. The *dwHookSwitchDev* parameter can have only one bit set. This parameter uses one and only one of the
[PHONEHOOKSWITCHDEV_ Constants](https://learn.microsoft.com/windows/desktop/Tapi/phonehookswitchdev--constants).

### `lpdwGain`

Pointer to a **DWORD** containing the current gain setting of the hookswitch microphone component. The *dwGain* parameter specifies the volume level of the hookswitch device. This is a number in the range 0x00000000 (silence) to 0x0000FFFF (maximum volume). The actual granularity and quantization of gain settings in this range are service provider-specific.

## Return value

Returns zero if the request succeeds or a negative error number if an error occurs. Possible return values are:

PHONEERR_INVALPHONEHANDLE, PHONEERR_NOMEM, PHONEERR_INVALPOINTER, PHONEERR_RESOURCEUNAVAIL, PHONEERR_INVALPHONESTATE, PHONEERR_OPERATIONFAILED, PHONEERR_INVALHOOKSWITCHDEV, PHONEERR_UNINITIALIZED, PHONEERR_OPERATIONUNAVAIL.

## See also

[Supplementary Phone Service Functions](https://learn.microsoft.com/windows/desktop/Tapi/supplementary-phone-service-functions)

[TAPI 2.2 Reference Overview](https://learn.microsoft.com/windows/desktop/Tapi/tapi-2-2-reference)