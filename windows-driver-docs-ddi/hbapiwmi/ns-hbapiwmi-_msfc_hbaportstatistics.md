# _MSFC_HBAPortStatistics structure

## Description

The MSFC_HBAPortStatistics structure contains statistics information about a port.

## Members

### `SecondsSinceLastReset`

Contains the number of seconds since the statistics were last reset.

### `TxFrames`

Contains the number of total transmitted fibre channel frames across all protocols and classes.

### `TxWords`

Contains the number of total transmitted fibre channel words across all protocols and classes.

### `RxFrames`

Contains the number of received fibre channel frames across all protocols and classes.

### `RxWords`

Contains the number of received fibre channel words across all protocols and classes.

### `LIPCount`

Contains the number of loop initialization primitive sequence (LIP) events that have occurred on a arbitrated loop.

### `NOSCount`

Contains the number of nonoperational state primitive sequence (NOS) events that have occurred on the switched fabric.

### `ErrorFrames`

Contains the number of frames that have been received in error.

### `DumpedFrames`

Contains the number of frames that were lost due to a lack of host buffers available.

### `LinkFailureCount`

Contains the link failure count.

### `LossOfSyncCount`

Contains the loss of synchronization count.

### `LossOfSignalCount`

Contains the loss of signal count.

### `PrimitiveSeqProtocolErrCount`

Contains the primitive sequence protocol error count.

### `InvalidTxWordCount`

Contains a count of the number of invalid transmissions.

### `InvalidCRCCount`

Contains a count of the number frames with invalid cyclic redundancy checksums.

## See also

[MSFC_HBAPortStatistics WMI Class](https://learn.microsoft.com/windows-hardware/drivers/storage/msfc-hbaportstatistics-wmi-class)