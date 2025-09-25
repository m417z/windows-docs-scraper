# IOCTL_STORAGE_FIRMWARE_ACTIVATE IOCTL

## Description

A driver can use **IOCTL_STORAGE_FIRMWARE_ACTIVATE** to activate a firmware image on a storage device.

## Parameters

### Major code

### Input buffer

**Irp->AssociatedIrp.SystemBuffer** contains [STORAGE_HW_FIRMWARE_ACTIVATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_storage_hw_firmware_activate) data that specifies information about the downloaded firmware to activate.

### Input buffer length

**Parameters.DeviceIoControl.InputBufferLength** indicates the size, in bytes, of the parameter buffer at **Irp->AssociatedIrp.SystemBuffer**, which must be >= **sizeof**([STORAGE_HW_FIRMWARE_ACTIVATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_storage_hw_firmware_activate)).

### Output buffer

This IOCTL has no output structure.

### Output buffer length

None.

### Input/output buffer

### Input/output buffer length

### Status block

The **Information** field is set to the number of bytes returned. The **Status** field is set to **STATUS_SUCCESS**, or possibly to **STATUS_INSUFFICIENT_RESOURCES**.

## See also

[IOCTL_STORAGE_FIRMWARE_DOWNLOAD](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_firmware_download)

[IOCTL_STORAGE_FIRMWARE_GET_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_firmware_get_info)

[STORAGE_HW_FIRMWARE_ACTIVATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_storage_hw_firmware_activate)

[STORAGE_HW_FIRMWARE_DOWNLOAD](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_storage_hw_firmware_download)

[STORAGE_HW_FIRMWARE_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_storage_hw_firmware_info)

[STORAGE_HW_FIRMWARE_INFO_QUERY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_storage_hw_firmware_info_query)

[STORAGE_HW_FIRMWARE_SLOT_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_storage_hw_firmware_slot_info)