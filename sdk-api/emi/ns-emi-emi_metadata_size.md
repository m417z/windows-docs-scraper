# EMI_METADATA_SIZE structure

## Description

The **EMI_METADATA_SIZE** structure specifies the size of the Energy Metering Interface (EMI) metadata object that can be obtained from the device by issuing an [IOCTL_EMI_GET_METADATA](https://learn.microsoft.com/windows/desktop/api/emi/ni-emi-ioctl_emi_get_metadata) request.

## Members

### `MetadataSize`

The size of the EMI metadata (an [EMI_METADATA](https://learn.microsoft.com/windows/win32/api/emi/ns-emi-emi_metadata_v1) structure) that can be obtained from the device.

## Remarks

This structure is returned through a successful completion of an [IOCTL_EMI_GET_METADATA_SIZE](https://learn.microsoft.com/windows/desktop/api/emi/ni-emi-ioctl_emi_get_metadata_size) IOCTL request.

## See also

[Energy Metering Interface](https://learn.microsoft.com/windows-hardware/drivers/powermeter/energy-meter-interface)

[IOCTL_EMI_GET_METADATA_SIZE](https://learn.microsoft.com/windows/desktop/api/emi/ni-emi-ioctl_emi_get_metadata_size)