# MINIDUMP_UNLOADED_MODULE structure

## Description

Contains information about a module that has been unloaded. This information can help diagnose problems calling code that is no longer loaded.

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

## See also

[MINIDUMP_UNLOADED_MODULE_LIST](https://learn.microsoft.com/windows/win32/api/minidumpapiset/ns-minidumpapiset-minidump_unloaded_module_list)