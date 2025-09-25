# IAudioEndpointOffloadStreamMute::SetMute

## Description

The **SetMute** method sets the mute status of the offloaded audio stream.

## Parameters

### `bMuted` [in]

Indicates whether or not the offloaded audio stream is to be muted. A value of **TRUE** mutes the stream, and a value of **FALSE** sets the stream to a non-muted state.

## Return value

The **SetMute** method returns **S_OK** to indicate that it has completed successfully. Otherwise it returns an appropriate error code.

## See also

[IAudioEndpointOffloadStreamMute](https://learn.microsoft.com/windows/desktop/api/audioengineendpoint/nn-audioengineendpoint-iaudioendpointoffloadstreammute)