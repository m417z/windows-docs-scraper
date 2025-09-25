# IWMPSettings::setMode

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **setMode** method sets the state of playback options.

## Parameters

### `bstrMode` [in]

**BSTR** containing one of the following values.

| Value | Description |
| --- | --- |
| autoRewind | Tracks are restarted at the beginning after playing to the end. Default state is true. |
| loop | The sequence of tracks repeats itself. Default state is false. |
| showFrame | The nearest video keyframe is displayed when not playing. Default state is false. Has no effect on audio tracks. |
| shuffle | Tracks are played in random order. Default state is false. |

### `varfMode` [in]

**VARIANT_BOOL** specifying whether the specified mode is active.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

When the showFrame mode is active, Windows Media Player must access the track content to retrieve the video frame. Use this mode cautiously when playing non-local content.

## See also

[IWMPSettings Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpsettings)

[IWMPSettings::getMode](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpsettings-getmode)