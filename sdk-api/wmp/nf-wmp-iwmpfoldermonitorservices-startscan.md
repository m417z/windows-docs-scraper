# IWMPFolderMonitorServices::startScan

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

This method and all other methods of the [IWMPFolderMonitorServices](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpfoldermonitorservices) interface are deprecated.

The **startScan** method starts a scanning operation.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

The **startScan** method should always be paired with a call to the **stopScan** method. You should never call the **startScan** method twice in a row. A scanning operation consists of two phases: scanning and updating. You can determine the current scan state by calling **get_scanState** or by handling the **FolderScanStateChange** event.

**Windows Media Player 10 Mobile:** This method is not supported.

## See also

[IWMPEvents3::FolderScanStateChange](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpevents3-folderscanstatechange)

[IWMPFolderMonitorServices Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpfoldermonitorservices)

[IWMPFolderMonitorServices::get_scanState](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpfoldermonitorservices-get_scanstate)

[IWMPFolderMonitorServices::stopScan](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpfoldermonitorservices-stopscan)

[WMPFolderScanState](https://learn.microsoft.com/windows/desktop/api/wmp/ne-wmp-wmpfolderscanstate)