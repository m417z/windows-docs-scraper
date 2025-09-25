# phoneSetHookSwitch function

## Description

The
**phoneSetHookSwitch** function sets the hook state of the specified open phone's hookswitch devices to the specified mode. Only the hookswitch state of the hookswitch devices listed is affected.

## Parameters

### `hPhone`

Handle to the open phone device. The application must be the owner of the phone.

### `dwHookSwitchDevs`

Device whose hookswitch mode is to be set. This parameter uses one and only one of the
[PHONEHOOKSWITCHDEV_ Constants](https://learn.microsoft.com/windows/desktop/Tapi/phonehookswitchdev--constants).

#### PHONEHOOKSWITCHDEV_HANDSET

The phone's handset.

#### PHONEHOOKSWITCHDEV_SPEAKER

The phone's speakerphone or adjunct.

#### PHONEHOOKSWITCHDEV_HEADSET

The phone's headset.

### `dwHookSwitchMode`

Hookswitch mode to set. This parameter uses one and only one of the
[PHONEHOOKSWITCHMODE_ Constants](https://learn.microsoft.com/windows/desktop/Tapi/phonehookswitchmode--constants).

#### PHONEHOOKSWITCHMODE_ONHOOK

The device's microphone and speaker are both onhook.

#### PHONEHOOKSWITCHMODE_MIC

The device's microphone is active, the speaker is mute.

#### PHONEHOOKSWITCHMODE_SPEAKER

The device's speaker is active, the microphone is mute.

#### PHONEHOOKSWITCHMODE_MICSPEAKER

The device's microphone and speaker are both active.

## Return value

Returns a positive request identifier if the function is completed asynchronously or a negative error number if an error occurs. The *dwParam2* parameter of the corresponding
[PHONE_REPLY](https://learn.microsoft.com/windows/desktop/Tapi/phone-reply) message is zero if the function succeeds or it is a negative error number if an error occurs. Possible return values are:

PHONEERR_INVALPHONEHANDLE, PHONEERR_OPERATIONUNAVAIL, PHONEERR_NOTOWNER, PHONEERR_NOMEM, PHONEERR_INVALHOOKSWITCHDEV, PHONEERR_RESOURCEUNAVAIL, PHONEERR_INVALHOOKSWITCHMODE, PHONEERR_OPERATIONFAILED, PHONEERR_INVALPHONESTATE, PHONEERR_UNINITIALIZED.

## Remarks

The hookswitch mode is the same for all specified devices. If different settings are desired, this function can be invoked multiple times with a different set of parameters. A
[PHONE_STATE](https://learn.microsoft.com/windows/desktop/Tapi/phone-state) message is sent to the application after the hookswitch state has changed.

## See also

[PHONE_REPLY](https://learn.microsoft.com/windows/desktop/Tapi/phone-reply)

[PHONE_STATE](https://learn.microsoft.com/windows/desktop/Tapi/phone-state)

[Supplementary Phone Service Functions](https://learn.microsoft.com/windows/desktop/Tapi/supplementary-phone-service-functions)

[TAPI 2.2 Reference Overview](https://learn.microsoft.com/windows/desktop/Tapi/tapi-2-2-reference)