# MACHINE_ATTRIBUTES enumeration

## Description

Specifies the ways in which an architecture of code can run on a host operating system. More than one bit may be set.

## Constants

### `UserEnabled` : 0x00000001

The specified architecture of code can run in user mode.

### `KernelEnabled` : 0x00000002

The specified architecture of code can run in kernel mode.

### `Wow64Container` : 0x00000004

The specified architecture of code runs by relying on WOW64's namespace [File System Redirector](https://learn.microsoft.com/windows/win32/winprog64/file-system-redirector) and [Registry Redirector](https://learn.microsoft.com/windows/win32/winprog64/registry-redirector). This bit will be set, for example, on x86 code running on a host operating system that is x64 or ARM64. When the compatibility layer does not use WOW64 style filesystem and registry namespaces, like x64 on ARM64 which runs on the root namespace of the OS, this bit will be reset.

## Remarks

## See also