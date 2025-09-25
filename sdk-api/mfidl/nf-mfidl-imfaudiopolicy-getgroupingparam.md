# IMFAudioPolicy::GetGroupingParam

## Description

Retrieves the group of sessions to which this audio session belongs.

## Parameters

### `pguidClass` [out]

Receives a GUID that identifies the session group.

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