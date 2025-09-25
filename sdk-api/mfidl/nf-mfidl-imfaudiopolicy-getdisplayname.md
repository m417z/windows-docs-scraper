# IMFAudioPolicy::GetDisplayName

## Description

Retrieves the display name of the audio session. The Windows volume control displays this name.

## Parameters

### `pszName` [out]

Receives a pointer to the display name string. The caller must free the memory allocated for the string by calling [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree).

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

If the application does not set a display name, Windows creates one.

## See also

[IMFAudioPolicy](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfaudiopolicy)

[Streaming Audio Renderer](https://learn.microsoft.com/windows/desktop/medfound/streaming-audio-renderer)