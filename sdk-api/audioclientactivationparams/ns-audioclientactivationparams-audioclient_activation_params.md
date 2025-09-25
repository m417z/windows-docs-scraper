## Description

Specifies the activation parameters for a call to [ActivateAudioInterfaceAsync](https://learn.microsoft.com/windows/win32/api/mmdeviceapi/nf-mmdeviceapi-activateaudiointerfaceasync).

## Members

### `ActivationType`

A member of the [AUDIOCLIENT_ACTIVATION_TYPE](https://learn.microsoft.com/windows/win32/api/audioclientactivationparams/ne-audioclientactivationparams-audioclient_activation_type) specifying the type of audio interface activation. Currently default activation and loopback activation are supported.

### `DUMMYUNIONNAME`

### `DUMMYUNIONNAME.ProcessLoopbackParams`

A [AUDIOCLIENT_PROCESS_LOOPBACK_PARAMS](https://learn.microsoft.com/windows/win32/api/audioclientactivationparams/ns-audioclientactivationparams-audioclient_process_loopback_params) specifying the loopback parameters for the audio interface activation.

## Remarks

## See also

[AUDIOCLIENT_ACTIVATION_TYPE](https://learn.microsoft.com/windows/win32/api/audioclientactivationparams/ne-audioclientactivationparams-audioclient_activation_type)

[ActivateAudioInterfaceAsync](https://learn.microsoft.com/windows/win32/api/mmdeviceapi/nf-mmdeviceapi-activateaudiointerfaceasync)