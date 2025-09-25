# WdmlibIoValidateDeviceIoControlAccess function

## Description

The **WdmlibIoValidateDeviceIoControlAccess** function verifies that the sender of an [IRP_MJ_DEVICE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-device-control) or [IRP_MJ_FILE_SYSTEM_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-file-system-control) IRP has the specified access to the device object.

## Parameters

### `Irp` [in]

Specifies the [IRP](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_irp) on which to perform the access check.

### `RequiredAccess` [in]

Specifies the type of access to the device object that the request sender must have. The caller can specify one or more of the following flags.

| Value | Meaning |
| --- | --- |
| **FILE_READ_ACCESS** | The request sender must have read access to the device object |
| **FILE_WRITE_ACCESS** | The request sender must have write access to the device object. |

## Return value

**WdmlibIoValidateDeviceIoControlAccess** returns an NTSTATUS value. Possible return values include:

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The request sender has the necessary access to the device object. |
| **STATUS_ACCESS_DENIED** | The request sender does not have the necessary access to the device object. |
| **STATUS_INVALID_PARAMETER** | The specified parameters are invalid. For example, if the routine is passed an IRP that is not an **IRP_MJ_DEVICE_CONTROL** or **IRP_MJ_FILE_SYSTEM_CONTROL** IRP, it returns STATUS_INVALID_PARAMETER. |

## Remarks

**WdmlibIoValidateDeviceIoControlAccess** allows drivers to perform dynamic access checks for IOCTLs. Use this routine to require more restrictive access than that specified in the IOCTL's definition. If the routine returns STATUS_ACCESS_DENIED, then the driver can complete the request with the STATUS_ACCESS_DENIED status value.

For example, if an IOCTL is defined with a *RequiredAccess* value of FILE_ANY_ACCESS, then by default any request sender with SYNCHRONIZE access to the device object can send the IOCTL. Use
**WdmlibIoValidateDeviceIoControlAccess** to require more stringent security at run time. For more information about the *RequiredAccess* value of an IOCTL, see [Defining I/O Control Codes](https://learn.microsoft.com/windows-hardware/drivers/kernel/defining-i-o-control-codes).

The access checks are only performed if the **RequestorMode** member of the [IRP](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_irp) structure is **UserMode**. If **RequestorMode** is **KernelMode**, the routine automatically returns STATUS_SUCCESS.

## See also

[IRP](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_irp)