# KSDISPATCH_TABLE structure

## Description

The KSDISPATCH_TABLE structure contains pointers to minidriver implemented IRP dispatch routines.

## Members

### `DeviceIoControl`

Specifies the minidriver's routine to dispatch [IRP_MJ_DEVICE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-device-control) IRPs to.

### `Read`

Specifies the minidriver's routine to dispatch [IRP_MJ_READ](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-read) IRPs to.

### `Write`

Specifies the minidriver's routine to dispatch [IRP_MJ_WRITE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-write) IRPs to.

### `Flush`

Specifies the minidriver's routine to dispatch [IRP_MJ_FLUSH_BUFFERS](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-flush-buffers) IRPs to.

### `Close`

Specifies the minidriver's routine to dispatch [IRP_MJ_CLOSE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-close) IRPs to.

### `QuerySecurity`

Specifies the minidriver's routine to dispatch [IRP_MJ_QUERY_SECURITY](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-query-security) IRPs to.

### `SetSecurity`

Specifies the minidriver's routine to dispatch [IRP_MJ_SET_SECURITY](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-set-security) IRPs to.

### `FastDeviceIoControl`

Specifies the minidriver's routine to dispatch fast device I/O control requests to.

### `FastRead`

Specifies the minidriver's routine to dispatch fast read requests to.

### `FastWrite`

Specifies the minidriver's routine to dispatch fast write requests to.

## Remarks

A pointer to a dispatch table is contained in the opaque object header that is the first element of data pointed to by the file object's **FsContext** field.

For more information about minidriver implemented IRP dispatch routines, see [KsSetMajorFunctionHandler](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kssetmajorfunctionhandler), and [DRIVER_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_driver_object).

## See also

[DRIVER_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_driver_object)

[KsSetMajorFunctionHandler](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kssetmajorfunctionhandler)