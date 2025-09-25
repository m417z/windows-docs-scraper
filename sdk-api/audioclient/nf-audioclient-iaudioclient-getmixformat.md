# IAudioClient::GetMixFormat

## Description

The **GetMixFormat** method retrieves the stream format that the audio engine uses for its internal processing of shared-mode streams.

## Parameters

### `ppDeviceFormat` [out]

Pointer to a pointer variable into which the method writes the address of the mix format. This parameter must be a valid, non-**NULL** pointer to a pointer variable. The method writes the address of a **WAVEFORMATEX** (or **WAVEFORMATEXTENSIBLE**) structure to this variable. The method allocates the storage for the structure. The caller is responsible for freeing the storage, when it is no longer needed, by calling the **CoTaskMemFree** function. If the **GetMixFormat** call fails, **ppDeviceFormat* is **NULL**. For information about **WAVEFORMATEX**, **WAVEFORMATEXTENSIBLE**, and **CoTaskMemFree**, see the Windows SDK documentation.

## Return value

If the method succeeds, it returns S_OK. If it fails, possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **AUDCLNT_E_DEVICE_INVALIDATED** | The audio endpoint device has been unplugged, or the audio hardware or associated hardware resources have been reconfigured, disabled, removed, or otherwise made unavailable for use. |
| **AUDCLNT_E_RESOURCES_INVALIDATED** | The stream's resources have been invalidated. This error may be thrown for the following reasons:\<br>- The stream is suspended.\<br>- An Exclusive or Offload stream is disconnected.\<br>- A packaged application that has an exclusive mode or offload stream is quiesced.\<br>- A "protected output" stream is closed.\ |
| **AUDCLNT_E_SERVICE_NOT_RUNNING** | The Windows audio service is not running. |
| **E_POINTER** | Parameter *ppDeviceFormat* is **NULL**. |
| **E_OUTOFMEMORY** | Out of memory. |

## Remarks

The client can call this method before calling the [IAudioClient::Initialize](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudioclient-initialize) method. When creating a shared-mode stream for an audio endpoint device, the **Initialize** method always accepts the stream format obtained from a **GetMixFormat** call on the same device.

The mix format is the format that the audio engine uses internally for digital processing of shared-mode streams. This format is not necessarily a format that the audio endpoint device supports. Thus, the caller might not succeed in creating an exclusive-mode stream with a format obtained by calling **GetMixFormat**.

For example, to facilitate digital audio processing, the audio engine might use a mix format that represents samples as floating-point values. If the device supports only integer PCM samples, then the engine converts the samples to or from integer PCM values at the connection between the device and the engine. However, to avoid resampling, the engine might use a mix format with a sample rate that the device supports.

To determine whether the **Initialize** method can create a shared-mode or exclusive-mode stream with a particular format, call the [IAudioClient::IsFormatSupported](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudioclient-isformatsupported) method.

By itself, a **WAVEFORMATEX** structure cannot specify the mapping of channels to speaker positions. In addition, although **WAVEFORMATEX** specifies the size of the container for each audio sample, it cannot specify the number of bits of precision in a sample (for example, 20 bits of precision in a 24-bit container). However, the **WAVEFORMATEXTENSIBLE** structure can specify both the mapping of channels to speakers and the number of bits of precision in each sample. For this reason, the **GetMixFormat** method retrieves a format descriptor that is in the form of a **WAVEFORMATEXTENSIBLE** structure instead of a standalone **WAVEFORMATEX** structure. Through the *ppDeviceFormat* parameter, the method outputs a pointer to the **WAVEFORMATEX** structure that is embedded at the start of this **WAVEFORMATEXTENSIBLE** structure. For more information about **WAVEFORMATEX** and **WAVEFORMATEXTENSIBLE**, see the Windows DDK documentation.

For more information about the **GetMixFormat** method, see [Device Formats](https://learn.microsoft.com/windows/desktop/CoreAudio/device-formats). For code examples that call **GetMixFormat**, see the following topics:

* [Rendering a Stream](https://learn.microsoft.com/windows/desktop/CoreAudio/rendering-a-stream)
* [Capturing a Stream](https://learn.microsoft.com/windows/desktop/CoreAudio/capturing-a-stream)

## See also

[IAudioClient Interface](https://learn.microsoft.com/windows/desktop/api/audioclient/nn-audioclient-iaudioclient)

[IAudioClient::Initialize](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudioclient-initialize)

[IAudioClient::IsFormatSupported](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudioclient-isformatsupported)