# MIPI_DSI_TRANSMISSION structure

## Description

The **MIPI_DSI_TRANSMISSION** structure is used to describe a MIPI (Mobile Industry Processor Interface) DSI (Display Serial Interface) transmission request that contains one or more DSI packets to be sent to the display device.

## Members

### `TotalBufferSize`

[in] The total size of the buffer that contains the transmission request, in bytes.

### `PacketCount`

[in] The number of packets in the transmission request.

### `FailedPacket`

[out] Index of the first failed packet in the transmission, if any failures occur.

### `TransmissionMode`

[in] Transmission mode.

### `ReportMipiErrors`

[in] When set, indicates that MIPI protocol errors should be reported.

### `ClearMipiErrors`

[in] When set, indicates that MIPI protocol errors should be cleared after being reported.

### `SecondaryPort`

[in] Indicates whether the transmission is for a secondary port.

### `ManufacturingMode`

[in] Indicates whether the transmission is happening in a special manufacturing mode.

### `Reserved`

Reserved.

### `ReadWordCount`

[out] Number of words read during a read operation.

### `FinalCommandExtraPayload`

[in] Size of any extra payload that should be sent with the final command.

### `MipiErrors`

[out] Errors reported by the MIPI DSI hardware, if any.

### `HostErrors`

[out] Errors reported by the host processor or controller that is managing the transmission, if any.

### `Packets`

Array of **PacketCount** [**MIPI_DSI_PACKET**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvdeo/ns-ntddvdeo-mipi_dsi_packet) structures that describe the packets to be transmitted/modified.

## Remarks

## See also