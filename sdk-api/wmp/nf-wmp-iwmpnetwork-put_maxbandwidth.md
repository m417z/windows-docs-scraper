# IWMPNetwork::put_maxBandwidth

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **put_maxBandwidth** method specifies the maximum allowed bandwidth.

## Parameters

### `lMaxBandwidth` [in]

**long** containing the max bandwidth.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

This method does not have a default value. The value can be specified while Windows Media Player is playing, but the change will not take effect until the current media item is released by opening another one or by calling **IWMPCore::close**. Windows Media Player attempts to achieve the highest bandwidth possible. Only in the case of this value being set will any intentional reduction of bandwidth occur.

This setting is useful for reducing the amount of bandwidth used, particularly in the case of a multiple bit rate (MBR) stream. An MBR stream contains multiple streams with different bit rates. In some cases, it may be desirable to use a stream with a lower bit rate than the client requires. In this case, specifying a lower bit rate with the **IWMPNetwork::put_maxBandwidth** method will select a lower bit-rate stream. For example, an MBR stream might include streams encoded at 20 kilobits per second (Kbps), 37 Kbps, and 200 Kbps. Using **IWMPNetwork::put_maxBandwidth** to specify a bit rate of 50,000 (50 Kbps) will select the 37 Kbps stream instead of the 200 Kbps stream.

## See also

[IWMPCore::close](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpcore-close)

[IWMPNetwork Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpnetwork)

[IWMPNetwork::get_maxBandwidth](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpnetwork-get_maxbandwidth)