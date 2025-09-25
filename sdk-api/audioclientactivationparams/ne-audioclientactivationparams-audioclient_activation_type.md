## Description

Specifies the activation type for an [AUDIOCLIENT_ACTIVATION_PARAMS](https://learn.microsoft.com/windows/win32/api/audioclientactivationparams/ns-audioclientactivationparams-audioclient_activation_params) structure passed into a call to [ActivateAudioInterfaceAsync](https://learn.microsoft.com/windows/win32/api/mmdeviceapi/nf-mmdeviceapi-activateaudiointerfaceasync).

## Constants

### `AUDIOCLIENT_ACTIVATION_TYPE_DEFAULT`

Default activation.

### `AUDIOCLIENT_ACTIVATION_TYPE_PROCESS_LOOPBACK`

Process loopback activation, allowing for the inclusion or exclusion of audio rendered by the specified process and its child processes. For sample code that demonstrates the process loopback capture scenario, see the [Application Loopback API Capture Sample](https://docs.microsoft.com/en-us/samples/microsoft/windows-classic-samples/applicationloopbackaudio-sample/).

## Remarks

## See also

[AUDIOCLIENT_ACTIVATION_PARAMS](https://learn.microsoft.com/windows/win32/api/audioclientactivationparams/ns-audioclientactivationparams-audioclient_activation_params)

[ActivateAudioInterfaceAsync](https://learn.microsoft.com/windows/win32/api/mmdeviceapi/nf-mmdeviceapi-activateaudiointerfaceasync)