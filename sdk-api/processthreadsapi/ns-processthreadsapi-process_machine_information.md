# PROCESS_MACHINE_INFORMATION structure

## Description

Specifies the architecture of a process and if that architecture of code can run in user mode, kernel mode, and/or under WoW64 on the host operating system.

## Members

### `ProcessMachine`

An IMAGE_FILE_MACHINE_* value indicating the architecture of the associated process. See the list of architecture values in [Image File Machine Constants](https://learn.microsoft.com/windows/win32/sysinfo/image-file-machine-constants).

### `Res0`

Reserved.

### `MachineAttributes`

A value from the [MACHINE_ATTRIBUTES](https://learn.microsoft.com/windows/win32/api/processthreadsapi/ne-processthreadsapi-machine_attributes) enumeration indicating if the process's architecture can run in user mode, kernel mode, and/or under WOW64 on the host operating system.

## Remarks

## See also

[PROCESS_INFORMATION_CLASS](https://learn.microsoft.com/windows/win32/api/processthreadsapi/ne-processthreadsapi-process_information_class)