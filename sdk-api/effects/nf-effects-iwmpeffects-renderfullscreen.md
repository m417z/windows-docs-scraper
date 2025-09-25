# IWMPEffects::RenderFullScreen

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **RenderFullScreen** method renders the visualization in full-screen mode.

## Parameters

### `pLevels` [in]

Pointer to a **TimedLevel** structure.

## Return value

If the method succeeds, your implementation should return S_OK. If it fails, return an **HRESULT** error code.

## Remarks

The **GoFullscreen** method must be called with a **True** value before **RenderFullScreen** can be called.

The user can enter or leave full screen mode by pressing the Alt and Enter keys simultaneously.

A default implementation of this method is not included in the visualization wizard.

If your implementation returns an error from this method, then **GoFullscreen**(**False**) will be called to ask your visualization to drop out of full screen mode.

## See also

[IWMPEffects Interface](https://learn.microsoft.com/windows/desktop/api/effects/nn-effects-iwmpeffects)

[TimedLevel](https://learn.microsoft.com/previous-versions/windows/desktop/api/effects/ns-effects-timedlevel)