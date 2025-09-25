# IAudioClient::IsFormatSupported

## Description

The **IsFormatSupported** method indicates whether the audio endpoint device supports a particular stream format.

## Parameters

### `ShareMode` [in]

The sharing mode for the stream format. Through this parameter, the client indicates whether it wants to use the specified format in exclusive mode or shared mode. The client should set this parameter to one of the following [AUDCLNT_SHAREMODE](https://learn.microsoft.com/windows/win32/api/audiosessiontypes/ne-audiosessiontypes-audclnt_sharemode) enumeration values:

AUDCLNT_SHAREMODE_EXCLUSIVE

AUDCLNT_SHAREMODE_SHARED

### `pFormat` [in]

Pointer to the specified stream format. This parameter points to a caller-allocated format descriptor of type **WAVEFORMATEX** or **WAVEFORMATEXTENSIBLE**. The client writes a format description to this structure before calling this method. For information about **WAVEFORMATEX** and **WAVEFORMATEXTENSIBLE**, see the Windows DDK documentation.

### `ppClosestMatch` [out]

Pointer to a pointer variable into which the method writes the address of a **WAVEFORMATEX** or **WAVEFORMATEXTENSIBLE** structure. This structure specifies the supported format that is closest to the format that the client specified through the *pFormat* parameter. For shared mode (that is, if the *ShareMode* parameter is AUDCLNT_SHAREMODE_SHARED), set *ppClosestMatch* to point to a valid, non-**NULL** pointer variable. For exclusive mode, set *ppClosestMatch* to **NULL**. The method allocates the storage for the structure. The caller is responsible for freeing the storage, when it is no longer needed, by calling the **CoTaskMemFree** function. If the **IsFormatSupported** call fails and *ppClosestMatch* is non-**NULL**, the method sets **ppClosestMatch* to **NULL**. For information about **CoTaskMemFree**, see the Windows SDK documentation.

## Return value

| Return code | Description |
| --- | --- |
| **S_OK** | Succeeded and the audio endpoint device supports the specified stream format. |
| **S_FALSE** | Succeeded with a closest match to the specified format. |
| **AUDCLNT_E_UNSUPPORTED_FORMAT** | Succeeded but the specified format is not supported in exclusive mode. |

 If the operation fails, possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **E_POINTER** | Parameter *pFormat* is **NULL**, or *ppClosestMatch* is **NULL** and *ShareMode* is AUDCLNT_SHAREMODE_SHARED. |
| **E_INVALIDARG** | Parameter *ShareMode* is a value other than AUDCLNT_SHAREMODE_SHARED or AUDCLNT_SHAREMODE_EXCLUSIVE. |
| **AUDCLNT_E_DEVICE_INVALIDATED** | The audio endpoint device has been unplugged, or the audio hardware or associated hardware resources have been reconfigured, disabled, removed, or otherwise made unavailable for use. |
| **AUDCLNT_E_RESOURCES_INVALIDATED** | The stream's resources have been invalidated. This error may be thrown for the following reasons:\<br>- The stream is suspended.\<br>- An Exclusive or Offload stream is disconnected.\<br>- A packaged application that has an exclusive mode or offload stream is quiesced.\<br>- A "protected output" stream is closed.\ |
| **AUDCLNT_E_SERVICE_NOT_RUNNING** | The Windows audio service is not running. |

## Remarks

This method provides a way for a client to determine, before calling [IAudioClient::Initialize](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudioclient-initialize), whether the audio engine supports a particular stream format.

For exclusive mode, **IsFormatSupported** returns S_OK if the audio endpoint device supports the caller-specified format, or it returns AUDCLNT_E_UNSUPPORTED_FORMAT if the device does not support the format. The *ppClosestMatch* parameter can be **NULL**. If it is not **NULL**, the method writes **NULL** to **ppClosestMatch*.

For shared mode, if the audio engine supports the caller-specified format, **IsFormatSupported** sets ***ppClosestMatch** to **NULL** and returns S_OK. If the audio engine does not support the caller-specified format but does support a similar format, the method retrieves the similar format through the *ppClosestMatch* parameter and returns S_FALSE. If the audio engine does not support the caller-specified format or any similar format, the method sets **ppClosestMatch* to **NULL** and returns AUDCLNT_E_UNSUPPORTED_FORMAT.

In shared mode, the audio engine always supports the mix format, which the client can obtain by calling the [IAudioClient::GetMixFormat](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudioclient-getmixformat) method. In addition, the audio engine might support similar formats that have the same sample rate and number of channels as the mix format but differ in the representation of audio sample values. The audio engine represents sample values internally as floating-point numbers, but if the caller-specified format represents sample values as integers, the audio engine typically can convert between the integer sample values and its internal floating-point representation.

The audio engine might be able to support an even wider range of shared-mode formats if the installation package for the audio device includes a local effects (LFX) audio processing object (APO) that can handle format conversions. An LFX APO is a software module that performs device-specific processing of an audio stream. The audio graph builder in the Windows audio service inserts the LFX APO into the stream between each client and the audio engine. When a client calls the **IsFormatSupported** method and the method determines that an LFX APO is installed for use with the device, the method directs the query to the LFX APO, which indicates whether it supports the caller-specified format.

For example, a particular LFX APO might accept a 6-channel surround sound stream from a client and convert the stream to a stereo format that can be played through headphones. Typically, an LFX APO supports only client formats with sample rates that match the sample rate of the mix format.

For more information about APOs, see [Windows Audio Processing Objects](https://learn.microsoft.com/windows-hardware/drivers/audio/windows-audio-processing-objects). For more information about the **IsFormatSupported** method, see [Device Formats](https://learn.microsoft.com/windows/desktop/CoreAudio/device-formats).

## See also

[IAudioClient Interface](https://learn.microsoft.com/windows/desktop/api/audioclient/nn-audioclient-iaudioclient)

[IAudioClient::GetMixFormat](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudioclient-getmixformat)

[IAudioClient::Initialize](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-iaudioclient-initialize)