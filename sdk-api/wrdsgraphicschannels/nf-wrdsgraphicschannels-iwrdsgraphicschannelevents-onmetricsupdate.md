# IWRdsGraphicsChannelEvents::OnMetricsUpdate

## Description

Called to notify the RemoteFX graphics services that network conditions have changed.

## Parameters

### `bandwidth` [in]

The expected bandwidth, in bytes per second. If this parameter contains **WRdsGraphicsChannels_Bandwidth_Unavailable**, bandwidth statistics are not available.

### `RTT` [in]

The round trip time (RTT) of the link, in milliseconds. If this parameter contains **WRdsGraphicsChannels_RTT_Unavailable**, latency statistics are not available.

### `lastSentByteIndex` [in]

The byte index of the last byte that was sent from this channel at this time. This value begins at zero and increases for the lifetime of the connection. This value will roll back to zero when an overflow occurs.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IWRdsGraphicsChannelEvents](https://learn.microsoft.com/windows/desktop/api/wrdsgraphicschannels/nn-wrdsgraphicschannels-iwrdsgraphicschannelevents)