# IMFSpatialAudioSample::GetSpatialAudioObjectByIndex

## Description

Returns the spatial audio object, represented by an [IMFSpatialAudioObjectBuffer](https://learn.microsoft.com/windows/desktop/api/mfspatialaudio/nn-mfspatialaudio-imfspatialaudioobjectbuffer) object, corresponding to the specified index.

## Parameters

### `dwIndex`

A 32 bit variable with the 0-based index of the requested audio object.

### `ppAudioObjBuffer`

A pointer to an [IMFSpatialAudioObjectBuffer](https://learn.microsoft.com/windows/desktop/api/mfspatialaudio/nn-mfspatialaudio-imfspatialaudioobjectbuffer) object in which the spatial audio object corresponding with the specified index will be stored.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | The supplied pointer is invalid. |

## See also

[IMFSpatialAudioSample](https://learn.microsoft.com/windows/desktop/api/mfspatialaudio/nn-mfspatialaudio-imfspatialaudiosample)