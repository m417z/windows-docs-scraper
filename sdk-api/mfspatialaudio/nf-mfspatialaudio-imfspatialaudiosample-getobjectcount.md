# IMFSpatialAudioSample::GetObjectCount

## Description

Gets the count of spatial audio objects, represented by [IMFSpatialAudioObjectBuffer](https://learn.microsoft.com/windows/desktop/api/mfspatialaudio/nn-mfspatialaudio-imfspatialaudioobjectbuffer) objects, in the sample.

## Parameters

### `pdwObjectCount` [out]

A pointer to a 32 bit variable where the total number of audio objects in the sample will be stored.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | The supplied pointer is invalid. |

## See also

[IMFSpatialAudioSample](https://learn.microsoft.com/windows/desktop/api/mfspatialaudio/nn-mfspatialaudio-imfspatialaudiosample)