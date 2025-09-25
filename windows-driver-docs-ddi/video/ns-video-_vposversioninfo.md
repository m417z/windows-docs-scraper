# _VPOSVERSIONINFO structure

## Description

The VPOSVERSIONINFO structure contains version information about the currently running operating system.

## Members

### `Size`

Specifies the size, in bytes, of the VPOSVERSIONINFO structure.

### `MajorVersion`

Specifies the major version number of the operating system. For example, for Windows 2000, the major version number is five. For Windows XP, the major version number is six.

### `MinorVersion`

Specifies the minor version number of the operating system. For example, for Windows 2000, the minor version number is zero.

### `BuildNumber`

Specifies the build number of the operating system.

### `ServicePackMajor`

Specifies the major version number of the latest Service Pack installed on the operating system. For example, for Service Pack 3, the major version number is three.

### `ServicePackMinor`

Specifies the minor version number of the latest Service Pack installed on the operating system. For example, for Service Pack 3, the minor version number is zero.

## Remarks

This structure is available in Windows XP and later.

To obtain version information about the currently running operating system, a video miniport driver would call the [VideoPortGetVersion](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportgetversion) function, which fills in this structure.

## See also

[VideoPortGetVersion](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportgetversion)