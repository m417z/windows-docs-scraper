# _BOOT_AREA_INFO structure

## Description

The **BOOT_AREA_INFO** structure contains the output for the [FSCTL_GET_BOOT_AREA_INFO](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-get-boot-area-info) control code.

## Members

### `BootSectorCount`

The number of elements in the **BootSectors** array.

### `Offset`

### `BootSectors`

A variable length array of structures. Each structure contains an **Offset** member.

#### Offset

The location of a boot sector or a copy of a boot sector.

## See also

[FSCTL_GET_BOOT_AREA_INFO](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-get-boot-area-info)