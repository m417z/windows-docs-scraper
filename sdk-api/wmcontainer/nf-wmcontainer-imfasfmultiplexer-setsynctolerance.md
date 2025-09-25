# IMFASFMultiplexer::SetSyncTolerance

## Description

Sets the maximum time by which samples from various streams can be out of synchronization. The multiplexer will not accept a sample with a time stamp that is out of synchronization with the latest samples from any other stream by an amount that exceeds the synchronization tolerance.

## Parameters

### `msSyncTolerance` [in]

Synchronization tolerance in milliseconds.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

The synchronization tolerance is the maximum difference in presentation times at any given point between samples of different streams that the ASF multiplexer can accommodate. That is, if the synchronization tolerance is 3 seconds, no stream can be more than 3 seconds behind any other stream in the time stamps passed to the multiplexer. The multiplexer determines a default synchronization tolerance to use, but this method overrides it (usually to increase it). More tolerance means the potential for greater latency in the multiplexer. If the time stamps are synchronized among the streams, actual latency will be much lower than *msSyncTolerance*.

## See also

[ASF Multiplexer](https://learn.microsoft.com/windows/desktop/medfound/asf-multiplexer)

[IMFASFMultiplexer](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nn-wmcontainer-imfasfmultiplexer)