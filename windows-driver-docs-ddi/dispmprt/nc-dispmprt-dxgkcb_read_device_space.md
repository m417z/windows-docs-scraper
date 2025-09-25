# DXGKCB_READ_DEVICE_SPACE callback function

## Description

The **DxgkCbReadDeviceSpace** function reads from a device configuration space or the expansion ROM of a display adapter.

## Parameters

### `DeviceHandle` [in]

A handle that represents a display adapter. The display miniport driver previously obtained this handle in the **DeviceHandle** member of the [DXGKRNL_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgkrnl_interface) structure that was passed to [DxgkDdiStartDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_start_device).

### `DataType` [in]

The type of read transaction to be performed. This parameter must be one of the following values, which are defined in *Dispmprt.h*.

#### DXGK_WHICHSPACE_BRIDGE

Read from the PCI Express (PCIe) root port's configuration space.

#### DXGK_WHICHSPACE_CONFIG

Read from the display adapter's configuration space.

#### DXGK_WHICHSPACE_MCH

Read from the configuration space of a memory controller hub that is a peer to the adapter's parent bus.

#### DXGK_WHICHSPACE_ROM

Read from the display adapter's expansion ROM.

### `Buffer` [in]

A pointer to a caller-allocated buffer that receives the data read from the configuration space or ROM.

### `Offset` [in]

The offset, into the configuration space or the expansion ROM, at which the read transaction begins.

### `Length` [in]

The number of bytes to be read.

### `BytesRead` [out]

A pointer to a ULONG-typed variable that receives the number of bytes actually read.

## Return value

**DxgkCbReadDeviceSpace** returns one of the following values:

|Return code|Description|
|--- |--- |
|STATUS_SUCCESS|The function succeeded.|
|STATUS_INVALID_PARAMETER|The DeviceHandle, DataType, or Buffer parameter is invalid.|
|STATUS_UNSUCCESSFUL|The function was unable to read the data.|

## See also

[DxgkCbWriteDeviceSpace](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkcb_write_device_space)