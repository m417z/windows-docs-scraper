# IWMPEffects::GoFullscreen

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **GoFullscreen** method instructs the visualization to switch to full-screen mode.

## Parameters

### `fFullScreen` [in]

**Boolean** indicating whether to switch to full-screen mode.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an **HRESULT** error code.

## Remarks

This method is called when the visualization is to go full screen or leave full screen. If the full screen capabilities flag is not returned through **GetCapabilities**, your visualization will not be asked to go or render full screen. This method will be called before **RenderFullScreen** is called.

A default implementation of this method is not included in the visualization wizard.

## See also

[IWMPEffects Interface](https://learn.microsoft.com/windows/desktop/api/effects/nn-effects-iwmpeffects)