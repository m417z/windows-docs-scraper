# IMFAudioPolicy::SetDisplayName

## Description

Sets the display name of the audio session. The Windows volume control displays this name.

## Parameters

### `pszName` [in]

A null-terminated wide-character string that contains the display name.

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