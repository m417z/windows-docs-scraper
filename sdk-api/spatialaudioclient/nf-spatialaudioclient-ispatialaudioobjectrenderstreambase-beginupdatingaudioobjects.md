# ISpatialAudioObjectRenderStreamBase::BeginUpdatingAudioObjects

## Description

Puts the system into the state where audio object data can be submitted for processing and the [ISpatialAudioObject](https://learn.microsoft.com/windows/desktop/api/spatialaudioclient/nn-spatialaudioclient-ispatialaudioobject) state can be modified.

## Parameters

### `availableDynamicObjectCount` [out]

The number of dynamic audio objects that are available to be rendered for the current processing pass. All allocated static audio objects can be rendered in every pass. For information on audio object types, see [AudioObjectType](https://learn.microsoft.com/windows/desktop/api/spatialaudioclient/ne-spatialaudioclient-audioobjecttype).

### `frameCountPerBuffer` [out]

The size, in audio frames, of the buffer returned by [GetBuffer](https://learn.microsoft.com/windows/desktop/api/spatialaudioclient/nf-spatialaudioclient-ispatialaudioobjectbase-getbuffer).

## Return value

If the method succeeds, it returns S_OK. If it fails, possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **SPTLAUDCLNT_E_OUT_OF_ORDER** | **BeginUpdatingAudioObjects** was called twice without a matching call to [EndUpdatingAudioObjects](https://learn.microsoft.com/windows/desktop/api/spatialaudioclient/nf-spatialaudioclient-ispatialaudioobjectrenderstreambase-endupdatingaudioobjects) between the two calls. |
| **SPTLAUDCLNT_E_DESTROYED** | The [ISpatialAudioClient](https://learn.microsoft.com/windows/win32/api/spatialaudioclient/nn-spatialaudioclient-ispatialaudioclient) associated with the spatial audio stream has been destroyed. |
| **AUDCLNT_E_DEVICE_INVALIDATED** | The audio endpoint device has been unplugged, or the audio hardware or associated hardware resources have been reconfigured, disabled, removed, or otherwise made unavailable for use. |
| **AUDCLNT_E_RESOURCES_INVALIDATED** | A resource associated with the spatial audio stream is no longer valid. |
| **SPTLAUDCLNT_E_INTERNAL** | An internal error has occurred. |
| **AUDCLNT_E_UNSUPPORTED_FORMAT** | The media associated with the spatial audio stream uses an unsupported format. |

## Remarks

This method must be called each time the event passed in the [SpatialAudioObjectRenderStreamActivationParams](https://learn.microsoft.com/windows/desktop/api/spatialaudioclient/ns-spatialaudioclient-spatialaudioobjectrenderstreamactivationparams) to [ISpatialAudioClient::ActivateSpatialAudioStream](https://learn.microsoft.com/windows/desktop/api/spatialaudioclient/nf-spatialaudioclient-ispatialaudioclient-activatespatialaudiostream) is signaled,
even if there no audio object data to submit.

For each **BeginUpdatingAudioObjects** call, there should be a corresponding call to [EndUpdatingAudioObjects](https://learn.microsoft.com/windows/desktop/api/spatialaudioclient/nf-spatialaudioclient-ispatialaudioobjectrenderstreambase-endupdatingaudioobjects) call.
If **BeginUpdatingAudioObjects** is called twice without a call **EndUpdatingAudioObjects** between them, the second call to
**BeginUpdatingAudioObjects** will return SPTLAUDCLNT_E_OUT_OF_ORDER.

## See also

[ISpatialAudioObjectRenderStream](https://learn.microsoft.com/windows/desktop/api/spatialaudioclient/nn-spatialaudioclient-ispatialaudioobjectrenderstream)

[ISpatialAudioObjectRenderStreamBase](https://learn.microsoft.com/windows/win32/api/spatialaudioclient/nn-spatialaudioclient-ispatialaudioobjectrenderstreambase)