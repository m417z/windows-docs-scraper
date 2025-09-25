# MODULEINFO structure

## Description

Contains the module load address, size, and entry point.

## Members

### `lpBaseOfDll`

The load address of the module.

### `SizeOfImage`

The size of the linear space that the module occupies, in bytes.

### `EntryPoint`

The entry point of the module.

## Remarks

The load address of a module is the same as the **HMODULE** value. The information returned in the **SizeOfImage** and **EntryPoint** members comes from the module's Portable Executable (PE) header. The module entry point is the location called during process startup, thread startup, process shutdown, and thread shutdown. While this is not the address of the
[DllMain](https://learn.microsoft.com/windows/desktop/Dlls/dllmain) function, it should be close enough for most purposes.

## See also

[GetModuleInformation](https://learn.microsoft.com/windows/desktop/api/psapi/nf-psapi-getmoduleinformation)