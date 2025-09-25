# _WDF_REQUEST_TYPE enumeration (wdfrequest.h)

## Description

[Applies to KMDF and UMDF]

The **WDF_REQUEST_TYPE** enumeration type identifies types of requests that a framework request object might contain.

## Constants

### `WdfRequestTypeCreate:0x0`

The request object represents an [IRP_MJ_CREATE](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-create) request. The framework delivers this type of request to a driver's [EvtDeviceFileCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_file_create) callback function.

### `WdfRequestTypeCreateNamedPipe:0x1`

The request object represents an **IRP_MJ_CREATE_NAMED_PIPE** request. The framework does not handle this type of request.

### `WdfRequestTypeClose:0x2`

The request object represents an [IRP_MJ_CLOSE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-close) request. The framework delivers this type of request to a driver's [EvtFileClose](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_file_close) callback function.

### `WdfRequestTypeRead:0x3`

The request object represents an [IRP_MJ_READ](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-read) request. The framework delivers this type of request to a driver's [request handler](https://learn.microsoft.com/windows-hardware/drivers/wdf/request-handlers).

### `WdfRequestTypeWrite:0x4`

The request object represents an [IRP_MJ_WRITE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-write) request. The framework delivers this type of request to a driver's [request handler](https://learn.microsoft.com/windows-hardware/drivers/wdf/request-handlers).

### `WdfRequestTypeQueryInformation:0x5`

The request object represents an [IRP_MJ_QUERY_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-query-information) request. The framework does not handle this type of request.

### `WdfRequestTypeSetInformation:0x6`

The request object represents an [IRP_MJ_SET_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-set-information) request. The framework does not handle this type of request.

### `WdfRequestTypeQueryEA:0x7`

The request object represents an [IRP_MJ_QUERY_EA](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-query-ea) request. The framework does not handle this type of request.

### `WdfRequestTypeSetEA:0x8`

The request object represents an [IRP_MJ_SET_EA](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-set-ea) request. The framework does not handle this type of request.

### `WdfRequestTypeFlushBuffers:0x9`

The request object represents an [IRP_MJ_FLUSH_BUFFERS](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-flush-buffers) request. The framework does not handle this type of request.

### `WdfRequestTypeQueryVolumeInformation:0xa`

The request object represents an [IRP_MJ_QUERY_VOLUME_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-query-volume-information) request. The framework does not handle this type of request.

### `WdfRequestTypeSetVolumeInformation:0xb`

The request object represents an [IRP_MJ_SET_VOLUME_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-set-volume-information) request. The framework does not handle this type of request.

### `WdfRequestTypeDirectoryControl:0xc`

The request object represents an [IRP_MJ_DIRECTORY_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-directory-control) request. The framework does not handle this type of request.

### `WdfRequestTypeFileSystemControl:0xd`

The request object represents an [IRP_MJ_FILE_SYSTEM_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-file-system-control) request. The framework does not handle this type of request.

### `WdfRequestTypeDeviceControl:0xe`

The request object represents an [IRP_MJ_DEVICE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-device-control) request. The framework delivers this type of request to a driver's [request handler](https://learn.microsoft.com/windows-hardware/drivers/wdf/request-handlers).

### `WdfRequestTypeDeviceControlInternal:0xf`

The request object represents an [IRP_MJ_INTERNAL_DEVICE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-internal-device-control) request. The framework delivers this type of request to a driver's [request handler](https://learn.microsoft.com/windows-hardware/drivers/wdf/request-handlers).

### `WdfRequestTypeShutdown:0x10`

The request object represents an [IRP_MJ_SHUTDOWN](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-shutdown) request. The framework handles this type of request for the driver, but the framework also calls the driver's [EvtDeviceShutdownNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfcontrol/nc-wdfcontrol-evt_wdf_device_shutdown_notification) callback function, if it exists.

### `WdfRequestTypeLockControl:0x11`

The request object represents an [IRP_MJ_LOCK_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-lock-control) request. The framework does not handle this type of request.

### `WdfRequestTypeCleanup:0x12`

The request object represents an [IRP_MJ_CLEANUP](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-cleanup) request. The framework delivers this type of request to a driver's [EvtFileCleanup](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_file_cleanup) callback function.

### `WdfRequestTypeCreateMailSlot:0x13`

The request object represents an **IRP_MJ_CREATE_MAILSLOT** request. The framework does not handle this type of request.

### `WdfRequestTypeQuerySecurity:0x14`

The request object represents an [IRP_MJ_QUERY_SECURITY](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-query-security) request. The framework does not handle this type of request.

### `WdfRequestTypeSetSecurity:0x15`

The request object represents an [IRP_MJ_SET_SECURITY](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-set-security) request. The framework does not handle this type of request.

### `WdfRequestTypePower:0x16`

The request object represents an [IRP_MJ_POWER](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-power) request. The framework handles this type of request for the driver, but the framework also calls the driver's [general](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/), [FDO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/), and [PDO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/) callback functions for Plug and Play (PnP) and power management, if the callback functions exist.

### `WdfRequestTypeSystemControl:0x17`

The request object represents an [IRP_MJ_SYSTEM_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-system-control) request. The framework handles this type of request for the driver, if the driver supports [Windows Management Instrumentation (WMI)](https://learn.microsoft.com/windows-hardware/drivers/wdf/supporting-wmi-in-kmdf-drivers).

### `WdfRequestTypeDeviceChange:0x18`

The request object represents an **IRP_MJ_DEVICE_CHANGE** request. The framework does not handle this type of request.

### `WdfRequestTypeQueryQuota:0x19`

The request object represents an [IRP_MJ_QUERY_QUOTA](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-query-quota) request. The framework does not handle this type of request.

### `WdfRequestTypeSetQuota:0x1A`

The request object represents an [IRP_MJ_SET_QUOTA](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-set-quota) request. The framework does not handle this type of request.

### `WdfRequestTypePnp:0x1B`

The request object represents an [IRP_MJ_PNP](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-pnp) request. The framework handles this type of request for the driver, but the framework also calls the driver's [general](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/), [FDO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/), and [PDO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/) callback functions for PnP and power management, if the callback functions exist.

### `WdfRequestTypeOther:0x1C`

A driver receives this request type in its [CompletionRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nc-wdfrequest-evt_wdf_request_completion_routine) event callback function when requests formatted with [WdfIoTargetFormatRequestForInternalIoctlOthers](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetformatrequestforinternalioctlothers) are completed.

### `WdfRequestTypeUsb:0x40`

The target device is a USB device. (This value is used only in [WDF_REQUEST_COMPLETION_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/ns-wdfrequest-_wdf_request_completion_params) structures.)

### `WdfRequestTypeNoFormat:0xFF`

The request object's type has not been specified.

### `WdfRequestTypeMax`

The maximum value that has been assigned to a valid IRP major function code.

## Remarks

The **WDF_REQUEST_TYPE** enumeration type is used in the [WDF_REQUEST_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/ns-wdfrequest-_wdf_request_parameters) and [WDF_REQUEST_COMPLETION_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/ns-wdfrequest-_wdf_request_completion_params) structures.

For information about how a framework-based driver can handle request types that the framework does not support, see [Handling an IRP that the Framework Does Not Support](https://learn.microsoft.com/windows-hardware/drivers/wdf/handling-an-irp-that-the-framework-does-not-support).

For the UMDF version of this enumeration, see [WDF_REQUEST_TYPE (UMDF)](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/ne-wdfrequest-_wdf_request_type).

## See also

[EvtDeviceFileCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_file_create)

[EvtDeviceShutdownNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfcontrol/nc-wdfcontrol-evt_wdf_device_shutdown_notification)

[EvtFileCleanup](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_file_cleanup)

[EvtFileClose](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_file_close)