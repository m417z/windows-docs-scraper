# DEVICE_DATA_SET_REPAIR_PARAMETERS structure

## Description

Specifies parameters for the repair operation. A repair operation is
initiated by specifying **DeviceDsmAction_Repair** in the
**Action** member of the
[DEVICE_MANAGE_DATA_SET_ATTRIBUTES](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-device_manage_data_set_attributes)
structure passed in a
[IOCTL_STORAGE_MANAGE_DATA_SET_ATTRIBUTES](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-ioctl_storage_manage_data_set_attributes)
control code.

## Members

### `NumberOfRepairCopies`

The number of copies that will be repaired.

### `SourceCopy`

The copy number of the source copy.

### `RepairCopies`

The copy numbers of all the copies that will be repaired.

## See also

[DEVICE_MANAGE_DATA_SET_ATTRIBUTES](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-device_manage_data_set_attributes)

[Device Management Structures](https://learn.microsoft.com/windows/desktop/DevIO/device-management-structures)

[IOCTL_STORAGE_MANAGE_DATA_SET_ATTRIBUTES](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-ioctl_storage_manage_data_set_attributes)