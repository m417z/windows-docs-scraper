# IWMPEvents::CurrentItemChange

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **CurrentItemChange** event occurs when the user or the **IWMPControls::put_CurrentItem** method changes the current item value.

## Parameters

### `pdispMedia` [in]

Pointer to an **IDispatch** interface that identifies the new current item.

## See also

[IWMPControls::put_currentItem](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpcontrols-put_currentitem)

[IWMPEvents Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpevents)