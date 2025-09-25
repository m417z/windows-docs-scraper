# BOOT_AREA_INFO structure

## Description

Contains the output for the [FSCTL_GET_BOOT_AREA_INFO](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-fsctl_get_boot_area_info) control code.

## Members

### `BootSectorCount`

Number of elements in the **BootSectors** array.

### `Offset`

### `BootSectors`

A variable length array of structures each containing the following member.

#### Offset

The location of a boot sector or a copy of a boot sector.

## Syntax

```cpp
typedef struct _BOOT_AREA_INFO {
  DWORD                    BootSectorCount;
  struct {
    LARGE_INTEGER Offset;
  } BootSectors[2];
} BOOT_AREA_INFO, *PBOOT_AREA_INFO;
```

## See also

[FSCTL_GET_BOOT_AREA_INFO](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-fsctl_get_boot_area_info)