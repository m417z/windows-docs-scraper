# NTMS_ALLOCATION_INFORMATION structure

## Description

[[Removable Storage Manager](https://learn.microsoft.com/previous-versions/windows/desktop/bb540725(v=vs.85)) is no longer available as of Windows 7 and Windows Server 2008 R2.]

The
**NTMS_ALLOCATION_INFORMATION** structure contains information about the source media pool from which a medium was taken.

## Members

### `dwSize`

Size of the structure.

### `lpReserved.ptr`

### `lpReserved`

Reserved.

### `AllocatedFrom`

Unique identifier of the original source of the media.

## See also

[AllocateNtmsMedia](https://learn.microsoft.com/previous-versions/windows/desktop/rsm/media)