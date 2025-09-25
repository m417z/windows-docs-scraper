# ISpatialAudioObjectBase::GetBuffer

## Description

Gets a buffer that is used to supply the audio data for the [ISpatialAudioObject](https://learn.microsoft.com/windows/desktop/api/spatialaudioclient/nn-spatialaudioclient-ispatialaudioobject).

## Parameters

### `buffer` [out]

The buffer into which audio data is written.

### `bufferLength` [out]

The length of the buffer in bytes. This length will be the value returned in the *frameCountPerBuffer* parameter to [ISpatialAudioObjectRenderStream::BeginUpdatingAudioObjects](https://learn.microsoft.com/windows/desktop/api/spatialaudioclient/nf-spatialaudioclient-ispatialaudioobjectrenderstreambase-beginupdatingaudioobjects) multiplied by the value of the **nBlockAlign** field of the [WAVEFORMATEX](https://learn.microsoft.com/windows/win32/api/mmreg/ns-mmreg-waveformatex) structure passed in the [SpatialAudioObjectRenderStreamActivationParams](https://learn.microsoft.com/windows/desktop/api/spatialaudioclient/ns-spatialaudioclient-spatialaudioobjectrenderstreamactivationparams)
parameter to [ISpatialAudioClient::ActivateSpatialAudioStream](https://learn.microsoft.com/windows/desktop/api/spatialaudioclient/nf-spatialaudioclient-ispatialaudioclient-activatespatialaudiostream).

## Return value

If the method succeeds, it returns S_OK. If it fails, possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **SPTLAUDCLNT_E_OUT_OF_ORDER** | [ISpatialAudioObjectRenderStream::BeginUpdatingAudioObjects](https://learn.microsoft.com/windows/desktop/api/spatialaudioclient/nf-spatialaudioclient-ispatialaudioobjectrenderstreambase-beginupdatingaudioobjects) was not called before the call to **GetBuffer**. This method must be called before the first time **GetBuffer** is called and after every subsequent call to [ISpatialAudioObjectRenderStream::EndUpdatingAudioObjects](https://learn.microsoft.com/windows/desktop/api/spatialaudioclient/nf-spatialaudioclient-ispatialaudioobjectrenderstreambase-endupdatingaudioobjects). |
| **SPTLAUDCLNT_E_RESOURCES_INVALIDATED** | [SetEndOfStream](https://learn.microsoft.com/windows/desktop/api/spatialaudioclient/nf-spatialaudioclient-ispatialaudioobjectbase-setendofstream) was called either explicitly or implicitly in a previous audio processing pass. **SetEndOfStream** is called implicitly by the system if **GetBuffer** is not called within an audio processing pass (between calls to [ISpatialAudioObjectRenderStream::BeginUpdatingAudioObjects](https://learn.microsoft.com/windows/desktop/api/spatialaudioclient/nf-spatialaudioclient-ispatialaudioobjectrenderstreambase-beginupdatingaudioobjects) and [ISpatialAudioObjectRenderStream::EndUpdatingAudioObjects](https://learn.microsoft.com/windows/desktop/api/spatialaudioclient/nf-spatialaudioclient-ispatialaudioobjectrenderstreambase-endupdatingaudioobjects)). |

## Remarks

The first time **GetBuffer** is called after the [ISpatialAudioObject](https://learn.microsoft.com/windows/desktop/api/spatialaudioclient/nn-spatialaudioclient-ispatialaudioobject) is activated with a call [ISpatialAudioObjectRenderStream::ActivateSpatialAudioObject](https://learn.microsoft.com/windows/desktop/api/spatialaudioclient/nf-spatialaudioclient-ispatialaudioobjectrenderstream-activatespatialaudioobject),
lifetime of the spatial audio object starts.
To keep the spatial audio object alive after that, this **GetBuffer** must be called on every processing pass (between calls to [ISpatialAudioObjectRenderStream::BeginUpdatingAudioObjects](https://learn.microsoft.com/windows/desktop/api/spatialaudioclient/nf-spatialaudioclient-ispatialaudioobjectrenderstreambase-beginupdatingaudioobjects) and [ISpatialAudioObjectRenderStream::EndUpdatingAudioObjects](https://learn.microsoft.com/windows/desktop/api/spatialaudioclient/nf-spatialaudioclient-ispatialaudioobjectrenderstreambase-endupdatingaudioobjects)). If **GetBuffer** is not called within an audio processing pass, [SetEndOfStream](https://learn.microsoft.com/windows/desktop/api/spatialaudioclient/nf-spatialaudioclient-ispatialaudioobjectbase-setendofstream) is called implicitly on the audio object to deactivate, and the audio object can only be reused after calling [Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) on the object and then reactivating the object by calling **ActivateSpatialAudioObject** again.

The pointers retrieved by **GetBuffer** should not be used after
[ISpatialAudioObjectRenderStream::EndUpdatingAudioObjects](https://learn.microsoft.com/windows/desktop/api/spatialaudioclient/nf-spatialaudioclient-ispatialaudioobjectrenderstreambase-endupdatingaudioobjects) has been called.

## See also

[ISpatialAudioObject](https://learn.microsoft.com/windows/desktop/api/spatialaudioclient/nn-spatialaudioclient-ispatialaudioobject)

[ISpatialAudioObjectBase](https://learn.microsoft.com/windows/win32/api/spatialaudioclient/nn-spatialaudioclient-ispatialaudioobjectbase)