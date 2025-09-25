# IWMPSettings::getMode

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **getMode** method determines whether the loop mode or shuffle mode is active.

## Parameters

### `bstrMode` [in]

**BSTR** containing one of the following values.

| Value | Description |
| --- | --- |
| autoRewind | Tracks are restarted from the beginning after playing to the end. |
| loop | The sequence of tracks repeats itself. |
| showFrame | The nearest key frame is displayed when not playing. This mode is not relevant for audio tracks. |
| shuffle | Tracks are played in random order. |

### `pvarfMode` [out]

Pointer to a **VARIANT_BOOL** indicating whether the specified mode is active.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## See also

[IWMPSettings Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpsettings)

[IWMPSettings::setMode](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpsettings-setmode)