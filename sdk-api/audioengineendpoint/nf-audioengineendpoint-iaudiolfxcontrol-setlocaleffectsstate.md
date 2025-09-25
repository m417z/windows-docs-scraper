# IAudioLfxControl::SetLocalEffectsState

## Description

The **SetLocalEffectsState** method sets the local effects state that is to be applied to the offloaded audio stream.

## Parameters

### `bEnabled` [in]

Indicates the local effects state that is to be applied to the offloaded audio stream. A value of **TRUE** enables local effects, and the local effects in the audio graph are applied to the stream. A value of **FALSE** disables local effects, so that the local effects in the audio graph are not applied to the audio stream.

## Return value

The **SetLocalEffectsState** method returns **S_OK** to indicate that it has completed successfully. Otherwise it returns an appropriate error code.

## See also

[IAudioLfxControl](https://learn.microsoft.com/windows/desktop/api/audioengineendpoint/nn-audioengineendpoint-iaudiolfxcontrol)