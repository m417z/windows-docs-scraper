# ISpatialAudioObjectBase::IsActive

## Description

Gets a boolean value indicating whether the [ISpatialAudioObject](https://learn.microsoft.com/windows/desktop/api/spatialaudioclient/nn-spatialaudioclient-ispatialaudioobject) is valid.

## Parameters

### `isActive` [out]

**TRUE** if the audio object is currently valid; otherwise, **FALSE**.

## Return value

If the method succeeds, it returns S_OK.

## Remarks

If this value is false, you should call [Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) to make the audio object resource available in the future.

**IsActive** will be set to false after [SetEndOfStream](https://learn.microsoft.com/windows/desktop/api/spatialaudioclient/nf-spatialaudioclient-ispatialaudioobjectbase-setendofstream) is called implicitly or explicitly. **SetEndOfStream** is called implicitly by the system if [GetBuffer](https://learn.microsoft.com/windows/desktop/api/spatialaudioclient/nf-spatialaudioclient-ispatialaudioobjectbase-getbuffer) is not called within an audio processing pass (between calls to [ISpatialAudioObjectRenderStream::BeginUpdatingAudioObjects](https://learn.microsoft.com/windows/desktop/api/spatialaudioclient/nf-spatialaudioclient-ispatialaudioobjectrenderstreambase-beginupdatingaudioobjects) and [ISpatialAudioObjectRenderStream::EndUpdatingAudioObjects](https://learn.microsoft.com/windows/desktop/api/spatialaudioclient/nf-spatialaudioclient-ispatialaudioobjectrenderstreambase-endupdatingaudioobjects)).

The rendering engine will also deactivate the audio object, setting **IsActive** to false, when audio object resources become unavailable. In this case, a notification is sent via [ISpatialAudioObjectRenderStreamNotify](https://learn.microsoft.com/windows/desktop/api/spatialaudioclient/nn-spatialaudioclient-ispatialaudioobjectrenderstreamnotify) before the object is deactivated. The value returned in the *availableDynamicObjectCount* parameter to [ISpatialAudioObjectRenderStream::BeginUpdatingAudioObjects](https://learn.microsoft.com/windows/desktop/api/spatialaudioclient/nf-spatialaudioclient-ispatialaudioobjectrenderstreambase-beginupdatingaudioobjects) indicates how many objects will be processed for each pass.

## See also

[ISpatialAudioObject](https://learn.microsoft.com/windows/desktop/api/spatialaudioclient/nn-spatialaudioclient-ispatialaudioobject)

[ISpatialAudioObjectBase](https://learn.microsoft.com/windows/win32/api/spatialaudioclient/nn-spatialaudioclient-ispatialaudioobjectbase)