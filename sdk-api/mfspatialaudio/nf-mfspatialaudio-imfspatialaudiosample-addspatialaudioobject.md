# IMFSpatialAudioSample::AddSpatialAudioObject

## Description

Adds a new spatial audio object, represented by an [IMFSpatialAudioObjectBuffer](https://learn.microsoft.com/windows/desktop/api/mfspatialaudio/nn-mfspatialaudio-imfspatialaudioobjectbuffer) object, to the sample.

## Parameters

### `pAudioObjBuffer` [in]

A pointer to the new IMFSpatialAudioObject.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | The supplied pointer is invalid. |

## See also

[IMFSpatialAudioSample](https://learn.microsoft.com/windows/desktop/api/mfspatialaudio/nn-mfspatialaudio-imfspatialaudiosample)