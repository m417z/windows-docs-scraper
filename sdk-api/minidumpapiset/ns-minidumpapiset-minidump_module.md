# MINIDUMP_MODULE structure

## Description

Contains information for a specific module.

## Members

### `BaseOfImage`

The base address of the module executable image in memory.

### `SizeOfImage`

The size of the module executable image in memory, in bytes.

### `CheckSum`

The checksum value of the module executable image.

### `TimeDateStamp`

The timestamp value of the module executable image, in **time_t** format.

### `ModuleNameRva`

An RVA to a
[MINIDUMP_STRING](https://learn.microsoft.com/windows/desktop/api/minidumpapiset/ns-minidumpapiset-minidump_string) structure that specifies the name of the module.

### `VersionInfo`

A
[VS_FIXEDFILEINFO](https://learn.microsoft.com/windows/desktop/api/verrsrc/ns-verrsrc-vs_fixedfileinfo) structure that specifies the version of the module.

### `CvRecord`

 A [MINIDUMP_LOCATION_DESCRIPTOR](https://learn.microsoft.com/windows/win32/api/minidumpapiset/ns-minidumpapiset-minidump_location_descriptor) structure that specifies the CodeView record of the module.

### `MiscRecord`

A [MINIDUMP_LOCATION_DESCRIPTOR](https://learn.microsoft.com/windows/win32/api/minidumpapiset/ns-minidumpapiset-minidump_location_descriptor) structure that specifies the miscellaneous record of the module.

### `Reserved0`

Reserved for future use.

### `Reserved1`

Reserved for future use.

## See also

[MINIDUMP_MODULE_LIST](https://learn.microsoft.com/windows/desktop/api/minidumpapiset/ns-minidumpapiset-minidump_module_list)

[MINIDUMP_STRING](https://learn.microsoft.com/windows/desktop/api/minidumpapiset/ns-minidumpapiset-minidump_string)

[VS_FIXEDFILEINFO](https://learn.microsoft.com/windows/desktop/api/verrsrc/ns-verrsrc-vs_fixedfileinfo)