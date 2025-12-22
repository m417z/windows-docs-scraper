# DEVICE_MANAGE_DATA_SET_ATTRIBUTES structure

## Description

Input structure for the
[IOCTL_STORAGE_MANAGE_DATA_SET_ATTRIBUTES](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-ioctl_storage_manage_data_set_attributes)
control code.

## Members

### `Size`

Size of this data structure. Must be set to
`sizeof(DEVICE_MANAGE_DATA_SET_ATTRIBUTES)`.

### `Action`

A valid value of type
[DEVICE_DATA_MANAGEMENT_SET_ACTION](https://learn.microsoft.com/windows/desktop/DevIO/device-data-management-set-action).

| Value | Meaning |
| --- | --- |
| **DeviceDsmAction_Trim**<br><br>1 | A trim action is performed. This value is not supported for user-mode applications. |
| **DeviceDsmAction_Notification**<br><br>2 \| **DeviceDsmActionFlag_NonDestructive** (0x80000002) | A notification action is performed. The additional parameters are in a [DEVICE_DSM_NOTIFICATION_PARAMETERS](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-device_dsm_notification_parameters) structure. The **DeviceDsmActionFlag_NonDestructive** (0x80000000) is a bit flag to indicate to the driver stack that this operation is non-destructive. |
| **DeviceDsmAction_OffloadRead**<br><br>3 \| **DeviceDsmActionFlag_NonDestructive** (0x80000003) | An offload read action is performed. The additional parameters are in a [DEVICE_DSM_OFFLOAD_READ_PARAMETERS](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-device_dsm_offload_read_parameters) structure. The **DeviceDsmActionFlag_NonDestructive** (0x80000000) is a bit flag to indicate to the driver stack that this operation is non-destructive.<br><br>**Windows 7 and Windows Server 2008 R2:** This value is not supported before Windows 8 and Windows Server 2012. |
| **DeviceDsmAction_OffloadWrite**<br><br>4 | An offload write action is performed. The additional parameters are in a [DEVICE_DSM_OFFLOAD_WRITE_PARAMETERS](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-device_dsm_offload_write_parameters) structure.<br><br>**Windows 7 and Windows Server 2008 R2:** This value is not supported before Windows 8 and Windows Server 2012. |
| **DeviceDsmAction_Allocation**<br><br>5 \| **DeviceDsmActionFlag_NonDestructive** (0x80000005) | An allocation bitmap is retrieved for the first data set range specified. The **DeviceDsmActionFlag_NonDestructive** (0x80000000) is a bit flag to indicate to the driver stack that this operation is non-destructive.<br><br>**Windows 7 and Windows Server 2008 R2:** This value is not supported before Windows 8 and Windows Server 2012. |
| **DeviceDsmAction_Repair**<br><br>6 \| **DeviceDsmActionFlag_NonDestructive** (0x80000006) | A repair action is performed. The additional parameters are in a [DEVICE_DATA_SET_REPAIR_PARAMETERS](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-device_data_set_repair_parameters) structure. The **DeviceDsmActionFlag_NonDestructive** (0x80000000) is a bit flag to indicate to the driver stack that this operation is non-destructive.<br><br>**Windows 7 and Windows Server 2008 R2:** This value is not supported before Windows 8 and Windows Server 2012. |
| **DeviceDsmAction_Scrub**<br><br>7 \| **DeviceDsmActionFlag_NonDestructive** (0x80000007) | A scrub action is performed. The **DeviceDsmActionFlag_NonDestructive** (0x80000000) is a bit flag to indicate to the driver stack that this operation is non-destructive.<br><br>**Windows 7 and Windows Server 2008 R2:** This value is not supported before Windows 8 and Windows Server 2012. |
| **DeviceDsmAction_Resiliency**<br><br>8 \| **DeviceDsmActionFlag_NonDestructive** (0x80000008) | A resiliency action is performed. The **DeviceDsmActionFlag_NonDestructive** (0x80000000) is a bit flag to indicate to the driver stack that this operation is non-destructive.<br><br>**Windows 7 and Windows Server 2008 R2:** This value is not supported before Windows 8 and Windows Server 2012. |

### `Flags`

Flags for the actions.

| Value | Meaning |
| --- | --- |
| **DEVICE_DSM_FLAG_TRIM_NOT_FS_ALLOCATED**<br><br>0x80000000 | If set then the described ranges are not allocated by a file system. This flag is specific to the **DeviceDsmAction_Trim** action. |
| **DEVICE_DSM_FLAG_RESILIENCY_START_RESYNC**<br><br>0x10000000 | Starts a resync operation on the storage device. This flag is specific to the **DeviceDsmAction_Resiliency** action. |
| **DEVICE_DSM_FLAG_RESILIENCY_START_LOAD_BALANCING**<br><br>0x20000000 | Starts a load balancing operation on the storage device. This flag is specific to the **DeviceDsmAction_Resiliency** action. |

### `ParameterBlockOffset`

Byte offset to the start of the parameter block stored in the buffer contiguous to this structure. Must be
aligned to the corresponding structure alignment. A value of zero indicates there is no parameter block and the
**ParameterBlockLength** member must also be zero.

### `ParameterBlockLength`

Length of the parameter block, in bytes. A value of zero indicates there is no parameter block and the
**ParameterBlockOffset** member must also be zero.

### `DataSetRangesOffset`

Byte offset to the start of the data set ranges block made up of an array of
[DEVICE_DATA_SET_RANGE](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-device_data_set_range) structures stored in the
buffer contiguous to this structure. Must be aligned to the
**DEVICE_DATA_SET_RANGE** structure alignment. A
value of zero indicates there is no data set ranges block and the
**DataSetRangesLength** member must also be zero.

### `DataSetRangesLength`

Length of the data set ranges block, in bytes. A value of zero indicates there is no data set ranges block
and the **DataSetRangesOffset** member must also be zero.

## Remarks

The total length of the buffer that contains this structure must be at least
`(sizeof(DEVICE_MANAGE_DATA_SET_ATTRIBUTES) + ParameterBlockLength + DataSetRangesLength)`.

## See also

[DEVICE_DATA_SET_RANGE](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-device_data_set_range)

[Device Management Structures](https://learn.microsoft.com/windows/desktop/DevIO/device-management-structures)

[IOCTL_STORAGE_MANAGE_DATA_SET_ATTRIBUTES](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-ioctl_storage_manage_data_set_attributes)