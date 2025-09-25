# IWMPCore::put_URL

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **put_URL** method specifies the URL of the media item to play.

## Parameters

### `bstrURL` [in]

**BSTR** containing the URL.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

This method can only be used to set a URL in a security zone that is the same or is less restrictive than the security zone of the calling program or webpage.

Applications that open media items from behind a firewall will have better performance if the address is specified using the domain name server (DNS) name instead of the IP address.

Do not call this method from event handler code as it may yield unexpected results.

## See also

[IWMPCore Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpcore)

[IWMPCore::get_URL](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpcore-get_url)