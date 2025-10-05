# IOCTL_STORAGE_FIRMWARE_GET_INFO IOCTL

## Description

A driver can use **IOCTL_STORAGE_FIRMWARE_GET_INFO** to query a storage device for detailed firmware information. A successful call will return information about firmware revisions, activity status, as well as read/write attributes for each slot. The amount of data returned varies based on storage protocol.

## Parameters

### Major code

### Input buffer

**Irp->AssociatedIrp.SystemBuffer** contains [STORAGE_HW_FIRMWARE_INFO_QUERY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_storage_hw_firmware_info_query) data that specifies the target of the request.

### Input buffer length

**Parameters.DeviceIoControl.InputBufferLength** indicates the size, in bytes, of the parameter buffer at **Irp->AssociatedIrp.SystemBuffer**, which must be >= ```sizeof(STORAGE_HW_FIRMWARE_INFO_QUERY)```.

### Output buffer

The driver returns query data to the buffer at **Irp->AssociatedIrp.SystemBuffer**. The output buffer should contain a [STORAGE_HW_FIRMWARE_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_storage_hw_firmware_info) and [STORAGE_HW_FIRMWARE_SLOT_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_storage_hw_firmware_slot_info) structure for each slot on the device.

### Output buffer length

**Parameters.DeviceIoControl.OutputBufferLength** indicates the number of bytes that can be written to **Irp->AssociatedIrp.SystemBuffer**. **OutputBufferLength** must be **sizeof**([STORAGE_HW_FIRMWARE_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_storage_hw_firmware_info)) + ```sizeof(STORAGE_HW_FIRMWARE_SLOT_INFO) * (STORAGE_HW_FIRMWARE_INFO.SlotCount -1)```.

### Input/output buffer

### Input/output buffer length

### Status block

The **Information** field is set to the number of bytes returned. The **Status** field is set to STATUS_SUCCESS, or possibly to STATUS_INVALID_DEVICE_REQUEST, STATUS_INVALID_PARAMETER, or STATUS_NOT_SUPPORTED.

## See also

[IOCTL_STORAGE_FIRMWARE_ACTIVATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_firmware_activate)

[IOCTL_STORAGE_FIRMWARE_DOWNLOAD](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_firmware_download)

[STORAGE_HW_FIRMWARE_ACTIVATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_storage_hw_firmware_activate)

[STORAGE_HW_FIRMWARE_DOWNLOAD](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_storage_hw_firmware_download)

[STORAGE_HW_FIRMWARE_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_storage_hw_firmware_info)

[STORAGE_HW_FIRMWARE_INFO_QUERY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_storage_hw_firmware_info_query)

[STORAGE_HW_FIRMWARE_SLOT_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_storage_hw_firmware_slot_info)