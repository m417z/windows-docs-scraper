# IWMPEvents::CdromMediaChange

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **CdromMediaChange** event occurs when a CD or DVD is inserted into or ejected from a CD or DVD drive.

## Parameters

### `CdromNum` [in]

Specifies the index of the CD or DVD drive.

## Remarks

The index of the CD drive corresponds to the index of a **Cdrom** object in the **IWMPCdromCollection** interface.

**Windows Media Player 10 Mobile:** This event is not supported.

## See also

[IWMPCdromCollection Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpcdromcollection)

[IWMPEvents Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpevents)