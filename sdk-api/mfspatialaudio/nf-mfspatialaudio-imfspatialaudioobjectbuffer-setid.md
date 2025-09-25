# IMFSpatialAudioObjectBuffer::SetID

## Description

Sets the ID of the spatial audio object represented by the buffer.

## Parameters

### `u32ID`

A 32-bit unsigned unique ID of the audio object.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

The object ID must be unique for each spatial audio sample. Subsequent samples can
contain spatial audio objects with the same IDs to represent moving dynamic objects or constant
static objects.

## See also

[IMFSpatialAudioObjectBuffer](https://learn.microsoft.com/windows/desktop/api/mfspatialaudio/nn-mfspatialaudio-imfspatialaudioobjectbuffer)