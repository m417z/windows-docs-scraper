# IMiniportWaveRTStream::GetPositionRegister

## Description

The GetPositionRegister method retrieves the information that the port driver requires to expose the position register to the audio subsystem and its clients.

## Parameters

### `Register`

Output pointer to a KSRTAUDIO_HWREGISTER structure that describes the register mapping.

## Return value

This method returns NTSTATUS which contains STATUS_SUCCESS if the call was successful. Otherwise, the function returns an appropriate error status code.

## Remarks

The WaveRT port driver calls this method in response to a KSPROPERTY_RTAUDIO_POSITIONREGISTER property request from a client.

## See also

[IMiniPortWaveRTStream](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iminiportwavertstream)