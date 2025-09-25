# IWMPEffects2::RenderWindowed

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **RenderWindowed** method is called by Windows Media Player to render a windowed visualization.

## Parameters

### `pData` [in]

Pointer to a **TimedLevel** structure specifying rendering information.

### `fRequiredRender` [in]

**BOOL** indicating whether the visualization must paint itself.

## Return value

This method returns an **HRESULT**.

## Remarks

This method is used to render windowed visualizations. Windowless visualizations should return S_OK and use the **IWMPEffects::Render** method instead.

The *fRequiredRender* parameter informs you that your visualization must repaint itself, for example, when another window is dragged over it. When this value is false, you can safely skip over the rendering code if the current media item is stopped or paused. This lets you avoid consuming CPU cycles unnecessarily.

## See also

[IWMPEffects2 Interface](https://learn.microsoft.com/windows/desktop/api/effects/nn-effects-iwmpeffects2)

[IWMPEffects::Render](https://learn.microsoft.com/windows/desktop/api/effects/nf-effects-iwmpeffects-render)

[TimedLevel](https://learn.microsoft.com/previous-versions/windows/desktop/api/effects/ns-effects-timedlevel)