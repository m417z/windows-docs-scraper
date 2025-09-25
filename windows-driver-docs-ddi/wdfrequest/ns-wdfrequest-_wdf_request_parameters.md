# _WDF_REQUEST_PARAMETERS structure

## Description

[Applies to KMDF and UMDF]

The **WDF_REQUEST_PARAMETERS** structure receives parameters that are associated with an I/O request.

## Members

### `Size`

The size, in bytes, of this structure.

### `MinorFunction`

The IRP minor function code, if any, that is associated with the I/O request. Some major function codes have associated minor function codes.

### `Type`

A [WDF_REQUEST_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/ne-wdfrequest-_wdf_request_type)-typed value that identifies the I/O request's type.

### `Parameters`

Parameters that are unique for each IRP major function code. This member contains a subset of the Parameters member of the [IO_STACK_LOCATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_stack_location) structure.

### `Parameters.Create`

Parameters for [IRP_MJ_CREATE](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-create).

### `Parameters.Create.SecurityContext`

### `Parameters.Create.Options`

### `Parameters.Create.FileAttributes`

### `Parameters.Create.ShareAccess`

### `Parameters.Create.EaLength`

### `Parameters.Read`

Parameters for [IRP_MJ_READ](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-read).

### `Parameters.Read.Length`

### `Parameters.Read.Key`

### `Parameters.Read.DeviceOffset`

### `Parameters.Write`

Parameters for [IRP_MJ_WRITE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-write).

### `Parameters.Write.Length`

### `Parameters.Write.Key`

### `Parameters.Write.DeviceOffset`

### `Parameters.DeviceIoControl`

Parameters for [IRP_MJ_DEVICE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-device-control) and [IRP_MJ_INTERNAL_DEVICE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-internal-device-control).

### `Parameters.DeviceIoControl.OutputBufferLength`

### `Parameters.DeviceIoControl.InputBufferLength`

### `Parameters.DeviceIoControl.IoControlCode`

### `Parameters.DeviceIoControl.Type3InputBuffer`

### `Parameters.Others`

Use of this member is defined by the driver stack.

### `Parameters.Others.Arg1`

### `Parameters.Others.Arg2`

### `Parameters.Others.IoControlCode`

### `Parameters.Others.Arg4`

## Remarks

The **WDF_REQUEST_PARAMETERS** structure is used as input to [WdfRequestGetParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestgetparameters). Drivers must call [WDF_REQUEST_PARAMETERS_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdf_request_parameters_init) to initialize this structure before they call **WdfRequestGetParameters**.

## See also

[IO_STACK_LOCATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_stack_location)

[WDF_REQUEST_PARAMETERS_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdf_request_parameters_init)

[WdfRequestGetParameters](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestgetparameters)