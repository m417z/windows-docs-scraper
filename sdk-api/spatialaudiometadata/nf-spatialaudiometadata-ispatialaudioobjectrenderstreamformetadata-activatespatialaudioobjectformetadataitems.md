# ISpatialAudioObjectRenderStreamForMetadata::ActivateSpatialAudioObjectForMetadataItems

## Description

Activate an [ISpatialAudioObjectForMetadataItems](https://learn.microsoft.com/windows/desktop/api/spatialaudiometadata/nn-spatialaudiometadata-ispatialaudioobjectformetadataitems) for rendering.

## Parameters

### `type` [in]

The type of audio object to activate. For dynamic audio objects, this value must be **AudioObjectType_Dynamic**. For static audio objects, specify one of the static audio channel values from the enumeration. Specifying **AudioObjectType_None** will produce an audio object that is not spatialized.

### `audioObject` [out]

Receives a pointer to the activated interface.

## Return value

If the method succeeds, it returns S_OK. If it fails, possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **SPTLAUDCLNT_E_NO_MORE_OBJECTS** | The maximum number of simultaneous spatial audio objects has been exceeded. Call [Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) on unused audio objects before attempting to activate additional objects. |
| **SPTLAUDCLNT_E_STATIC_OBJECT_NOT_AVAILABLE** | The static channel specified in the *type* parameter was not included in the **StaticObjectTypeMask** field of the [SpatialAudioObjectRenderStreamForMetadataActivationParams](https://learn.microsoft.com/windows/desktop/api/spatialaudiometadata/ns-spatialaudiometadata-spatialaudioobjectrenderstreamformetadataactivationparams) passed into [ISpatialAudioClient::ActivateSpatialAudioStream](https://learn.microsoft.com/windows/desktop/api/spatialaudioclient/nf-spatialaudioclient-ispatialaudioclient-activatespatialaudiostream). |
| **SPTLAUDCLNT_E_OBJECT_ALREADY_ACTIVE** | A spatial audio object has already been activated for the static channel specified in the *type* parameter. |
| **E_POINTER** | The supplied pointer is invalid. |
| **E_INVALIDARG** | The value specified in the *type* parameter is not one of the values defined by the [AudioObjectType](https://learn.microsoft.com/windows/desktop/api/spatialaudioclient/ne-spatialaudioclient-audioobjecttype) enumeration. |
| **SPTLAUDCLNT_E_DESTROYED** | The [ISpatialAudioClient](https://learn.microsoft.com/windows/win32/api/spatialaudioclient/nn-spatialaudioclient-ispatialaudioclient) associated with the spatial audio stream has been destroyed. |
| **AUDCLNT_E_DEVICE_INVALIDATED** | The audio endpoint device has been unplugged, or the audio hardware or associated hardware resources have been reconfigured, disabled, removed, or otherwise made unavailable for use. |
| **SPTLAUDCLNT_E_INTERNAL** | An internal error has occurred. |
| **AUDCLNT_E_UNSUPPORTED_FORMAT** | The media associated with the spatial audio stream uses an unsupported format. |

## Remarks

A dynamic [ISpatialAudioObjectForMetadataItems](https://learn.microsoft.com/windows/desktop/api/spatialaudiometadata/nn-spatialaudiometadata-ispatialaudioobjectformetadataitems) is one that was activated by setting the *type* parameter to the **ActivateSpatialAudioObjectForMetadataItems** method to **AudioObjectType_Dynamic**. The client has a limit of the maximum number of dynamic spatial audio objects that can be activated at one time. After the limit has been reached, attempting to activate additional audio objects will result in this method returning an SPTLAUDCLNT_E_NO_MORE_OBJECTS error. To avoid this, call [Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) on each dynamic **ISpatialAudioObjectForMetadataItems** after it is no longer being used to free up the resource so that it can be reallocated. See [ISpatialAudioObjectBase::IsActive](https://learn.microsoft.com/windows/desktop/api/spatialaudioclient/nf-spatialaudioclient-ispatialaudioobjectbase-isactive) and [ISpatialAudioObjectBase::SetEndOfStream](https://learn.microsoft.com/windows/desktop/api/spatialaudioclient/nf-spatialaudioclient-ispatialaudioobjectbase-setendofstream) for more information on the managing the lifetime of spatial audio objects.

## See also

[ISpatialAudioObjectForMetadataItems](https://learn.microsoft.com/windows/desktop/api/spatialaudiometadata/nn-spatialaudiometadata-ispatialaudioobjectformetadataitems)