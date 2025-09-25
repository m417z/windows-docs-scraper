# MIRACAST_DATARATE_STATS structure

## Description

Contains info used in the wireless display (Miracast) [pfnDataRateNotify](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdispumdddi/nc-netdispumdddi-pfn_datarate_notification) function about the audio/video encoder bit rate and failed or retried Wi-Fi frames.

## Members

### `EncoderBitRate`

The bit rate, in bits per second, that the operating system recommends that the audio/video encoder uses.

### `CurrentMaxTxDataRate`

The theoretical maximum speed, in bits per second, reported by the Wi-Fi driver.

### `TransmittedFrameCount`

The total number of Wi-Fi frames that were sent with zero retries since the previous time step.

### `FailedFrameCount`

The total number of Wi-Fi frames that exhausted the maximum number of retries since the previous time step.

### `RetriedFrameCount`

The total number of Wi-Fi frames that succeeded after a single retry since the previous time step.

### `MultipleRetryFrameCount`

The total number of Wi-Fi frames that succeeded after more than one retry since the previous time step.