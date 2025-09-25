# WDF_IO_TARGET_OPEN_PARAMS_INIT_CREATE_BY_NAME function

## Description

[Applies to KMDF and UMDF]

The **WDF_IO_TARGET_OPEN_PARAMS_INIT_CREATE_BY_NAME** function initializes a driver's [WDF_IO_TARGET_OPEN_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/ns-wdfiotarget-_wdf_io_target_open_params) structure so the driver can open an I/O target by specifying the name of the device, file, or device interface. If the supplied name does not exist, the operating system will try to create it.

## Parameters

### `Params` [out]

A pointer to a driver-allocated [WDF_IO_TARGET_OPEN_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/ns-wdfiotarget-_wdf_io_target_open_params) structure, which the function initializes.

### `TargetDeviceName` [in]

A value for the **TargetDeviceName** member of the [WDF_IO_TARGET_OPEN_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/ns-wdfiotarget-_wdf_io_target_open_params) structure.

### `DesiredAccess` [in]

A value for the **DesiredAccess** member of the [WDF_IO_TARGET_OPEN_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/ns-wdfiotarget-_wdf_io_target_open_params) structure.

## Remarks

If *TargetDeviceName* specifies the name of a file that already exists, the system replaces the existing file. If the file does not exist, the system creates it.

The [WDF_IO_TARGET_OPEN_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/ns-wdfiotarget-_wdf_io_target_open_params) structure is used as input to the [WdfIoTargetOpen](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetopen) method.

**KMDF** The **WDF_IO_TARGET_OPEN_PARAMS_INIT_CREATE_BY_NAME** function initializes the **Size**, **Type**, **TargetDeviceName**, **DesiredAccess**, and **CreateOptions** members of the specified [WDF_IO_TARGET_OPEN_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/ns-wdfiotarget-_wdf_io_target_open_params) structure.

**UMDF** The **WDF_IO_TARGET_OPEN_PARAMS_INIT_CREATE_BY_NAME** function initializes the **Size**, **Type**, **DesiredAccess**, and **TargetDeviceName** members of the specified [WDF_IO_TARGET_OPEN_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/ns-wdfiotarget-_wdf_io_target_open_params) structure. It sets the **ShareAccess** member to zero. It also sets the **FileAttributes** member to **FILE_ATTRIBUTE_NORMAL**.

For more information about I/O targets, see [Using I/O Targets](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-i-o-targets).

#### Examples

The following code example creates an I/O target object and opens a target by specifying a file name.

```cpp
UNICODE_STRING  fileName;

RtlInitUnicodeString(
                     &fileName,
                     (PCWSTR)PROTOCOL_INTERFACE_NAME
                     );

status = WdfIoTargetCreate(
                           Adapter->WdfDevice,
                           WDF_NO_OBJECT_ATTRIBUTES,
                           &Adapter->IoTarget
                           );
if (!NT_SUCCESS(status)) {
    DEBUGP(MP_ERROR, ("WdfIoTargetCreate failed 0x%x\n", status));
    return status;
}

WDF_IO_TARGET_OPEN_PARAMS_INIT_CREATE_BY_NAME(
                                              &openParams,
                                              &fileName,
                                              STANDARD_RIGHTS_ALL
                                              );

status = WdfIoTargetOpen(
                         Adapter->IoTarget,
                         &openParams
                         );
if (!NT_SUCCESS(status)) {
    DEBUGP(MP_ERROR, ("WdfIoTargetOpen failed 0x%x\n", status));
    return status;
}
```

## See also

[WDF_IO_TARGET_OPEN_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/ns-wdfiotarget-_wdf_io_target_open_params)

[WDF_IO_TARGET_OPEN_PARAMS_INIT_EXISTING_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdf_io_target_open_params_init_existing_device)

[WDF_IO_TARGET_OPEN_PARAMS_INIT_OPEN_BY_NAME](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdf_io_target_open_params_init_open_by_name)

[WdfIoTargetOpen](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetopen)