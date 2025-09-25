# IOCTL_STORAGE_DEVICE_POWER_CAP IOCTL

## Description

A driver can use **IOCTL_STORAGE_DEVICE_POWER_CAP** to specify a maximum operational power consumption level for a storage device. The OS will do its best to transition the device to a power state that will not exceed the given maximum; however, this depends on what the device supports. The actual maximum may be less than or greater than the desired maximum.

## Parameters

### Major code

### Input buffer

[**Irp->AssociatedIrp.SystemBuffer**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_irp) contains a [**STORAGE_DEVICE_POWER_CAP**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_storage_device_power_cap) structure that specifies the maximum power.

### Input buffer length

* **Parameters.DeviceIoControl.InputBufferLength** indicates the size, in bytes, of the input parameter buffer at **Irp->AssociatedIrp.SystemBuffer**, which must be greater than or equal to ```sizeof(STORAGE_DEVICE_POWER_CAP)```.

### Output buffer

If the operation is successful, the output buffer at **Irp->AssociatedIrp.SystemBuffer** will contain a [**STORAGE_DEVICE_POWER_CAP**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_storage_device_power_cap) structure.

### Output buffer length

**Parameters.DeviceIoControl.OutputBufferLength** indicates the size, in bytes, of the output parameter buffer at **Irp->AssociatedIrp.SystemBuffer**. **OutputBufferLength** must be greater than or equal to ```sizeof(STORAGE_DEVICE_POWER_CAP)```.

### Input/output buffer

### Input/output buffer length

### Status block

The [**Information**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_status_block) field is set to the number of bytes returned. The **Status** field is set to STATUS_SUCCESS, or possibly to STATUS_INVALID_DEVICE_REQUEST, STATUS_INVALID_PARAMETER, or STATUS_NOT_SUPPORTED.

## Remarks

For a reboot, the **IOCTL_STORAGE_DEVICE_POWER_CAP** effect is not persistent. For an NVMe device reset/power cycle, the IOCTL’s effect is persistent.

## See also

[**IO_STATUS_BLOCK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_status_block)

[**STORAGE_DEVICE_POWER_CAP**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_storage_device_power_cap)

[**STORAGE_DEVICE_POWER_CAP_UNITS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ne-ntddstor-_storage_device_power_cap_units)