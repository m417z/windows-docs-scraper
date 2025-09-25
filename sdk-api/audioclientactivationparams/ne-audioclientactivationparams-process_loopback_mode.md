## Description

Specifies the loopback mode for an [AUDIOCLIENT_ACTIVATION_PARAMS](https://learn.microsoft.com/windows/win32/api/audioclientactivationparams/ns-audioclientactivationparams-audioclient_activation_params) structure passed into a call to [ActivateAudioInterfaceAsync](https://learn.microsoft.com/windows/win32/api/mmdeviceapi/nf-mmdeviceapi-activateaudiointerfaceasync).

## Constants

### `PROCESS_LOOPBACK_MODE_INCLUDE_TARGET_PROCESS_TREE`

Render streams from the specified process and its child processes are included in the activated process loopback stream.

### `PROCESS_LOOPBACK_MODE_EXCLUDE_TARGET_PROCESS_TREE`

Render streams from the specified process and its child processes are excluded from the activated process loopback stream.

## Remarks

## See also

[AUDIOCLIENT_ACTIVATION_PARAMS](https://learn.microsoft.com/windows/win32/api/audioclientactivationparams/ns-audioclientactivationparams-audioclient_activation_params)
[ActivateAudioInterfaceAsync](https://learn.microsoft.com/windows/win32/api/mmdeviceapi/nf-mmdeviceapi-activateaudiointerfaceasync)