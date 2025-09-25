# WDF_IO_TARGET_OPEN_PARAMS_INIT_OPEN_BY_NAME function

## Description

[Applies to KMDF and UMDF]

The **WDF_IO_TARGET_OPEN_PARAMS_INIT_OPEN_BY_NAME** function initializes a driver's [WDF_IO_TARGET_OPEN_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/ns-wdfiotarget-_wdf_io_target_open_params) structure so the driver can open an I/O target by specifying the name of the device, file, or device interface. If the supplied name does not exist, the system will not try to create it.

## Parameters

### `Params` [out]

A pointer to a driver-allocated [WDF_IO_TARGET_OPEN_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/ns-wdfiotarget-_wdf_io_target_open_params) structure, which the function initializes.

### `TargetDeviceName` [in]

A value for the **TargetDeviceName** member of the [WDF_IO_TARGET_OPEN_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/ns-wdfiotarget-_wdf_io_target_open_params) structure.

### `DesiredAccess` [in]

A value for the **DesiredAccess** member of the [WDF_IO_TARGET_OPEN_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/ns-wdfiotarget-_wdf_io_target_open_params) structure.

## Remarks

If *TargetDeviceName* specifies the name of a file that already exists, the system opens the existing file. If the file does not exist, the open operation fails.

The [WDF_IO_TARGET_OPEN_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/ns-wdfiotarget-_wdf_io_target_open_params) structure is used as input to the [WdfIoTargetOpen](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetopen) method.

The **WDF_IO_TARGET_OPEN_PARAMS_INIT_OPEN_BY_NAME** function initializes the **Size**, **Type**, **TargetDeviceName**, **DesiredAccess**, **CreateOptions**, and **CreateDisposition** members of the specified [WDF_IO_TARGET_OPEN_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/ns-wdfiotarget-_wdf_io_target_open_params) structure.

**KMDF** The **WDF_IO_TARGET_OPEN_PARAMS_INIT_OPEN_BY_NAME** function initializes the **CreateDisposition** member to **FILE_OPEN**.

**UMDF** The **WDF_IO_TARGET_OPEN_PARAMS_INIT_OPEN_BY_NAME** function initializes the **CreateDisposition** member to **OPEN_EXISTING**.

For more information about I/O targets, see [Using I/O Targets](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-i-o-targets).

#### Examples

For a code example that uses **WDF_IO_TARGET_OPEN_PARAMS_INIT_OPEN_BY_NAME**, see [WdfIoTargetOpen](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetopen).

## See also

[WDF_IO_TARGET_OPEN_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/ns-wdfiotarget-_wdf_io_target_open_params)

[WDF_IO_TARGET_OPEN_PARAMS_INIT_CREATE_BY_NAME](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdf_io_target_open_params_init_create_by_name)

[WDF_IO_TARGET_OPEN_PARAMS_INIT_EXISTING_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdf_io_target_open_params_init_existing_device)

[WdfIoTargetOpen](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetopen)