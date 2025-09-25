# DlSetBusData function

## Description

Sets bus-configuration data for an adapter on a dynamically configurable I/O bus with a published, standard interface.

## Parameters

### `DeviceHandle`

A handle that represents a display adapter.

### `BusDataType`

Specifies the type of bus data to be set.

### `SlotNumber`

For a *BusDataType* value that specifies the location of the device on the bus. This parameter should be zero for all other bus types.

### `Buffer`

Pointer to a caller-supplied storage area with configuration information specific to *BusDataType*.

### `Offset`

Specifies the byte offset within the PCI_COMMON_CONFIG structure at which the caller-supplied configuration values begin. A miniport driver can use PCI_COMMON_HDR_LENGTH to specify the offset of the device-specific area in PCI_COMMON_CONFIG.

### `Length`

Specifies the number of bytes in *Buffer*.

## Return value

This function returns ULONG.

## Remarks

## See also