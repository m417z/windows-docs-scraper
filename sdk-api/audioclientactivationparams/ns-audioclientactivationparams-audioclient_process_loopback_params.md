## Description

Specifies parameters for a call to [ActivateAudioInterfaceAsync](https://learn.microsoft.com/windows/win32/api/mmdeviceapi/nf-mmdeviceapi-activateaudiointerfaceasync) where loopback activation is requested.

## Members

### `TargetProcessId`

The ID of the process for which the render streams, and the render streams of its child processes, will be included or excluded when activating the process loopback stream.

### `ProcessLoopbackMode`

A value from the [PROCESS_LOOPBACK_MODE](https://learn.microsoft.com/windows/win32/api/audioclientactivationparams/ne-audioclientactivationparams-process_loopback_mode) enumeration specifying whether the render streams for the process and child processes specified in the *TargetProcessId* field should be included or excluded when activating the audio interface. For sample code that demonstrates the process loopback capture scenario, see the [Application Loopback API Capture Sample](https://docs.microsoft.com/en-us/samples/microsoft/windows-classic-samples/applicationloopbackaudio-sample/).

## Remarks

## See also