# IWMPEffects2::OnWindowMessage

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **OnWindowMessage** method is called by Windows Media Player to pass window messages to a visualization.

## Parameters

### `msg` [in]

**UINT** that identifies the window message.

### `WParam` [in]

**WPARAM** specifying a window message parameter.

### `LParam` [in]

**LPARAM** specifying a window message parameter.

### `plResultParam` [in]

Pointer to an **LRESULT** specifying the result code for the window message.

## Return value

This method returns an **HRESULT**.

## Remarks

Your implementation must only return S_OK if it has handled the window message. If it has not handled the window message, it should return S_FALSE. If this method is not implemented, return E_NOTIMPL.

## See also

[IWMPEffects2 Interface](https://learn.microsoft.com/windows/desktop/api/effects/nn-effects-iwmpeffects2)