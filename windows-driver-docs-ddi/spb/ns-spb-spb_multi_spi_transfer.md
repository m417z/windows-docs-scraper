## Description

The **SPB_MULTI_SPI_TRANSFER** structure describes a SPI I/O operation which is to be executed using a multi-SPI transfer mode such as Dual or Quad SPI.

## Members

### `Header`

A **SPB_MULTI_SPI_TRANSFER_HEADER** structure containing the parameters of the transfer.

### `TransferPhaseCount`

The number of transfer phases present in the transfer structure. For a read operation, this should be set to 2 (representing a read phase, then a write phase). For a write operation, this should be set to 1 (representing solely a write phase).

### `TransferPhases`

An array of **SPB_TRANSFER_LIST_ENTRY** structures, representing the phases of the transfer.

## Remarks

If this structure is used directly (rather than **SPB_MULTI_SPI_WRITE_TRANSFER** or **SPB_MULTI_SPI_READ_TRANSFER**), it must be initialized using the **SPB_MULTI_SPI_TRANSFER_INIT** helper function.

This structure (and the associated header) allows for the following to be specified:

- Dual or quad SPI transfer modes.
- One or two transfer phases - a _write_ phase, followed by an optional _read_ phase.
- A variable number of bytes to be transmitted at the beginning of the _write_ phase in single-SPI mode, before switching to the specified multi-SPI mode.
- Where a _read_ phase is provided, a variable number of _wait cycles_ between _write_ and _read_ phases - clock cycles where no data is to be transferred.

The following restrictions apply to this structure:

- The **TransferPhases** structure in the request must contain exactly one or two entries. The first entry describes a buffer that contains data to write to the device. The second, optional, entry describes a buffer used to hold data read from the device.
- The direction of these **TransferPhases** should be set to **SpbTransferDirectionToDevice** and **SpbTransferDirectionFromDevice** respectively.
- Each **SPB_TRANSFER_LIST_ENTRY** structure in the transfer list must specify a **DelayInUs** value of zero.

## See also

- [SPB_MULTI_SPI_TRANSFER_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/spb/nf-spb-spb_multi_spi_transfer_init)