# NVME_LBA_RANGET_TYPE_ENTRY structure

## Description

Contains parameters that specify a single entry in a list of Logical Block Address (LBA) ranges, for the LBA Range Type Feature in the Set Features command.

## Members

### `Type`

An [NVME_LBA_RANGE_TYPES](https://learn.microsoft.com/windows/win32/api/nvme/ne-nvme-nvme_lba_range_types) value that specifies the type of the LBA range.

### `Attributes`

Specifies attributes for the LBA range. Each bit defines an attribute, as follows:

- Bit 0 - If this bit is set to `1`, the LBA range may be overwritten. If this bit is cleared to `0`, the LBA range should not be overwritten.
- Bit 1 - If this bit is set to `1`, the LBA range should be hidden from the OS/EFI/BIOS. If this bit is cleared to `0`, the area should be visible to the OS/EFI/BIOS.
- Bits 2-7 - Reserved

### `Attributes.MayOverwritten`

### `Attributes.Hidden`

### `Attributes.Reserved`

### `Attributes.Reserved0`

### `SLBA`

Specifies the 64-bit address of the first logical block that is part of this LBA range.

### `NLB`

Specifies the number of logical blocks that are part of this LBA range. This is a 0s based value.

### `GUID`

A Global Unique Identifier (GUID) that uniquely specifies the type of this LBA range. Well known Types may be defined and are published on the [NVM Express website](https://nvmexpress.org/).

### `Reserved1`

## Remarks

## See also

- [NVME_CDW11_FEATURE_LBA_RANGE_TYPE](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw11_feature_lba_range_type)