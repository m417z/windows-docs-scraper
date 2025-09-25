# IMiniportWaveRTStream::GetClockRegister

## Description

The GetClockRegister method retrieves the information that the port driver requires to expose the clock register to the audio subsystem and its clients.

## Parameters

### `Register`

Output pointer to a KSRTAUDIO_HWREGISTER structure that describes the register mapping.

## Return value

This method returns NTSTATUS which contains a status value of STATUS_SUCCESS if the call was successful. Otherwise, the method returns an appropriate error status code.

## Remarks

The port driver calls this method in response to a KSPROPERTY_RTAUDIO_CLOCKREGISTER property request from a client.

A clock register is a counter that increments at the frequency of the internal hardware clock that drives the internal bus of the audio device.The register increments by one with each tick of the clock. The register begins counting when the device powers on, and it continues to run until the device powers off. The clock register is used by software to synchronize two or more devices with independent hardware clocks.

## See also

[IMiniPortWaveRTStream](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iminiportwavertstream)