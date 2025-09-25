## Description

The **SPB_MULTI_SPI_TRANSFER_MODE** enumeration specifies a type of multi-SPI transfer to be used by a bus driver to communicate with a peripheral device.

## Constants

### `SpbMultiSpiTransferModeInvalid`

Reserved for use by the operating system.

### `SpbMultiSpiTransferModeDualSpi`

The transfer should be transmitted in the controller's Dual-SPI transfer mode.

### `SpbMultiSpiTransferModeQuadSpi`

The transfer should be transmitted in the controller's Quad-SPI transfer mode.

### `SpbMultiSpiTransferModeMax`

Reserved for use by the operating system.

## Remarks

The **Mode** member of the [SPB_MULTI_SPI_TRANSFER_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/spb/ns-spb-spb_multi_spi_transfer_header) structure is an **SPB_MULTI_SPI_TRANSFER_MODE** enumeration value.

## See also

- [SPB_MULTI_SPI_TRANSFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/spb/ns-spb-spb_multi_spi_transfer)