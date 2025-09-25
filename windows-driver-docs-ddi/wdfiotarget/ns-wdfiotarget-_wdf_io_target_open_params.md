# _WDF_IO_TARGET_OPEN_PARAMS structure

## Description

[Applies to KMDF and UMDF]

The **WDF_IO_TARGET_OPEN_PARAMS** structure contains parameters that the [WdfIoTargetOpen](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetopen) method uses.

## Members

### `Size`

The size, in bytes, of this structure.

### `Type`

A [WDF_IO_TARGET_OPEN_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/ne-wdfiotarget-_wdf_io_target_open_type)-typed value, which indicates the type of open operation that [WdfIoTargetOpen](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetopen) will perform.

### `EvtIoTargetQueryRemove`

A pointer to the driver's [EvtIoTargetQueryRemove](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nc-wdfiotarget-evt_wdf_io_target_query_remove) event callback function, or **NULL**.

### `EvtIoTargetRemoveCanceled`

A pointer to the driver's [EvtIoTargetRemoveCanceled](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nc-wdfiotarget-evt_wdf_io_target_remove_canceled) event callback function, or **NULL**.

### `EvtIoTargetRemoveComplete`

A pointer to the driver's [EvtIoTargetRemoveComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nc-wdfiotarget-evt_wdf_io_target_remove_complete) event callback function, or **NULL**.

### `TargetDeviceObject`

This member is not applicable to UMDF drivers.

**KMDF**
If the value of **Type** is **WdfIoTargetOpenUseExistingDevice**, this is a pointer to a [DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object) structure that represents the I/O target's device. If the value of **Type** is not **WdfIoTargetOpenUseExistingDevice**, this member is ignored.

### `TargetFileObject`

This member is not applicable to UMDF drivers.

**KMDF** If the value of **Type** is **WdfIoTargetOpenUseExistingDevice**, this is a pointer to a [FILE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_file_object) structure. This structure is included in all of the I/O requests that the driver sends to the I/O target (see [WdfRequestGetFileObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestgetfileobject)). This member is optional and can be **NULL**.
If the value of **Type** is not **WdfIoTargetOpenUseExistingDevice**, this member is ignored.

### `TargetDeviceName`

If the value of **Type** is **WdfIoTargetOpenByName**, this is a [UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string) structure that contains the name of a device, file, or device interface. For information about the format of this name, see [Object Names](https://learn.microsoft.com/windows-hardware/drivers/kernel/object-names).

If the value of **Type** is not **WdfIoTargetOpenByName**, this member is ignored.

### `DesiredAccess`

If the value of **Type** is **WdfIoTargetOpenByName**, this is an [ACCESS_MASK](https://learn.microsoft.com/windows-hardware/drivers/kernel/access-mask) value.

If the value of **Type** is not **WdfIoTargetOpenByName**, this member is ignored.

**KMDF** Possible values include FILE_*Xxxx*_ACCESS values, such as FILE_ANY_ACCESS, FILE_SPECIAL_ACCESS, FILE_READ_ACCESS, or
FILE_WRITE_ACCESS, as well as GENERIC_READ,
GENERIC_WRITE, and GENERIC_ALL.

**UMDF** The most commonly used values are GENERIC_READ, GENERIC_WRITE, or both (GENERIC_READ | GENERIC_WRITE). Note that [ACCESS_MASK](https://learn.microsoft.com/windows-hardware/drivers/kernel/access-mask) is a DWORD value. For more information about this member, see the *dwDesiredAccess* parameter of [CreateFile](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-createfilea) in the Windows SDK.

### `ShareAccess`

If the value of **Type** is not **WdfIoTargetOpenByName**, this member is ignored.

**KMDF** If the value of **Type** is **WdfIoTargetOpenByName**, this is a bitwise OR of the following flags (which are defined in *Wdm.h*), or zero.

| ShareAccess flag | Meaning |
| --- | --- |
| FILE_SHARE_READ | The driver does not require exclusive read access to the device. |
| FILE_SHARE_WRITE | The driver does not require exclusive write access to the device. |
| FILE_SHARE_DELETE | The driver does not require exclusive delete access to the device. |

**UMDF** For more information about this member, see the *dwShareMode* parameter of the [CreateFile](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-createfilea) function in the
Windows SDK.

A value of zero in **ShareAccess** indicates that the driver requires exclusive access to the device.

### `FileAttributes`

**KMDF** If the value of **Type** is **WdfIoTargetOpenByName**, this is a bitwise OR of the FILE_ATTRIBUTE_*Xxxx* flags that are defined in *Wdm.h*. Most drivers specify FILE_ATTRIBUTE_NORMAL. For more information about these flags, see [ZwCreateFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntcreatefile).

**UMDF** For more information about
this member, see the *dwFlagsAndAttributes* parameter of the [CreateFile](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-createfilea) function in the Windows SDK.

If the value of **Type** is not **WdfIoTargetOpenByName**, this member is ignored.

### `CreateDisposition`

**KMDF** If the value of **Type** is **WdfIoTargetOpenByName**, this value indicates an action for the system to take when opening a file. For a list of possible values, see [ZwCreateFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntcreatefile).

**UMDF** For more information about
this member, see the *dwCreationDisposition* parameter of the [CreateFile](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-createfilea) function in the Windows SDK.

If the value of **Type** is not **WdfIoTargetOpenByName**, this member is ignored.

### `CreateOptions`

This member is not applicable to UMDF drivers.

**KMDF** If the value of **Type** is **WdfIoTargetOpenByName**, this is a bitwise OR of file option flags. For a list of possible flags, see [ZwCreateFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntcreatefile).
If the value of **Type** is not **WdfIoTargetOpenByName**, this member is ignored.

### `EaBuffer`

This member is not applicable to UMDF drivers.

**KMDF** If the value of **Type** is **WdfIoTargetOpenByName**, this member points to an extended attributes buffer. Typically, drivers supply **NULL** for this value.
If the value of **Type** is not **WdfIoTargetOpenByName**, this member is ignored.

### `EaBufferLength`

This member is not applicable to UMDF drivers.

**KMDF** If the value of **Type** is **WdfIoTargetOpenByName**, this is the length of the extended attributes buffer. Typically, drivers supply zero for this value. If the value of **Type** is not **WdfIoTargetOpenByName**, this member is ignored.

### `AllocationSize`

This member is not applicable to UMDF drivers.

**KMDF** If the value of **Type** is **WdfIoTargetOpenByName**, this member specifies the size, in bytes, that the system should initially allocate for the file, if it is creating a new file. This value is optional and can be zero. If the value of **Type** is not **WdfIoTargetOpenByName**, this member is ignored.

### `FileInformation`

This member is not applicable to UMDF drivers.

**KMDF** If the value of **Type** is **WdfIoTargetOpenByName**, this member receives status information when the call to [WdfIoTargetOpen](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetopen) returns. The information is one of the following values: FILE_CREATED, FILE_OPENED, FILE_OVERWRITTEN, FILE_SUPERSEDED, FILE_EXISTS, or FILE_DOES_NOT_EXIST. If the value of **Type** is not **WdfIoTargetOpenByName**, this member is ignored.

### `FileName`

This member is not applicable to KMDF drivers.

**UMDF** A UNICODE_STRING structure that contains the
name of the file from which to create a file object. This member is
optional, and is applicable only when the value of **Type** is **WdfIoTargetOpenLocalTargetByFile**. Most drivers specify **NULL** here unless the lower target supports [Device Namespace Access](https://learn.microsoft.com/windows-hardware/drivers/kernel/controlling-device-namespace-access). If supplied, the string must not contain any path separator characters
(forward slash or backslash).

## Remarks

Drivers should initialize the **WDF_IO_TARGET_OPEN_PARAMS** structure by calling one of the following functions:

* [WDF_IO_TARGET_OPEN_PARAMS_INIT_EXISTING_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdf_io_target_open_params_init_existing_device), if your driver can identify a target device by supplying a pointer to a [DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object) structure.
* [WDF_IO_TARGET_OPEN_PARAMS_INIT_CREATE_BY_NAME](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdf_io_target_open_params_init_create_by_name), if the I/O target is a device, file, or device interface, and if your driver can supply the name of the device, file, or device interface. If you specify the name of a file that already exists, the system replaces the existing file. If the file does not exist, the system creates it.
* [WDF_IO_TARGET_OPEN_PARAMS_INIT_OPEN_BY_NAME](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdf_io_target_open_params_init_open_by_name), if the I/O target is a device, file, or device interface, and if your driver can supply the name of the device, file, or device interface. If you specify the name of a file that already exists, the system opens the existing file. If the file does not exist, the open operation fails.
* [WDF_IO_TARGET_OPEN_PARAMS_INIT_REOPEN](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdf_io_target_open_params_init_reopen), if your driver's [EvtIoTargetRemoveCanceled](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nc-wdfiotarget-evt_wdf_io_target_remove_canceled) callback function is reopening a remote I/O target because the device was not removed.
* [WDF_IO_TARGET_OPEN_PARAMS_INIT_OPEN_BY_FILE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdf_io_target_open_params_init_open_by_file), if your UMDF driver needs to send driver-created requests to lower targets that require an associated file object.

## See also

[ACCESS_MASK](https://learn.microsoft.com/windows-hardware/drivers/kernel/access-mask)

[DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object)

[EvtIoTargetQueryRemove](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nc-wdfiotarget-evt_wdf_io_target_query_remove)

[EvtIoTargetRemoveCanceled](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nc-wdfiotarget-evt_wdf_io_target_remove_canceled)

[FILE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_file_object)

[UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string)

[WDF_IO_TARGET_OPEN_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/ne-wdfiotarget-_wdf_io_target_open_type)

[WdfIoTargetOpen](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetopen)

[WdfRequestGetFileObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestgetfileobject)

[ZwCreateFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntcreatefile)