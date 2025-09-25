# DlReadDeviceSpace function

## Description

Reads from a device configuration space or the expansion ROM of a display adapter.

## Parameters

### `DeviceHandle`

A handle that represents a display adapter.

### `DataType`

The type of read transaction to be performed.

### `SlotNumber`

### `Buffer`

A pointer to a caller-allocated buffer that receives the data read from the configuration space or ROM.

### `Offset`

The offset, into the configuration space or the expansion ROM, at which the read transaction begins.

### `Length`

The number of bytes to be read.

## Return value

This function returns ULONG.

## Remarks

## See also