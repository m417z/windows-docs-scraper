## Description

The **SPB_MULTI_SPI_TRANSFER_INIT** function initializes an [SPB_MULTI_SPI_TRANSFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/spb/ns-spb-spb_multi_spi_transfer) structure.

## Parameters

### `SpiTransfer`

A pointer to the **SPB_MULTI_SPI_TRANSFER** structure that is to be initialized. This structure includes a single transfer phase - an additional transfer phase should be provided when using this function to initialize a two-phase read operation.

### `Mode`

An [SPB_MULTI_SPI_TRANSFER_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/spb/ne-spb-spb_multi_spi_transfer_mode) enumeration value, specifying the line mode of the multi-SPI transfer to be used by a bus driver to communicate with a peripheral device.

### `TransferPhaseCount`

The number of phases in the multi-SPI transfer. For a read operation, this should be set to 2, representing a read phase, then a write phase. For a write operation, this should be set to 1, representing solely a write phase.

### `WritePhaseSingleSpiByteCount`

The count of bytes at the beginning of the write phase to be transferred in single-SPI mode, before line mode switch to the mode specified in the Mode member of this struct.

### `WaitCycleByteCount`

The number of wait cycles represented as the number of bytes, representing multi-SPI transfer cycles - e.g. 1 byte => 8 bits => 2 clock cycles in quad-SPI mode, between the write phase and read phase of the transfer. These wait cycle bytes should be present, and of an undefined value at the end of the WritePhaseBuffer. This should be set to 0 if the transfer does not have a read phase.

## Remarks

Typically, this function should not be called directly, instead [SPB_MULTI_SPI_READ_TRANSFER_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/spb/nf-spb-spb_multi_spi_read_transfer_init) or [SPB_MULTI_SPI_WRITE_TRANSFER_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/spb/nf-spb-spb_multi_spi_write_transfer_init) may be used as appropriate.

## See also

- [SPB_MULTI_SPI_TRANSFER_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/spb/ne-spb-spb_multi_spi_transfer_mode)
- [SPB_MULTI_SPI_TRANSFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/spb/ns-spb-spb_multi_spi_transfer)
- [SPB_MULTI_SPI_READ_TRANSFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/spb/ns-spb-spb_multi_spi_read_transfer)
- [SPB_MULTI_SPI_READ_TRANSFER_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/spb/nf-spb-spb_multi_spi_read_transfer_init)
- [SPB_MULTI_SPI_WRITE_TRANSFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/spb/ns-spb-spb_multi_spi_write_transfer)
- [SPB_MULTI_SPI_WRITE_TRANSFER_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/spb/nf-spb-spb_multi_spi_write_transfer_init)