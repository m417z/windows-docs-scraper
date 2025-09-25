# ISpatialAudioObjectRenderStreamBase::EndUpdatingAudioObjects

## Description

Notifies the system that the app has finished supplying audio data for the spatial audio objects activated with [ActivateSpatialAudioObject](https://learn.microsoft.com/windows/desktop/api/spatialaudioclient/nf-spatialaudioclient-ispatialaudioobjectrenderstream-activatespatialaudioobject).

## Return value

If the method succeeds, it returns S_OK. If it fails, possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **SPTLAUDCLNT_E_OUT_OF_ORDER** | **EndUpdatingAudioObjects** was called before [BeginUpdatingAudioObjects](https://learn.microsoft.com/windows/desktop/api/spatialaudioclient/nf-spatialaudioclient-ispatialaudioobjectrenderstreambase-beginupdatingaudioobjects). |
| **SPTLAUDCLNT_E_DESTROYED** | The [ISpatialAudioClient](https://learn.microsoft.com/windows/win32/api/spatialaudioclient/nn-spatialaudioclient-ispatialaudioclient) associated with the spatial audio stream has been destroyed. |
| **AUDCLNT_E_DEVICE_INVALIDATED** | The audio endpoint device has been unplugged, or the audio hardware or associated hardware resources have been reconfigured, disabled, removed, or otherwise made unavailable for use. |
| **AUDCLNT_E_RESOURCES_INVALIDATED** | A resource associated with the spatial audio stream is no longer valid. |
| **SPTLAUDCLNT_E_INTERNAL** | An internal error has occurred. |
| **AUDCLNT_E_UNSUPPORTED_FORMAT** | The media associated with the spatial audio stream uses an unsupported format. |

## Remarks

The pointers retrieved with [ISpatialAudioObjectBase::GetBuffer](https://learn.microsoft.com/windows/desktop/api/spatialaudioclient/nf-spatialaudioclient-ispatialaudioobjectbase-getbuffer) can no longer be used after this method is called.

## See also

[ISpatialAudioObjectRenderStream](https://learn.microsoft.com/windows/desktop/api/spatialaudioclient/nn-spatialaudioclient-ispatialaudioobjectrenderstream)

[ISpatialAudioObjectRenderStreamBase](https://learn.microsoft.com/windows/win32/api/spatialaudioclient/nn-spatialaudioclient-ispatialaudioobjectrenderstreambase)