# DXGK_DSI_PACKET structure

## Description

An OEM panel driver uses **DXGK_DSI_PACKET** structures to transmit Digital Serial Interface (DSI) packets to the bus driver (graphics kernel).

## Members

### `DataId`

8-bit value, where the lower 6 bits form the DataType and the higher 2 bits are VirtualChannel.

### `DataType`

Type of data being transmitted, which implicitly defines the transaction as a read or a write as well as the number of parameters and whether the transaction is formed as a short or long packet.

### `VirtualChannel`

Indicates the sub-unit of the peripheral being addressed. Can be one of 0, 1, 2, or 3.

### `Data0`

8-bit value used in short packets to transfer parameters. Short packets have 0, 1, or 2 bytes of parameters, where the number and meaning is determined by the DataType.

### `Data1`

8-bit value used in short packets to transfer parameters. Short packets have 0, 1, or 2 bytes of parameters, where the number and meaning is determined by the DataType.

### `LongWriteWordCount`

Word count, in bytes, of the Payload for a write long packet.

### `EccFiller`

An 8-bit field which occupies the space that the Error Correction Code (ECC) will take in the sequence of transmitted bytes. The fourth byte of the transmission is always an ECC and for long writes, the payload directly follows the ECC so this filler allows a long write command to be constructed in memory as a complete command. It is the responsibility of the graphics driver to overwrite the filler value with the correct ECC value prior to transmission.

### `Payload`

Array of 8 bytes which allows for sequences of small writes to be sent as an array of packets in the same transmission but limits the size of the data. The final packet in a transmission can append further data in memory directly after the last byte of the embedded Payload. Read packets are only permitted as the last one in a transmission but may be in the form of a long or short packet and either way, the read data should be placed in the Payload buffer, with extra space in the buffer to accommodate longer responses.

## Remarks

The panel driver calls [**IOCTL_MIPI_DSI_TRANSMISSION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvdeo/ni-ntddvdeo-ioctl_mipi_dsi_transmission) with an array of **DSI_PACKET** structures in a [**DXGK_DSI_TRANSMISSION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-dxgk_dsi_transmission) structure.

## See also

[**IOCTL_MIPI_DSI_QUERY_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvdeo/ni-ntddvdeo-ioctl_mipi_dsi_query_caps)

[**IOCTL_MIPI_DSI_RESET**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvdeo/ni-ntddvdeo-ioctl_mipi_dsi_reset)

[**IOCTL_MIPI_DSI_TRANSMISSION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddvdeo/ni-ntddvdeo-ioctl_mipi_dsi_transmission)