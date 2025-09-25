# IAudioEndpointOffloadStreamMute::GetMute

## Description

The **GetMute** method retrieves the mute status of the offloaded audio stream.

## Parameters

### `pbMuted` [out]

Indicates whether or not the offloaded audio stream is muted. A value of **TRUE** indicates that the stream is muted, and a value of **FALSE** indicates that the stream is not muted.

## Return value

The **GetMute** method returns **S_OK** to indicate that it has completed successfully. Otherwise it returns an appropriate error code.

## See also

[IAudioEndpointOffloadStreamMute](https://learn.microsoft.com/windows/desktop/api/audioengineendpoint/nn-audioengineendpoint-iaudioendpointoffloadstreammute)