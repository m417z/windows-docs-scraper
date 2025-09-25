# IAudioEndpointOffloadStreamMeter::GetMeteringData

## Description

The **GetMeteringData** method retrieves general information about the available audio channels in the offloaded stream.

## Parameters

### `u32ChannelCount` [in]

Indicates the number of available audio channels in the offloaded audio stream.

### `pf32PeakValues` [out]

A pointer to the peak values for the audio channels in the offloaded audio stream.

## Return value

The **GetMeteringData** method returns **S_OK** to indicate that it has completed successfully. Otherwise it returns an appropriate error code.

## See also

[IAudioEndpointOffloadStreamMeter](https://learn.microsoft.com/windows/desktop/api/audioengineendpoint/nn-audioengineendpoint-iaudioendpointoffloadstreammeter)