# ISpatialAudioObjectRenderStreamBase::GetService

## Description

Gets additional services from the **ISpatialAudioObjectRenderStream**.

## Parameters

### `riid` [in]

The interface ID for the requested service. The client should set this parameter to one of the following REFIID values:

IID_IAudioClock

IID_IAudioClock2

IID_IAudioStreamVolume

### `service` [out]

Pointer to a pointer variable into which the method writes the address of an instance of the requested interface. Through this method, the caller obtains a counted reference to the interface. The caller is responsible for releasing the interface, when it is no longer needed, by calling the interface's [Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) method. If the **GetService** call fails, **ppv*  is NULL.

## Return value

If the method succeeds, it returns S_OK. If it fails, possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **E_POINTER** | Parameter *ppv* is NULL. |
| **SPTLAUDCLNT_E_DESTROYED** | The [ISpatialAudioClient](https://learn.microsoft.com/windows/win32/api/spatialaudioclient/nn-spatialaudioclient-ispatialaudioclient) associated with the spatial audio stream has been destroyed. |
| **AUDCLNT_E_DEVICE_INVALIDATED** | The audio endpoint device has been unplugged, or the audio hardware or associated hardware resources have been reconfigured, disabled, removed, or otherwise made unavailable for use. |
| **SPTLAUDCLNT_E_INTERNAL** | An internal error has occurred. |
| **AUDCLNT_E_UNSUPPORTED_FORMAT** | The media associated with the spatial audio stream uses an unsupported format. |

## Remarks

The **GetService** method supports the following service interfaces:

* [IAudioClock](https://learn.microsoft.com/windows/desktop/api/audioclient/nn-audioclient-iaudioclock)
* [IAudioClock2](https://learn.microsoft.com/windows/desktop/api/audioclient/nn-audioclient-iaudioclock2)
* [IAudioStreamVolume](https://learn.microsoft.com/windows/desktop/api/audioclient/nn-audioclient-iaudiostreamvolume)

## See also

[ISpatialAudioObjectRenderStream](https://learn.microsoft.com/windows/desktop/api/spatialaudioclient/nn-spatialaudioclient-ispatialaudioobjectrenderstream)

[ISpatialAudioObjectRenderStreamBase](https://learn.microsoft.com/windows/win32/api/spatialaudioclient/nn-spatialaudioclient-ispatialaudioobjectrenderstreambase)