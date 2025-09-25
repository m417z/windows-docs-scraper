# IWMPEffects2::Destroy

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **Destroy** method is called by Windows Media Player to destroy a visualization window instantiated in the **Create** method.

## Return value

This method returns an **HRESULT**.

## Remarks

This method is used only by windowed visualizations. Windowless visualizations should simply return S_OK.

## See also

[IWMPEffects2 Interface](https://learn.microsoft.com/windows/desktop/api/effects/nn-effects-iwmpeffects2)

[IWMPEffects2::Create](https://learn.microsoft.com/windows/desktop/api/effects/nf-effects-iwmpeffects2-create)