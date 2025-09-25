# CSV_IS_OWNED_BY_CSVFS structure

## Description

Contains the output for the
[FSCTL_IS_VOLUME_OWNED_BYCSVFS](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-fsctl_is_volume_owned_bycsvfs) control code
that determines whether a volume is owned by CSVFS.

## Members

### `OwnedByCSVFS`

**TRUE** if a volume is owned by CSVFS; otherwise,
**FALSE**.

## See also

[FSCTL_IS_VOLUME_OWNED_BYCSVFS](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-fsctl_is_volume_owned_bycsvfs)

[Volume Management Structures](https://learn.microsoft.com/windows/desktop/FileIO/volume-management-structures)