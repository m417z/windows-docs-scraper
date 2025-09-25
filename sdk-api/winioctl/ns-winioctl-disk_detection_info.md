# DISK_DETECTION_INFO structure

## Description

Contains detected drive parameters.

## Members

### `SizeOfDetectInfo`

The size of the structure, in bytes.

### `DetectionType`

The detected partition type.

This member can be one of the following values from the **DETECTION_TYPE** enumeration.

| Value | Enumeration | Meaning |
| --- | --- | --- |
| **DetectExInt13** | 2 | The disk has an extended Int13 partition. |
| **DetectInt13** | 1 | The disk has a standard Int13 partition. |
| **DetectNone** | 0 | The disk does not have an Int13 or an extended Int13 partition. |

### `DUMMYUNIONNAME`

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME`

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME.Int13`

If **DetectionType** is DetectInt13, the union is a [**DISK_INT13_INFO**](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-disk_int13_info) structure.

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME.ExInt13`

If **DetectionType** is DetectExInt13, the union is a [**DISK_EX_INT13_INFO**](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-disk_ex_int13_info) structure.

## See also

[DISK_EX_INT13_INFO](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-disk_ex_int13_info), [DISK_INT13_INFO](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-disk_int13_info), [DISK_GEOMETRY_EX](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-disk_geometry_ex)