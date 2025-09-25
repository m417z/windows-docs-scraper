# IMFSpatialAudioObjectBuffer::GetType

## Description

Gets the type of the spatial audio object represented by the buffer. If [SetType](https://learn.microsoft.com/windows/desktop/api/mfspatialaudio/nf-mfspatialaudio-imfspatialaudioobjectbuffer-settype) has not been called previously, this method returns the default value of **AudioObjectType_None**.

## Parameters

### `pType` [out]

A pointer to an [AudioObjectType](https://learn.microsoft.com/windows/desktop/api/spatialaudioclient/ne-spatialaudioclient-audioobjecttype) variable where the audio object type will be stored.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | The supplied pointer is invalid. |

## See also

[IMFSpatialAudioObjectBuffer](https://learn.microsoft.com/windows/desktop/api/mfspatialaudio/nn-mfspatialaudio-imfspatialaudioobjectbuffer)