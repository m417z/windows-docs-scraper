# NVME_LBA_RANGE_TYPES enumeration

## Description

Contains values that indicate the type of Logical Block Addressing (LBA) range in an LBA Range Type entry [NVME_LBA_RANGET_TYPE_ENTRY](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_lba_ranget_type_entry) structure.

## Constants

### `NVME_LBA_RANGE_TYPE_RESERVED`

The reserved LBA range.

### `NVME_LBA_RANGE_TYPE_FILESYSTEM`

The filesystem LBA range.

### `NVME_LBA_RANGE_TYPE_RAID`

The RAID LBA range.

### `NVME_LBA_RANGE_TYPE_CACHE`

The cache LBA range.

### `NVME_LBA_RANGE_TYPE_PAGE_SWAP_FILE`

The page/swap file LBA range.

## Remarks

LBA range information ise used by a driver to determine if it may utilize a particular LBA range. The information is not exposed to higher level software.

## See also

[NVME_LBA_RANGET_TYPE_ENTRY](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_lba_ranget_type_entry)