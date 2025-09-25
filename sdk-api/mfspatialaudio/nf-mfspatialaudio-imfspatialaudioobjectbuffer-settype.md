# IMFSpatialAudioObjectBuffer::SetType

## Description

Sets the type of the spatial audio object represented by the buffer.

## Parameters

### `type`

A value from the [AudioObjectType](https://learn.microsoft.com/windows/desktop/api/spatialaudioclient/ne-spatialaudioclient-audioobjecttype) enumeration specifying the type of audio object.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

A spatial audio object can be of type **AudioObjectType_Dynamic**, which means that it can change position and orientation in 3D space over time, or it can have a value such as **AudioObjectType_FrontLeft** which represents the static position of a real or virtual speaker that does not change position over time.

## See also

[IMFSpatialAudioObjectBuffer](https://learn.microsoft.com/windows/desktop/api/mfspatialaudio/nn-mfspatialaudio-imfspatialaudioobjectbuffer)