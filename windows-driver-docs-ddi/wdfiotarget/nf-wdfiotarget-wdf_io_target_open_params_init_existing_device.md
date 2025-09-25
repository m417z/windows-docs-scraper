# WDF_IO_TARGET_OPEN_PARAMS_INIT_EXISTING_DEVICE function

## Description

[Applies to KMDF only]

The **WDF_IO_TARGET_OPEN_PARAMS_INIT_EXISTING_DEVICE** function initializes a driver's [WDF_IO_TARGET_OPEN_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/ns-wdfiotarget-_wdf_io_target_open_params) structure so that the driver can open a remote I/O target by specifying a Windows Driver Model (WDM) device object.

## Parameters

### `Params` [out]

A pointer to a driver-allocated [WDF_IO_TARGET_OPEN_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/ns-wdfiotarget-_wdf_io_target_open_params) structure that the function initializes.

### `DeviceObject` [in]

A pointer to a [DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object) structure, which is used as the value for the **DeviceObject** member of the [WDF_IO_TARGET_OPEN_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/ns-wdfiotarget-_wdf_io_target_open_params) structure.

## Remarks

The [WDF_IO_TARGET_OPEN_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/ns-wdfiotarget-_wdf_io_target_open_params) structure is used as input to the [WdfIoTargetOpen](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetopen) method.

The **WDF_IO_TARGET_OPEN_PARAMS_INIT_EXISTING_DEVICE** function initializes the **Size**, **Type**, and **TargetDeviceObject** members of the specified [WDF_IO_TARGET_OPEN_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/ns-wdfiotarget-_wdf_io_target_open_params) structure.

Typically, a driver sets the **TargetFileObject** member of the [WDF_IO_TARGET_OPEN_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/ns-wdfiotarget-_wdf_io_target_open_params) structure after the driver has called **WDF_IO_TARGET_OPEN_PARAMS_INIT_EXISTING_DEVICE**.

For more information about I/O targets, see [Using I/O Targets](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-i-o-targets).

#### Examples

The following code example creates an I/O target object and opens the target by specifying a DEVICE_OBJECT structure. The sample driver obtains the DEVICE_OBJECT structure by calling [NdisMGetDeviceProperty](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismgetdeviceproperty) (not shown).

```cpp
WDF_IO_TARGET_OPEN_PARAMS  openParams;
NTSTATUS  ntStatus;

ntStatus = WdfIoTargetCreate(
                             Adapter->WdfDevice,
                             WDF_NO_OBJECT_ATTRIBUTES,
                             &Adapter->IoTarget
                             );
if (!NT_SUCCESS(ntStatus)) {
    DEBUGP(MP_ERROR, ("WdfIoTargetCreate failed 0x%x\n", ntStatus));
    break;
}

WDF_IO_TARGET_OPEN_PARAMS_INIT_EXISTING_DEVICE(
                                               &openParams,
                                               Adapter->NextDeviceObject
                                               );

ntStatus = WdfIoTargetOpen(Adapter->IoTarget,
                           &openParams);
if (!NT_SUCCESS(ntStatus)) {
    DEBUGP(MP_ERROR, ("WdfIoTargetOpen failed 0x%x\n", ntStatus));
    break;
}
```

## See also

[WDF_IO_TARGET_OPEN_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/ns-wdfiotarget-_wdf_io_target_open_params)

[WDF_IO_TARGET_OPEN_PARAMS_INIT_CREATE_BY_NAME](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdf_io_target_open_params_init_create_by_name)

[WDF_IO_TARGET_OPEN_PARAMS_INIT_OPEN_BY_NAME](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdf_io_target_open_params_init_open_by_name)

[WdfIoTargetOpen](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetopen)