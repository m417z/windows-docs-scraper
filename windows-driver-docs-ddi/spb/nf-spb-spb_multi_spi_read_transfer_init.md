## Description

The **SPB_MULTI_SPI_READ_TRANSFER_INIT** function initializes an [SPB_MULTI_SPI_READ_TRANSFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/spb/ns-spb-spb_multi_spi_read_transfer) structure.

## Parameters

### `SpiTransfer`

A pointer to the **SPB_MULTI_SPI_READ_TRANSFER** structure that is to be initialized.

### `Mode`

An [SPB_MULTI_SPI_TRANSFER_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/spb/ne-spb-spb_multi_spi_transfer_mode) enumeration value, specifying the line mode of the multi-SPI transfer to be used by a bus driver to communicate with a peripheral device.

### `WritePhaseSingleSpiByteCount`

The count of bytes at the beginning of the write phase to be transferred in single-SPI mode, before line mode switch to the mode specified in the Mode member of this struct.

### `WaitCycleByteCount`

The number of wait cycles represented as the number of bytes, representing multi-SPI transfer cycles - e.g. 1 byte => 8 bits => 2 clock cycles in quad-SPI mode, between the write phase and read phase of the transfer. These wait cycle bytes should be present, and of an undefined value at the end of the WritePhaseBuffer.

## Remarks

The **SPB_MULTI_SPI_READ_TRANSFER_INIT** function should be used to initialize multi-SPI read transfers. It initializes a **SPB_MULTI_SPI_READ_TRANSFER** structure with the two transfer phases required for a read operation.

## See also

- [SPB_MULTI_SPI_TRANSFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/spb/ns-spb-spb_multi_spi_transfer)
- [SPB_MULTI_SPI_READ_TRANSFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/spb/ns-spb-spb_multi_spi_read_transfer)
- [SPB_MULTI_SPI_TRANSFER_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/spb/ns-spb-spb_multi_spi_transfer_header)