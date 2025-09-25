# _WDF_DEVICE_IO_TYPE enumeration (wdfdevice.h)

## Description

[Applies to KMDF and UMDF]

The **WDF_DEVICE_IO_TYPE** enumeration is used to specify a [method for accessing data buffers](https://learn.microsoft.com/windows-hardware/drivers/kernel/methods-for-accessing-data-buffers).

## Constants

### `WdfDeviceIoUndefined:0`

Reserved for system use.

### `WdfDeviceIoNeither`

**UMDF** This value is not used by UMDF drivers. A UMDF driver can access device I/O control requests that specify the METHOD_NEITHER buffer access method by setting the **UmdfMethodNeitherAction** INF directive and using **WdfDeviceIoBuffered** or **WdfDeviceIoDirect**. For more information, see [Specifying WDF Directives in INF Files](https://learn.microsoft.com/windows-hardware/drivers/wdf/specifying-wdf-directives-in-inf-files).

**KMDF** Neither buffered nor direct I/O will be used to access data buffers.

### `WdfDeviceIoBuffered`

Buffered I/O will be used to access data buffers.

### `WdfDeviceIoDirect`

Direct I/O will be used to access data buffers.

### `WdfDeviceIoBufferedOrDirect:4`

This value is not used by KMDF drivers.

**UMDF** Buffered I/O or direct I/O will be used to access data buffers.

### `WdfDeviceIoMaximum`

## Remarks

The **WDF_DEVICE_IO_TYPE** enumeration is used to specify buffer access method types in the [WDF_IO_TYPE_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ns-wdfdevice-_wdf_io_type_config) structure.

The [WDF_IO_TYPE_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ns-wdfdevice-_wdf_io_type_config) structure is used as input to [WdfDeviceInitSetIoTypeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceinitsetiotypeex) and [WdfDeviceInitSetIoType](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceinitsetiotype).

## See also

[WDF_IO_TYPE_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ns-wdfdevice-_wdf_io_type_config)

[WdfDeviceInitSetIoType](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceinitsetiotype)

[WdfDeviceInitSetIoTypeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceinitsetiotypeex)