# FILE_SET_SPARSE_BUFFER structure

## Description

Specifies the sparse state to be set.**Windows Server 2003 and Windows XP:** This structure is optional. For more information, see
[FSCTL_SET_SPARSE](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-fsctl_set_sparse).

## Members

### `SetSparse`

If **TRUE**, makes the file sparse.

If **FALSE**, makes the file not sparse.

**Windows Server 2008 R2, Windows 7, Windows Server 2008 and Windows Vista:** A value of **FALSE** for this member is valid only on files that no longer have any
sparse regions. For more information, see
[FSCTL_SET_SPARSE](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-fsctl_set_sparse).

**Windows Server 2003 and Windows XP:** A value of **FALSE** for this member is not supported. Specifying
**FALSE** will cause the
[FSCTL_SET_SPARSE](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-fsctl_set_sparse) call to fail.

## See also

[DeviceIoControl](https://learn.microsoft.com/windows/desktop/api/ioapiset/nf-ioapiset-deviceiocontrol)

[FSCTL_SET_SPARSE](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-fsctl_set_sparse)