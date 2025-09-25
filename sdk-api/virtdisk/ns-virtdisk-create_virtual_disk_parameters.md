# CREATE_VIRTUAL_DISK_PARAMETERS structure

## Description

Contains virtual hard disk (VHD) creation parameters, providing control over, and information about,
the newly created virtual disk.

## Members

### `Version`

A value from the [CREATE_VIRTUAL_DISK_VERSION](https://learn.microsoft.com/windows/win32/api/virtdisk/ne-virtdisk-create_virtual_disk_version)
enumeration that is the discriminant for the union.

| Value | Meaning |
| --- | --- |
| **CREATE_VIRTUAL_DISK_VERSION_1**<br><br>1 | Use the **Version1** member of this structure. |
| **CREATE_VIRTUAL_DISK_VERSION_2**<br><br>2 | Use the **Version2** member of this structure. |

### `Version1`

This structure is used if the **Version** member is
**CREATE_VIRTUAL_DISK_VERSION_1** (1).

### `Version1.UniqueId`

Unique identifier to assign to the virtual disk object. If this member is set to zero, a unique
identifier is created by the system.

### `Version1.MaximumSize`

The maximum virtual size, in bytes, of the virtual disk object. Must be a multiple of 512.

If a **ParentPath** is specified, this value must be zero.

If a **SourcePath** is specified, this value can be zero to specify the size of the
source virtual disk to be used, otherwise the size specified must be greater than or equal to the size of the
source disk.

### `Version1.BlockSizeInBytes`

Internal size of the virtual disk object blocks, in bytes. This must be set to
one of the following values.

| Value | Meaning |
| --- | --- |
| **CREATE_VIRTUAL_DISK_PARAMETERS_DEFAULT_BLOCK_SIZE**<br><br>0 | This is the default value and represents a block size of 2 MB. |
| 524288 (0x80000) | The block size is 512 KB. |
| 2097152 (0x200000) | The block size is 2 MB |

### `Version1.SectorSizeInBytes`

Internal size of the virtual disk object sectors. Must be set to 512.

| Value | Meaning |
| --- | --- |
| **CREATE_VIRTUAL_DISK_PARAMETERS_DEFAULT_SECTOR_SIZE**<br><br>0x200 | The default and only allowable size, 512 bytes. |

### `Version1.ParentPath`

Optional [fully qualified](https://learn.microsoft.com/windows/desktop/FileIO/naming-a-file) path to a parent
virtual disk object. Associates the new virtual disk with an existing virtual disk.

If this parameter is not **NULL**, **SourcePath** must be
**NULL**.

### `Version1.SourcePath`

Optional [fully qualified](https://learn.microsoft.com/windows/desktop/FileIO/naming-a-file) path to
pre-populate the new virtual disk object with block data from an existing disk. This path may refer to a
virtual disk or a physical disk.

If this parameter is not **NULL**, **ParentPath** must be
**NULL**.

### `Version2`

This structure is used if the **Version** member is
**CREATE_VIRTUAL_DISK_VERSION_2** (2).

**Windows 7 and Windows Server 2008 R2:** This structure is not supported until Windows 8 and Windows Server 2012.

### `Version2.UniqueId`

Unique identifier to assign to the virtual disk object. If this member is set to zero, a unique
identifier is created by the system.

### `Version2.MaximumSize`

The maximum virtual size, in bytes, of the virtual disk object. Must be a multiple of 512.

If a **ParentPath** is specified, this value must be zero.

If a **SourcePath** is specified, this value can be zero to specify the size of the
source virtual disk to be used, otherwise the size specified must be greater than or equal to the size of the
source disk.

### `Version2.BlockSizeInBytes`

Internal size of the virtual disk object blocks, in bytes. For VHDX this must be a multiple
of 1 MB between 1 and 256 MB. For VHD 1 this must be set to
one of the following values.

| Value | Meaning |
| --- | --- |
| **CREATE_VIRTUAL_DISK_PARAMETERS_DEFAULT_BLOCK_SIZE**<br><br>0 | This is the default value and represents a block size of 2 MB. This is the only supported value for fixed VHD 1 virtual disks. |
| 524288 (0x80000) | The block size is 512 KB. This value is not supported on fixed VHD 1 virtual disks. |
| 2097152 (0x200000) | The block size is 2 MB. This value is not supported on fixed VHD 1 virtual disks. |

### `Version2.SectorSizeInBytes`

Internal size of the virtual disk object sectors. For VHDX must be set to 512 (0x200) or
4096 (0x1000). For VHD 1 must be set to 512.

### `Version2.PhysicalSectorSizeInBytes`

### `Version2.ParentPath`

Optional [fully qualified](https://learn.microsoft.com/windows/desktop/FileIO/naming-a-file) path to a parent
virtual disk object. Associates the new virtual disk with an existing virtual disk.

If this parameter is not **NULL**, **SourcePath** must be
**NULL**.

### `Version2.SourcePath`

Optional [fully qualified](https://learn.microsoft.com/windows/desktop/FileIO/naming-a-file) path to
pre-populate the new virtual disk object with block data from an existing disk. This path may refer to a
virtual disk or a physical disk.

If this parameter is not **NULL**, **ParentPath** must be
**NULL**.

### `Version2.OpenFlags`

Zero or more flags from the
[OPEN_VIRTUAL_DISK_FLAG](https://learn.microsoft.com/windows/win32/api/virtdisk/ne-virtdisk-open_virtual_disk_flag) enumeration describing
how the virtual disk is to be opened.

### `Version2.ParentVirtualStorageType`

A [VIRTUAL_STORAGE_TYPE](https://learn.microsoft.com/windows/win32/api/virtdisk/ns-virtdisk-virtual_storage_type) structure describing
the parent virtual disk specified in the **ParentPath** member.

### `Version2.SourceVirtualStorageType`

A [VIRTUAL_STORAGE_TYPE](https://learn.microsoft.com/windows/win32/api/virtdisk/ns-virtdisk-virtual_storage_type) structure describing
the source virtual disk specified in the **SourcePath** member.

### `Version2.ResiliencyGuid`

Resiliency **GUID** for the file.

> [!NOTE]
> The following parameters prefaced Version3 and Version4 are intended for internal use.

## Syntax

```cpp
typedef struct _CREATE_VIRTUAL_DISK_PARAMETERS {
  CREATE_VIRTUAL_DISK_VERSION Version;
  union {
    struct {
      GUID      UniqueId;
      ULONGLONG MaximumSize;
      ULONG     BlockSizeInBytes;
      ULONG     SectorSizeInBytes;
      PCWSTR    ParentPath;
      PCWSTR    SourcePath;
    } Version1;
    struct {
      GUID                   UniqueId;
      ULONGLONG              MaximumSize;
      ULONG                  BlockSizeInBytes;
      ULONG                  SectorSizeInBytes;
      ULONG                  PhysicalSectorSizeInBytes;
      PCWSTR                 ParentPath;
      PCWSTR                 SourcePath;
      OPEN_VIRTUAL_DISK_FLAG OpenFlags;
      VIRTUAL_STORAGE_TYPE   ParentVirtualStorageType;
      VIRTUAL_STORAGE_TYPE   SourceVirtualStorageType;
      GUID                   ResiliencyGuid;
    } Version2;
  };
} CREATE_VIRTUAL_DISK_PARAMETERS, *PCREATE_VIRTUAL_DISK_PARAMETERS;
```

## See also

[About VHD](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd323654(v=vs.85))

[CreateVirtualDisk](https://learn.microsoft.com/windows/win32/api/virtdisk/nf-virtdisk-createvirtualdisk)

[Naming Files, Paths, and Namespaces](https://learn.microsoft.com/windows/desktop/FileIO/naming-a-file)

[VHD Reference](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd323700(v=vs.85))

[VHD Structures](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd323701(v=vs.85))