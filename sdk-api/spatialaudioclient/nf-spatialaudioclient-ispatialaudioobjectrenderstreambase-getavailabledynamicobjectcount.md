# ISpatialAudioObjectRenderStreamBase::GetAvailableDynamicObjectCount

## Description

Gets the number of dynamic spatial audio objects that are currently available.

## Parameters

### `value` [out]

The number of dynamic spatial audio objects that are currently available.

## Return value

If the method succeeds, it returns S_OK. If it fails, possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| **SPTLAUDCLNT_E_DESTROYED** | The [ISpatialAudioClient](https://learn.microsoft.com/windows/win32/api/spatialaudioclient/nn-spatialaudioclient-ispatialaudioclient) associated with the spatial audio stream has been destroyed. |
| **AUDCLNT_E_DEVICE_INVALIDATED** | The audio device associated with the spatial audio stream is no longer valid. |
| **AUDCLNT_E_DEVICE_INVALIDATED** | The audio endpoint device has been unplugged, or the audio hardware or associated hardware resources have been reconfigured, disabled, removed, or otherwise made unavailable for use. |
| **SPTLAUDCLNT_E_INTERNAL** | An internal error has occurred. |
| **AUDCLNT_E_UNSUPPORTED_FORMAT** | **The media associated with the spatial audio stream uses an unsupported format.** |

## Remarks

A dynamic [ISpatialAudioObject](https://learn.microsoft.com/windows/desktop/api/spatialaudioclient/nn-spatialaudioclient-ispatialaudioobject) is one that was activated by setting the *type* parameter to the [ActivateSpatialAudioObject](https://learn.microsoft.com/windows/desktop/api/spatialaudioclient/nf-spatialaudioclient-ispatialaudioobjectrenderstream-activatespatialaudioobject) method to **AudioObjectType_Dynamic**. The system has a limit of the maximum number of dynamic spatial audio objects that can be activated at one time. Call [Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) on an **ISpatialAudioObject** when it is no longer being used to free up the resource to create new dynamic spatial audio objects.

You should not call this method after streaming has started, as the value is already provided by [ISpatialAudioObjectRenderStreamBase::BeginUpdatingAudioObjects](https://learn.microsoft.com/windows/win32/api/spatialaudioclient/nf-spatialaudioclient-ispatialaudioobjectrenderstreambase-beginupdatingaudioobjects). This method should only be called before streaming has started, which occurs after [ISpatialAudioObjectRenderStreamBase::Start](https://learn.microsoft.com/windows/win32/api/spatialaudioclient/nf-spatialaudioclient-ispatialaudioobjectrenderstreambase-start) is called.

## See also

[ISpatialAudioObjectRenderStream](https://learn.microsoft.com/windows/desktop/api/spatialaudioclient/nn-spatialaudioclient-ispatialaudioobjectrenderstream)

[ISpatialAudioObjectRenderStreamBase](https://learn.microsoft.com/windows/win32/api/spatialaudioclient/nn-spatialaudioclient-ispatialaudioobjectrenderstreambase)