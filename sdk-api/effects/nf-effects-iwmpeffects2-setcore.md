# IWMPEffects2::SetCore

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **SetCore** method is called by Windows Media Player to provide visualization access to the core Windows Media Player APIs.

## Parameters

### `pPlayer` [in]

Pointer to an **IWMPCore** interface.

## Return value

This method returns an **HRESULT**.

## Remarks

You can use this method to set or release a pointer to the **IWMPCore** interface. If *pPlayer* is **NULL**, the visualization is being shut down and all stored references to the core should be released.

This method is not called when Windows Media Player instantiates the visualization for the purpose of displaying its property page. This method can therefore be used as an entry point that will only be called when the visualization is enabled and Windows Media Player loads it normally.

## See also

[IWMPEffects2 Interface](https://learn.microsoft.com/windows/desktop/api/effects/nn-effects-iwmpeffects2)