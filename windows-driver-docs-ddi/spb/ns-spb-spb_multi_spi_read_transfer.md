## Description

The **SPB_MULTI_SPI_READ_TRANSFER** structure describes a read operation to be executed in a Multi-SPI (e.g. Dual SPI or Quad SPI) mode. It is comprised of a **SPB_MULTI_SPI_TRANSFER** structure containing the parameters and first write phase of the transfer, and an additional transfer phase structure for the read phase of the transfer.

## Members

### `SpiTransfer`

A [SPB_MULTI_SPI_TRANSFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/spb/ns-spb-spb_multi_spi_transfer) structure containing the parameters of the transfer, and the write phase buffer.

### `ExtraTransfer`

An extra [SPB_TRANSFER_LIST_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/spb/ns-spb-spb_transfer_list_entry) structure containing the read phase buffer of the transfer operation.

## Remarks

After initialization using **SPB_MULTI_SPI_READ_TRANSFER_INIT**, a peripheral driver may access the member **SpiTransfer.TransferPhases[]** to configure the transfer buffers.

## See also

- [SPB_MULTI_SPI_TRANSFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/spb/ns-spb-spb_multi_spi_transfer)
- [SPB_MULTI_SPI_READ_TRANSFER_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/spb/nf-spb-spb_multi_spi_read_transfer_init)