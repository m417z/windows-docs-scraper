# IWMPEvents3::CdromBurnError

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **CdromBurnError** event occurs when a generic error happens during a CD burning operation.

## Parameters

### `pCdromBurn` [in]

Pointer to the **IWMPCdromBurn** interface that represents the burning operation that raised the error.

### `hrError` [in]

**HRESULT** for the error that raised the event.

## Remarks

To capture media specific errors, handle the **CdromBurnMediaError** event.

You can also handle this event through an **IDispatch** event sink by using the **_WMPOCXEvents** interface.

**Windows Media Player 10 Mobile:** This event is not supported.

## See also

[IWMPCdromBurn Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpcdromburn)

[IWMPEvents3 Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpevents3)

[IWMPEvents3::CdromBurnMediaError](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpevents3-cdromburnmediaerror)

[_WMPOCXEvents Interface](https://learn.microsoft.com/windows/desktop/WMP/-wmpocxevents-interface)