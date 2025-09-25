# IWMPCdromBurn::getItemInfo

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **getItemInfo** method retrieves the value of the specified attribute for the CD.

## Parameters

### `bstrItem` [in]

**BSTR** that contains one of the following values.

| Value | Description |
| --- | --- |
| AvailableTime | Retrieves the time available on the CD, in seconds. |
| Blank | Retrieves a **Boolean** (represented as a string) indicating whether the CD is blank. |
| FreeSpace | Retrieves the free space on the CD, in bytes. |
| TotalSpace | Retrieves the total space on the CD, in bytes. |

### `pbstrVal` [out]

Pointer to a **BSTR** that receives the returned value.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

**Windows Media Player 10 Mobile:** This method is not supported.

## See also

[IWMPCdromBurn Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpcdromburn)