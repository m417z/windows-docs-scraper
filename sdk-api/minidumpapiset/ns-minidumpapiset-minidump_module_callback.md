# MINIDUMP_MODULE_CALLBACK structure

## Description

Contains module information for the
[MiniDumpCallback](https://learn.microsoft.com/windows/desktop/api/minidumpapiset/nc-minidumpapiset-minidump_callback_routine) function when the callback type is
[ModuleCallback](https://learn.microsoft.com/windows/desktop/api/minidumpapiset/ne-minidumpapiset-minidump_callback_type).

## Members

### `FullPath`

The fully qualified path of the module executable.

### `BaseOfImage`

The base address of the module executable image in memory.

### `SizeOfImage`

The size of the module executable image in memory, in bytes.

### `CheckSum`

The checksum value of the module executable image.

### `TimeDateStamp`

The timestamp value of the module executable image, in **time_t** format.

### `VersionInfo`

A
[VS_FIXEDFILEINFO](https://learn.microsoft.com/windows/desktop/api/verrsrc/ns-verrsrc-vs_fixedfileinfo) structure that specifies the version of the module.

### `CvRecord`

A pointer to a string containing the CodeView record of the module.

### `SizeOfCvRecord`

The size of the Codeview record of the module in the **CvRecord** member, in bytes.

### `MiscRecord`

A pointer to a string that specifies the miscellaneous record of the module.

### `SizeOfMiscRecord`

The size of the miscellaneous record of the module in the **MiscRecord** member, in bytes.

## See also

[MINIDUMP_CALLBACK_INPUT](https://learn.microsoft.com/windows/win32/api/minidumpapiset/ns-minidumpapiset-minidump_callback_input)

[MiniDumpCallback](https://learn.microsoft.com/windows/desktop/api/minidumpapiset/nc-minidumpapiset-minidump_callback_routine)

[VS_FIXEDFILEINFO](https://learn.microsoft.com/windows/desktop/api/verrsrc/ns-verrsrc-vs_fixedfileinfo)