# _WDF_IO_TARGET_OPEN_TYPE enumeration

## Description

[Applies to KMDF and UMDF]

The **WDF_IO_TARGET_OPEN_TYPE** enumeration specifies how a driver identifies a remote I/O target when the driver calls [WdfIoTargetOpen](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetopen).

## Constants

### `WdfIoTargetOpenUndefined:0`

Reserved for system use.

### `WdfIoTargetOpenUseExistingDevice:1`

This value is supported by KMDF only.

The driver is identifying a remote I/O target by supplying a pointer to a Windows Driver Model (WDM) [DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object) structure.

### `WdfIoTargetOpenByName:2`

The driver is opening a remote I/O target by supplying a Unicode name string that represents an [object name](https://learn.microsoft.com/windows-hardware/drivers/kernel/object-names). This name can identify a device, file, or device interface.

### `WdfIoTargetOpenReopen:3`

The driver is reopening a remote I/O target after previously calling [WdfIoTargetCloseForQueryRemove](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetcloseforqueryremove). For more information, see the following Remarks section.

### `WdfIoTargetOpenLocalTargetByFile:4`

This value is supported by UMDF only.

**UMDF** The driver is opening a file handle that represents the lower stack (just like a local target), so that it can send a driver-created request down to the lower stack. A UMDF driver specifies this value when it calls [WDF_IO_TARGET_OPEN_PARAMS_INIT_OPEN_BY_FILE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdf_io_target_open_params_init_open_by_file).

## Remarks

The **WDF_IO_TARGET_OPEN_TYPE** enumeration is used in the **Type** member of the [WDF_IO_TARGET_OPEN_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/ns-wdfiotarget-_wdf_io_target_open_params) structure.

The driver can specify **WdfIoTargetOpenReopen** only if it specified **WdfIoTargetOpenByName** when it originally opened the remote I/O target.

If **WdfIoTargetOpenReopen** is set, the framework ignores all other members of the [WDF_IO_TARGET_OPEN_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/ns-wdfiotarget-_wdf_io_target_open_params) structure and uses the values that the driver specified when it originally called [WdfIoTargetOpen](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetopen) to open a remote I/O target.

By default (unless the driver specifies **UmdfFileObjectPolicy**=**AllowNullAndUnknownFileObjects** in its INF file), UMDF doesn’t allow processing of I/O requests that are not associated with a file object.
Also, some driver stacks, such as HIDclass-enumerated collection PDOs, fail requests that have no associated file object.

Unlike app-created requests, driver-created requests sent to a local I/O target have no associated file object. As a result, the framework or the lower driver might fail those requests.

In this situation, you can use **WdfIoTargetOpenLocalTargetByFile** to cause driver-created requests sent to a local target to be associated with the file object corresponding to that target.

## See also

[DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object)

[WDF_IO_TARGET_OPEN_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/ns-wdfiotarget-_wdf_io_target_open_params)

[WDF_IO_TARGET_OPEN_PARAMS_INIT_OPEN_BY_FILE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdf_io_target_open_params_init_open_by_file)

[WdfIoTargetCloseForQueryRemove](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetcloseforqueryremove)

[WdfIoTargetOpen](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetopen)