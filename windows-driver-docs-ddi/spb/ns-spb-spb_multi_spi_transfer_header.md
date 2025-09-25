## Description

The **SPB_MULTI_SPI_TRANSFER_HEADER** structure describes a SPI transfer to be executed in a Multi-SPI (e.g. Dual SPI or Quad SPI) mode. This structure should be accessed by a controller driver to retrieve the parameters of a multi-SPI transfer.

## Members

### `Size`

The size, in bytes, of the parent **SPB_MULTI_SPI_TRANSFER** structure, not including any additional **TransferPhases** entries following the parent structure.

### `Mode`

An [SPB_MULTI_SPI_TRANSFER_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/spb/ne-spb-spb_multi_spi_transfer_mode) enumeration value, specifying the line mode of the multi-SPI transfer to be used by a bus driver to communicate with a peripheral device.

### `WritePhaseSingleSpiByteCount`

The count of bytes at the beginning of the write phase to be transferred in single-SPI mode, before line mode switch to the mode specified in the Mode member of this struct.

### `WaitCycleByteCount`

The number of wait cycles represented as the number of bytes (representing multi-SPI transfer cycles - e.g. 1 byte => 8 bits => 2 clock cycles in quad-SPI mode), between the write phase and read phase of the transfer. These wait cycle bytes should be present, and of an undefined value at the end of the WritePhaseBuffer.

## Remarks

The **SPB_MULTI_SPI_READ_TRANSFER_INIT**, **SPB_MULTI_SPI_WRITE_TRANSFER_INIT**, or **SPB_MULTI_SPI_TRANSFER_INIT** functions should be used by a peripheral driver to initialize the header of a **SPB_MULTI_SPI_TRANSFER** and should not be accessed directly. A controller driver accesses this structure to retrieve the parameters of a Multi-SPI transfer.

## See also

- [SPB_MULTI_SPI_TRANSFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/spb/ns-spb-spb_multi_spi_transfer)
- [SPB_MULTI_SPI_READ_TRANSFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/spb/ns-spb-spb_multi_spi_read_transfer)
- [SPB_MULTI_SPI_READ_TRANSFER_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/spb/nf-spb-spb_multi_spi_read_transfer_init)
- [SPB_MULTI_SPI_WRITE_TRANSFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/spb/ns-spb-spb_multi_spi_write_transfer)
- [SPB_MULTI_SPI_WRITE_TRANSFER_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/spb/nf-spb-spb_multi_spi_write_transfer_init)