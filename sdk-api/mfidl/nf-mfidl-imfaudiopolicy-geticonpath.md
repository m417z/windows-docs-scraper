# IMFAudioPolicy::GetIconPath

## Description

Retrieves the icon resource for the audio session. The Windows volume control displays this icon.

## Parameters

### `pszPath` [out]

Receives a pointer to a wide-character string that specifies a shell resource. The format of the string is described in the topic [IMFAudioPolicy::SetIconPath](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfaudiopolicy-seticonpath). The caller must free the memory allocated for the string by calling [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree).

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

If the application did not set an icon path, the method returns an empty string ("").

For more information, see **IAudioSessionControl::GetIconPath** in the core audio API documentation.

## See also

[IMFAudioPolicy](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfaudiopolicy)

[Streaming Audio Renderer](https://learn.microsoft.com/windows/desktop/medfound/streaming-audio-renderer)