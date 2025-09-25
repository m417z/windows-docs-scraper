# _WDF_REQUEST_FORWARD_OPTIONS structure

## Description

[Applies to KMDF only]

The **WDF_REQUEST_FORWARD_OPTIONS** structure contains options for requeuing an I/O request from a child device's I/O queue to the parent device's I/O queue.

## Members

### `Size`

The size, in bytes, of this structure.

### `Flags`

A bitwise OR of [WDF_REQUEST_FORWARD_OPTIONS_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/ne-wdfrequest-_wdf_request_forward_options_flags)-typed flags.

## Remarks

The **WDF_REQUEST_FORWARD_OPTIONS** structure is used as input to the [WdfRequestForwardToParentDeviceIoQueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestforwardtoparentdeviceioqueue) method.

Your driver must call [WDF_REQUEST_FORWARD_OPTIONS_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdf_request_forward_options_init) to initialize the **WDF_REQUEST_FORWARD_OPTIONS** structure before the driver calls [WdfRequestForwardToParentDeviceIoQueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestforwardtoparentdeviceioqueue).

## See also

[WDF_REQUEST_FORWARD_OPTIONS_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/ne-wdfrequest-_wdf_request_forward_options_flags)