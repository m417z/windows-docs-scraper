# IWMPEffects::GetTitle

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **GetTitle** method gets the display title of the visualization.

## Parameters

### `bstrTitle` [out]

**String** containing the title.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an **HRESULT** error code.

## Remarks

This method allows the application to show the user a title when the visualization itself is displayed. The title should be as unique as possible. Do not use titles of visualizations included with the Windows Media Player as this will cause confusion to the user.

## See also

[IWMPEffects Interface](https://learn.microsoft.com/windows/desktop/api/effects/nn-effects-iwmpeffects)