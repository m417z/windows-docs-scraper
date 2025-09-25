## Description

The **SPB_MULTI_SPI_WRITE_TRANSFER** structure describes a write operation to be executed in a Multi-SPI (e.g. Dual SPI or Quad SPI) mode. It is comprised of a **SPB_MULTI_SPI_TRANSFER** structure containing the parameters and write phase of the transfer.

## Members

### `SpiTransfer`

A [SPB_MULTI_SPI_TRANSFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/spb/ns-spb-spb_multi_spi_transfer) structure containing the parameters of the transfer, and the write phase buffer.

## Remarks

After initialization using **SPB_MULTI_SPI_WRITE_TRANSFER_INIT**, a peripheral driver may access **SpiTransfer.TransferPhases[]** to configure the transfer buffers.

## See also

- [SPB_MULTI_SPI_TRANSFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/spb/ns-spb-spb_multi_spi_transfer)
- [SPB_MULTI_SPI_WRITE_TRANSFER_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/spb/nf-spb-spb_multi_spi_write_transfer_init)