# IMiniportWaveRTOutputStream::SetWritePacket

## Description

SetWritePacket informs the driver that the OS has written valid data to the WaveRT buffer.

## Parameters

### `PacketNumber` [in]

The number of the packet written by the OS to the WaveRT buffer.

### `Flags` [in]

Additional attributes related to the packet or stream.

KSSTREAM_HEADER_OPTIONSF_ENDOFSTREAM - This flag indicates that this packet represents the end of the data stream.

### `EosPacketLength` [in]

The length of the EOS packet if KSSTREAM_HEADER_OPTIONSF_ENDOFSTREAM is specified in Flags. Zero is a valid value. If KSSTREAM_HEADER_OPTIONSF_ENDOFSTREAM is not specified in Flags, this parameter is ignored.

## Return value

`SetWritePacket` returns STATUS_SUCCESS if the call was successful. Otherwise, the function returns an appropriate error status code.

STATUS_DATA_LATE_ERROR – The driver returns this error if the OS passes a packet number that has already transferred or is currently transferring. In this case, a glitch condition has occurred. The driver may optionally use some of the data from the packet or continue playing out the data previously written to this packet number.

STATUS_DATA_OVERRUN – The driver returns this error if the OS passes a packet number that is higher than can be stored in the WaveRT buffer. In this case, a glitch condition has occurred. The driver may optionally ignore the data in the packet.

STATUS_INVALID_DEVICE_STATE – The driver returns this error if the OS calls this routine after a previously setting the KSSTREAM_HEADER_OPTIONSF_ENDOFSTREAM flag.

STATUS_INVALID_PARAMETER – The driver returns this error if it finds any other parameter invalid, aside from the specific cases for other error status. This includes any Flag values not specifically defined above.

## Remarks

After the OS calls this routine, the driver may optionally use the provided information to optimize the hardware transfer. For example, the driver might optimize DMA transfers, or program hardware to stop transfer at the end of the specified packet in case the OS does not call this routine again to inform the driver of another packet. This can mitigate audible effects of underflow, for example introducing an audible gap rather than repeating a circular buffer. The driver however is still obligated to increase its internal packet counter and signal notification events at a nominal real time rate.

Except when the OS specifies the KSSTREAM_HEADER_OPTIONSF_ENDOFSTREAM flag, the packet size is the WaveRT buffer size divided by the NotificationCount passed to [IMiniportWaveRTStreamNotification::AllocateBufferWithNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iminiportwavertstreamnotification-allocatebufferwithnotification).

Depending on hardware capabilities, if the KSSTREAM_HEADER_OPTIONSF_ENDOFSTREAM flag is specified, the driver may silence-fill a portion of the WaveRT buffer that follows the EOS packet in case the hardware transfers data beyond the EOS position.

## See also

[IMiniportWaveRTOutputStream](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iminiportwavertoutputstream)