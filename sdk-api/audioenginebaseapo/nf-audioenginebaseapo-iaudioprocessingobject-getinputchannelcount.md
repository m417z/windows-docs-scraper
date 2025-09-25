# IAudioProcessingObject::GetInputChannelCount

## Description

GetInputChannelCount returns the input channel count (samples-per-frame) for this APO.

## Parameters

### `pu32ChannelCount` [out]

The input channel count.

## Return value

`GetInputChannelCount` returns a value of S_OK if the call was successful.

## Remarks

The input channel count that is returned refers to the input side of the APO.

## See also

[IAudioProcessingObject](https://learn.microsoft.com/windows/desktop/api/audioenginebaseapo/nn-audioenginebaseapo-iaudioprocessingobject)