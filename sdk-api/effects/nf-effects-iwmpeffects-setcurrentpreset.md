# IWMPEffects::SetCurrentPreset

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **SetCurrentPreset** method gets the current preset from Windows Media Player and sets it in the visualization.

## Parameters

### `nPreset` [out]

**Long** value specifying the new preset index.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an **HRESULT** error code.

## Remarks

This is called by the Windows Media Player to request that the given preset be displayed.

## See also

[IWMPEffects Interface](https://learn.microsoft.com/windows/desktop/api/effects/nn-effects-iwmpeffects)