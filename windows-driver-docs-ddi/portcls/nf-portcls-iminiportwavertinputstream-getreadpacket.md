# IMiniportWaveRTInputStream::GetReadPacket

## Description

Returns information about captured data.

## Parameters

### `PacketNumber` [out]

Returns the packet number relative to the start of capture.

### `Flags` [out]

Reserved for future use. Must be set to 0.

### `PerformanceCounterValue` [out]

Returns the performance counter value corresponding to the sampling instant of the first sample in the packet.

### `MoreData` [out]

 Returns **TRUE** if there is more data ready immediately. The OS may optionally immediately call this routine again after processing the packet to get the next packet information. If the driver returns **FALSE**, then capture is operating at real time.

## Return value

`GetReadPacket` returns STATUS_SUCCESS if the call was successful. Otherwise, the function returns an appropriate error status code.

 STATUS_DEVICE_NOT_READY - The driver returns this error if no new data is available.

## Remarks

Before reading captured audio data from the WaveRT buffer, the OS calls this routine to get information about the available data.

The packet number identifies a packet within the stream. This resets to zero when the stream is in KSSTATE_STOP. The number advances with each captured buffer. From the packet number the OS can derive the packet location within the WaveRT buffer and can also derive the stream position of the packet relative to start of stream.

The packet size is the WaveRT buffer size divided by the NotificationCount passed to [IMiniportWaveRTStreamNotification::AllocateBufferWithNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iminiportwavertstreamnotification-allocatebufferwithnotification). The OS may call this routine at any time. In normal operation, the OS calls this routine after the driver sets the buffer notification event or after a previous call returns true for MoreData. When the OS calls this routine, the driver may assume that the OS has finished reading all previous packets. If the hardware has captured enough data, the driver may immediately burst the next complete packet to the WaveRT buffer and set the buffer event again.In the case of capture overflow (when the OS does not read data quickly enough) the audio driver may drop or overwrite some audio data. The audio driver drops or overwrites oldest data first, The audio driver may continue to advance its internal packet counter even though the OS may not have read the data.

## See also

[IMiniportWaveRTInputStream](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iminiportwavertinputstream)