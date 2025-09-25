# WdfIoTargetOpen function

## Description

[Applies to KMDF and UMDF]

The **WdfIoTargetOpen** method opens a remote I/O target so the driver can send I/O requests to it.

## Parameters

### `IoTarget` [in]

A handle to an I/O target object that was obtained from a previous call to [WdfIoTargetCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetcreate).

### `OpenParams` [in]

A pointer to a caller-allocated [WDF_IO_TARGET_OPEN_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/ns-wdfiotarget-_wdf_io_target_open_params) structure.

## Return value

**WdfIoTargetOpen** returns STATUS_SUCCESS if the operation succeeds. Otherwise, this method might return one of the following values:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_DEVICE_STATE** | The specified I/O target is already open. |
| **STATUS_INSUFFICIENT_RESOURCES** | Available system resources were insufficient to complete the operation. |
| **STATUS_INFO_LENGTH_MISMATCH** | The size of the [WDF_IO_TARGET_OPEN_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/ns-wdfiotarget-_wdf_io_target_open_params) structure that *OpenParams* specified was incorrect. |
| **STATUS_NO_SUCH_DEVICE** | The *TargetFileObject* member of the caller's [WDF_IO_TARGET_OPEN_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/ns-wdfiotarget-_wdf_io_target_open_params) structure specified an invalid file object. |
| **STATUS_INVALID_PARAMETER** | An invalid parameter was detected. |
| **STATUS_NOT_FOUND** | The device name that is identified in the *OpenParams* parameter cannot be found. |

This method also might return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

Drivers can open remote I/O targets by supplying a Unicode string that represents an [object name](https://learn.microsoft.com/windows-hardware/drivers/kernel/object-names) or by supplying a pointer to a Windows Driver Model (WDM) [DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object) structure. (Framework-based drivers typically do not have pointers to other drivers' DEVICE_OBJECT structures.)

To obtain a device interface name prior to calling **WdfIoTargetOpen**, a UMDF driver should call [CM_Register_Notification](https://learn.microsoft.com/windows/win32/api/cfgmgr32/nf-cfgmgr32-cm_register_notification) to register for interface arrival and removal notification. Then it can open the remote target using
the interface symbolic name that it receives in the interface notification callback routine. The driver should continue to listen for the removal notification while the handle is open. If the target driver fails, the UMDF driver must close the handle.

 If the interface already exists, a UMDF driver should call [CM_Get_Device_Interface_List](https://learn.microsoft.com/windows/win32/api/cfgmgr32/nf-cfgmgr32-cm_get_device_interface_lista), possibly calling [CM_Get_Device_Interface_List_Size](https://learn.microsoft.com/windows/win32/api/cfgmgr32/nf-cfgmgr32-cm_get_device_interface_list_sizea) first to determine the required buffer size.

If you want your driver to use its local I/O target, the driver must call [WdfDeviceGetIoTarget](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicegetiotarget) instead of **WdfIoTargetOpen**.

If a call to **WdfIoTargetOpen** fails, the driver should call [WdfObjectDelete](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/nf-wdfobject-wdfobjectdelete) to delete the I/O target object.

For more information about **WdfIoTargetOpen**, see [Initializing a General I/O Target](https://learn.microsoft.com/windows-hardware/drivers/wdf/initializing-a-general-i-o-target).

For more information about I/O targets, see [Using I/O Targets](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-i-o-targets).

#### Examples

The following example creates an I/O target object, initializes a [WDF_IO_TARGET_OPEN_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/ns-wdfiotarget-_wdf_io_target_open_params) structure, and opens a remote I/O target by specifying a device's symbolic link name.

```cpp
WDF_OBJECT_ATTRIBUTES  ioTargetAttrib;
WDFIOTARGET  ioTarget;
WDF_IO_TARGET_OPEN_PARAMS  openParams;

WDF_OBJECT_ATTRIBUTES_INIT_CONTEXT_TYPE(
                                        &ioTargetAttrib,
                                        TARGET_DEVICE_INFO
                                        );
status = WdfIoTargetCreate(
                           device,
                           &ioTargetAttrib,
                           &ioTarget
                           );
if (!NT_SUCCESS(status)) {
    return status;
}
WDF_IO_TARGET_OPEN_PARAMS_INIT_OPEN_BY_NAME(
                                            &openParams,
                                            SymbolicLink,
                                            STANDARD_RIGHTS_ALL
                                            );
status = WdfIoTargetOpen(
                         ioTarget,
                         &openParams
                         );
if (!NT_SUCCESS(status)) {
    WdfObjectDelete(ioTarget);
    return status;
}
```

## See also

[DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object)

[WDF_IO_TARGET_OPEN_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/ns-wdfiotarget-_wdf_io_target_open_params)

[WdfDeviceGetIoTarget](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicegetiotarget)

[WdfIoTargetClose](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetclose)

[WdfIoTargetCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetcreate)

[WdfIoTargetOpen](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetopen)

[WdfObjectDelete](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/nf-wdfobject-wdfobjectdelete)