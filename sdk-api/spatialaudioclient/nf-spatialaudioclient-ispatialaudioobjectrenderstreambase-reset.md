# ISpatialAudioObjectRenderStreamBase::Reset

## Description

Reset a stopped audio stream.

## Return value

If the method succeeds, it returns S_OK. If it fails, possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **SPTLAUDCLNT_E_STREAM_NOT_STOPPED** | The audio stream has not been stopped. Stop the stream by calling [Stop](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudioclient-stop). |
| **SPTLAUDCLNT_E_DESTROYED** | The [ISpatialAudioClient](https://learn.microsoft.com/windows/win32/api/spatialaudioclient/nn-spatialaudioclient-ispatialaudioclient) associated with the spatial audio stream has been destroyed. |
| **AUDCLNT_E_DEVICE_INVALIDATED** | The audio endpoint device has been unplugged, or the audio hardware or associated hardware resources have been reconfigured, disabled, removed, or otherwise made unavailable for use. |
| **SPTLAUDCLNT_E_INTERNAL** | An internal error has occurred. |
| **AUDCLNT_E_UNSUPPORTED_FORMAT** | The media associated with the spatial audio stream uses an unsupported format. |

## Remarks

Resetting the audio stream flushes all pending data and resets the audio clock stream position to 0. Resetting the stream also causes all active [ISpatialAudioObject](https://learn.microsoft.com/windows/desktop/api/spatialaudioclient/nn-spatialaudioclient-ispatialaudioobject) instances to be revoked.
A subsequent call to [Start](https://learn.microsoft.com/windows/desktop/api/spatialaudioclient/nf-spatialaudioclient-ispatialaudioobjectrenderstreambase-start) causes the stream to start from 0 position.

The stream must have been previously stopped with a call to [Stop](https://learn.microsoft.com/windows/desktop/api/spatialaudioclient/nf-spatialaudioclient-ispatialaudioobjectrenderstreambase-stop) or the method will fail and return SPTLAUDCLNT_E_STREAM_NOT_STOPPED.

## See also

[ISpatialAudioObjectRenderStream](https://learn.microsoft.com/windows/desktop/api/spatialaudioclient/nn-spatialaudioclient-ispatialaudioobjectrenderstream)

[ISpatialAudioObjectRenderStreamBase](https://learn.microsoft.com/windows/win32/api/spatialaudioclient/nn-spatialaudioclient-ispatialaudioobjectrenderstreambase)