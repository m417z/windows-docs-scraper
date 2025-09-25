# IWMPEffects::MediaInfo

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **MediaInfo** method sends channel and sample rate data to the visualization.

## Parameters

### `lChannelCount` [in]

**Long** integer containing the number of channels (one for mono, or two for stereo).

### `lSampleRate` [in]

**Long** integer containing the sample rate in hertz (Hz). For example, a value of 22500 would specify a rate of 22.5KHz.

### `bstrTitle` [in]

**String** specifying the title.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an **HRESULT** error code.

## See also

[IWMPEffects Interface](https://learn.microsoft.com/windows/desktop/api/effects/nn-effects-iwmpeffects)