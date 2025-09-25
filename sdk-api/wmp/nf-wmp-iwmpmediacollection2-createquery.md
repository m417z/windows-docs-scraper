# IWMPMediaCollection2::createQuery

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **createQuery** method retrieves a pointer to an **IWMPQuery** interface that represents a new query.

## Parameters

### `ppQuery` [out]

Address of a variable that receives an **IWMPQuery** pointer to the new, empty query.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

Creating a new query is the first step toward creating a compound query.

**Windows Media Player 10 Mobile:** This method is not supported.

## See also

[IWMPMediaCollection2 Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpmediacollection2)

[IWMPQuery Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpquery)