# IAudioLfxControl::GetLocalEffectsState

## Description

The **GetLocalEffectsState** method retrieves the local effects state that is currently applied to the offloaded audio stream.

## Parameters

### `pbEnabled` [out]

A pointer to the Boolean variable that indicates the state of the local effects that have been applied to the offloaded audio stream. A value of **TRUE** indicates that local effects have been enabled and applied to the stream. A value of **FALSE** indicates that local effects have been disabled.

## Return value

The **GetLocalEffectsState** method returns **S_OK** to indicate that it has completed successfully. Otherwise it returns an appropriate error code.

## See also

[IAudioLfxControl](https://learn.microsoft.com/windows/desktop/api/audioengineendpoint/nn-audioengineendpoint-iaudiolfxcontrol)