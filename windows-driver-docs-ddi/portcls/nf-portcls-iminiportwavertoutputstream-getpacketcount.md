# IMiniportWaveRTOutputStream::GetPacketCount

## Description

GetPacketCount returns the (1-based) count of packets completely transferred from the WaveRT buffer into hardware.

## Parameters

### `pPacketCount` [out]

pPacketCount returns the number of packets completely transferred from the WaveRT buffer into hardware.

## Return value

`GetPacketCount` returns STATUS_SUCCESS if the call was successful. Otherwise, the function returns an appropriate error status code.

## Remarks

From the packet count, the OS can derive the stream position of the packets it writes into the WaveRT buffer. The OS can also derive the WaveRT buffer position of the next packet to write within the WaveRT buffer. For WaveRT drivers, the driver signals a single notification event as it transfers data from each packet of the WaveRT buffer. Therefore the event alone cannot indicate which packet within the WaveRT buffer is being transferred. In normal operation this is not a concern but in underflow cases correction is more easily achieved by querying the packet count from which the OS can determine which packet to write next.

The returned PacketCount indicates the (1-based) count of packets completely transferred from the WaveRT buffer into hardware. From this, the OS can determine the 0-based number of the packet currently being transferred, and ensure that it writes ahead of that packet. For example, if the packet count is 5, then 5 packets have completely transferred. That is, packets 0-4 have completely transferred. Therefore packet 5 is in progress, and the OS should write packet 6. If the notification count for the WaveRT buffer is 2, then packet 6 would be at offset 0 within the WaveRT buffer (because 6 modulo 2 is 0, and 0 times the packet size is 0).

The OS may get this property at any time. However it generally gets this property only periodically or after the driver returns a dataflow error (STATUS_DATA_LATE_ERROR, STATUS_DATA_OVERRUN) from SetWritePacket() in order to resynchronize with the driver.

The driver should reset the packet count to 0 when the stream is in KSSTATE_STOP.

## See also

[IMiniportWaveRTOutputStream](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iminiportwavertoutputstream)