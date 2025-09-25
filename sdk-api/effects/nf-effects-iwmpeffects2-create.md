# IWMPEffects2::Create

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **Create** method is called by Windows Media Player to instantiate a visualization window.

## Parameters

### `hwndParent` [in]

**HWND** handle to the parent window hosting the visualization window.

## Return value

This method returns an **HRESULT**.

## Remarks

A visualization that implements **IWMPEffects2** is rendered in its own window unless it will be displayed in a clipped device context, in which case it is rendered windowless. For a visualization that is rendered windowless, Windows Media Player calls this method with a **NULL** value for the *hwndParent* parameter. If your visualization does not support windowless mode (for example, when using Direct3D), it should return a failure **HRESULT** value. In this case, your visualization will not be available in skins that clip the display region.

If you create a visualization for Windows Media Player using the Direct3D® component of Microsoft DirectX®, you must set the **D3DCREATE_FPU_PRESERVE** flag when calling **IDirect3D8::CreateDevice**. Failure to set this flag for visualizations that use Direct3D may yield unexpected results.

## See also

[IWMPEffects2 Interface](https://learn.microsoft.com/windows/desktop/api/effects/nn-effects-iwmpeffects2)

[IWMPEffects2::Destroy](https://learn.microsoft.com/windows/desktop/api/effects/nf-effects-iwmpeffects2-destroy)