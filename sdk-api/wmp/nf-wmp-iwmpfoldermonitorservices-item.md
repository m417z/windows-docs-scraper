# IWMPFolderMonitorServices::item

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

This method and all other methods of the [IWMPFolderMonitorServices](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpfoldermonitorservices) interface are deprecated.

The **item** method retrieves the path to the folder corresponding to the specified index.

## Parameters

### `lIndex` [in]

A **long** specifying the index of the folder to retrieve.

### `pbstrFolder` [out]

Pointer to a **BSTR** that receives the folder path string.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

**Windows Media Player 10 Mobile:** This method is not supported.

## See also

[IWMPFolderMonitorServices Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpfoldermonitorservices)