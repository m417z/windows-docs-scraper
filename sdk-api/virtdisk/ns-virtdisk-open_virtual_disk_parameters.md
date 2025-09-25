# OPEN_VIRTUAL_DISK_PARAMETERS structure

## Description

Contains virtual disk open request parameters.

## Members

### `Version`

An [OPEN_VIRTUAL_DISK_VERSION](https://learn.microsoft.com/windows/win32/api/virtdisk/ne-virtdisk-open_virtual_disk_version) enumeration
that specifies the version of the
**OPEN_VIRTUAL_DISK_PARAMETERS** structure
being passed to or from the VHD functions.

| Value | Meaning |
| --- | --- |
| **OPEN_VIRTUAL_DISK_VERSION_1**<br><br>1 | Use the **Version1** member of this structure. |
| **OPEN_VIRTUAL_DISK_VERSION_2**<br><br>2 | Use the **Version2** member of this structure. |

### `Version1`

This structure is used if the **Version** member is
**OPEN_VIRTUAL_DISK_VERSION_1** (1).

### `Version1.RWDepth`

Indicates the number of stores, beginning with the child, of the backing store chain to open as
read/write. The remaining stores in the differencing chain will be opened read-only. This is necessary for
merge operations to succeed.

| Value | Meaning |
| --- | --- |
| 0 | Do not open for read/write at any depth. This value should be used for read-only operations. |
| **OPEN_VIRTUAL_DISK_RW_DEPTH_DEFAULT**<br><br>1 | Default value to use if no other value is desired. |
| n (user-defined) | This integer value should be the number of merge levels plus one, if a merge operation is intended. |

### `Version2`

This structure is used if the **Version** member is
**OPEN_VIRTUAL_DISK_VERSION_2** (2).

**Windows 7 and Windows Server 2008 R2:** This structure is not supported until Windows 8 and Windows Server 2012.

### `Version2.GetInfoOnly`

If **TRUE**, indicates the handle is only to be used to get information on the virtual disk.

### `Version2.ReadOnly`

If **TRUE**, indicates the file backing store is to be opened as read-only.

### `Version2.ResiliencyGuid`

Resiliency **GUID** to specify when opening files.

> [!NOTE]
> The following parameters prefaced Version3 are intended for internal use.

## Syntax

```cpp
typedef struct _OPEN_VIRTUAL_DISK_PARAMETERS {
  OPEN_VIRTUAL_DISK_VERSION Version;
  union {
    struct {
      ULONG RWDepth;
    } Version1;
    struct {
      BOOL GetInfoOnly;
      BOOL ReadOnly;
      GUID ResiliencyGuid;
    } Version2;
  };
} OPEN_VIRTUAL_DISK_PARAMETERS, *POPEN_VIRTUAL_DISK_PARAMETERS;
```

## See also

[About VHD](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd323654(v=vs.85))

[OpenVirtualDisk](https://learn.microsoft.com/windows/win32/api/virtdisk/nf-virtdisk-openvirtualdisk)

[VHD Reference](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd323700(v=vs.85))