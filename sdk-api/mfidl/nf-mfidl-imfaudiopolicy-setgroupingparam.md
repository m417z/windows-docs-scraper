# IMFAudioPolicy::SetGroupingParam

## Description

Assigns the audio session to a group of sessions.

## Parameters

### `rguidClass` [in]

A **GUID** that identifies the session group. Groups are application-defined. To create a new session group, assign a new GUID.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

If two or more audio sessions share the same group, the Windows volume control displays one slider control for the entire group. Otherwise, it displays a slider for each session. For more information, see **IAudioSessionControl::SetGroupingParam** in the core audio API documentation.

## See also

[IMFAudioPolicy](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfaudiopolicy)

[Streaming Audio Renderer](https://learn.microsoft.com/windows/desktop/medfound/streaming-audio-renderer)