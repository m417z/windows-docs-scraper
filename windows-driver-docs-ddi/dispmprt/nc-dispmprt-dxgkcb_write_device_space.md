# DXGKCB_WRITE_DEVICE_SPACE callback function

## Description

The **DxgkCbWriteDeviceSpace** function writes to a device configuration space or the expansion ROM of a display adapter.

## Parameters

### `DeviceHandle` [in]

A handle that represents a display adapter. The display miniport driver previously obtained this handle in the **DeviceHandle** member of the [DXGKRNL_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgkrnl_interface) structure that was passed to [DxgkDdiStartDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_start_device).

### `DataType` [in]

The type of write transaction to be performed. This parameter must be one of the following values, which are defined in *Dispmprt.h*:

#### DXGK_WHICHSPACE_BRIDGE

Write to the parent bus device's configuration space.

#### DXGK_WHICHSPACE_CONFIG

Write to the display adapter's configuration space.

#### DXGK_WHICHSPACE_MCH

Write to the configuration space of a memory controller hub that is a peer to the adapter's parent bus.

#### DXGK_WHICHSPACE_ROM

Write to the display adapter's expansion ROM.

### `Buffer` [in]

A pointer to a buffer that supplies the data to be written to the configuration space.

### `Offset` [in]

The offset, in bytes, into the configuration space, at which the write transaction begins.

### `Length` [in]

The number of bytes to be written.

### `BytesWritten` [out]

A pointer to a ULONG-typed variable that receives the number of bytes actually written.

## Return value

**DxgkCbWriteDeviceSpace** returns one of the following values:

|Return code|Description|
|--- |--- |
|STATUS_SUCCESS|The function succeeded.|
|STATUS_INVALID_PARAMETER|The DeviceHandle, DataType, or Buffer parameter is invalid.|
|STATUS_UNSUCCESSFUL|The function was unable to write the data.|

## See also

[DxgkCbReadDeviceSpace](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkcb_read_device_space)