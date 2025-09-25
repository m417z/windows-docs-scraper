# IWMPEffects::Render

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **Render** method renders the visualization.

## Parameters

### `pLevels` [in]

Pointer to a **TimedLevel** structure.

### `hdc` [in]

Specifies a handle to a device context.

### `prc` [in]

Specifies the rectangle the visualization is to be rendered in.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an **HRESULT** error code.

## Remarks

The device context is normalized by this method.

## See also

[IWMPEffects Interface](https://learn.microsoft.com/windows/desktop/api/effects/nn-effects-iwmpeffects)

[TimedLevel](https://learn.microsoft.com/previous-versions/windows/desktop/api/effects/ns-effects-timedlevel)