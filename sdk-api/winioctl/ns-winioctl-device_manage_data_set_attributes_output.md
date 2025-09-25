# DEVICE_MANAGE_DATA_SET_ATTRIBUTES_OUTPUT structure

## Description

Output structure for the
[IOCTL_STORAGE_MANAGE_DATA_SET_ATTRIBUTES](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-ioctl_storage_manage_data_set_attributes)
control code.

## Members

### `Size`

Size of the structure. This is set to
`sizeof(DEVICE_MANAGE_DATA_SET_ATTRIBUTES_OUTPUT)`.

### `Action`

The action related to the instance of this structure. This is a value for the
[DEVICE_DATA_MANAGEMENT_SET_ACTION](https://learn.microsoft.com/windows/desktop/DevIO/device-data-management-set-action) data
type.

| Value | Meaning |
| --- | --- |
| **DeviceDsmAction_Trim**<br><br>1 | A trim action is performed. This value is not supported for user-mode applications. |
| **DeviceDsmAction_Notification**<br><br>2 | **DeviceDsmActionFlag_NonDestructive** (0x80000002) | A notification action is performed. The **DeviceDsmActionFlag_NonDestructive** (0x80000000) is a bit flag to indicate to the driver stack that this operation is non-destructive. |
| **DeviceDsmAction_OffloadRead**<br><br>3 | **DeviceDsmActionFlag_NonDestructive** (0x80000003) | An offload read action is performed. The output described by the **OutputBlockOffset** and **OutputBlockLength** members is a [STORAGE_OFFLOAD_READ_OUTPUT](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-storage_offload_read_output) structure. The **DeviceDsmActionFlag_NonDestructive** (0x80000000) is a bit flag to indicate to the driver stack that this operation is non-destructive. |
| **DeviceDsmAction_OffloadWrite**<br><br>4 | An offload write action is performed. The output described by the **OutputBlockOffset** and **OutputBlockLength** members is a [STORAGE_OFFLOAD_WRITE_OUTPUT](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-storage_offload_write_output) structure. |
| **DeviceDsmAction_Allocation**<br><br>5 | **DeviceDsmActionFlag_NonDestructive** (0x80000005) | An allocation bitmap is returned for the first data set range passed in. The output is in a [DEVICE_DATA_SET_LB_PROVISIONING_STATE](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-device_data_set_lb_provisioning_state) structure. The **DeviceDsmActionFlag_NonDestructive** (0x80000000) is a bit flag to indicate to the driver stack that this operation is non-destructive. |
| **DeviceDsmAction_Repair**<br><br>6 | **DeviceDsmActionFlag_NonDestructive** (0x80000006) | A repair action is performed. The **DeviceDsmActionFlag_NonDestructive** (0x80000000) is a bit flag to indicate to the driver stack that this operation is non-destructive.<br><br>**Windows 7 and Windows Server 2008 R2:** This value is not supported before Windows 8 and Windows Server 2012. |
| **DeviceDsmAction_Scrub**<br><br>7 | **DeviceDsmActionFlag_NonDestructive** (0x80000007) | A scrub action is performed. The **DeviceDsmActionFlag_NonDestructive** (0x80000000) is a bit flag to indicate to the driver stack that this operation is non-destructive.<br><br>**Windows 7 and Windows Server 2008 R2:** This value is not supported before Windows 8 and Windows Server 2012. |
| **DeviceDsmAction_Resiliency**<br><br>8 | **DeviceDsmActionFlag_NonDestructive** (0x80000008) | A resiliency action is performed. The **DeviceDsmActionFlag_NonDestructive** (0x80000000) is a bit flag to indicate to the driver stack that this operation is non-destructive.<br><br>**Windows 7 and Windows Server 2008 R2:** This value is not supported before Windows 8 and Windows Server 2012. |

### `Flags`

Not used.

### `OperationStatus`

Not used.

### `ExtendedError`

Extended error information.

### `TargetDetailedError`

Target specific error.

### `ReservedStatus`

Reserved.

### `OutputBlockOffset`

The offset, in bytes, from the beginning of this structure to where any action-specific data is
located.

### `OutputBlockLength`

The length, in bytes, of the action-specific data.

## See also

[DEVICE_DATA_SET_RANGE](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-device_data_set_range)

[Device Management Structures](https://learn.microsoft.com/windows/desktop/DevIO/device-management-structures)

[IOCTL_STORAGE_MANAGE_DATA_SET_ATTRIBUTES](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-ioctl_storage_manage_data_set_attributes)