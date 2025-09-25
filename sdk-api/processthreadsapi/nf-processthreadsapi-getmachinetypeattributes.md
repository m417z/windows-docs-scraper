## Description

Queries if the specified architecture is supported on the current system, either natively or by any form of compatibility or emulation layer.

## Parameters

### `Machine`

An IMAGE_FILE_MACHINE_* value corresponding to the architecture of code to be tested for supportability. See the list of architecture values in [Image File Machine Constants](https://learn.microsoft.com/windows/win32/sysinfo/image-file-machine-constants).

### `MachineTypeAttributes`

Output parameter receives a pointer to a value from the [MACHINE_ATTRIBUTES](https://learn.microsoft.com/windows/win32/api/processthreadsapi/ne-processthreadsapi-machine_attributes) enumeration indicating if the specified code architecture can run in user mode, kernel mode, and/or under WOW64 on the host operating system.

## Return value

If the function fails, the return value is a nonzero HRESULT value. If the function succeeds, the return value is zero.

## Remarks

## See also