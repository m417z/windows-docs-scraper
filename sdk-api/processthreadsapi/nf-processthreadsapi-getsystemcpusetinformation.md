## Description

Allows an application to query the available CPU Sets on the system, and their current state.

## Parameters

### `Information`

A pointer to a [**SYSTEM\_CPU\_SET\_INFORMATION**](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-system_cpu_set_information) structure that receives the CPU Set data. Pass NULL with a buffer length of 0 to determine the required buffer size.

### `BufferLength`

The length, in bytes, of the output buffer passed as the Information argument.

### `ReturnedLength`

The length, in bytes, of the valid data in the output buffer if the buffer is large enough, or the required size of the output buffer. If no CPU Sets exist, this value will be 0.

### `Process`

An optional handle to a process. This process is used to determine the value of the **AllocatedToTargetProcess** flag in the SYSTEM\_CPU\_SET\_INFORMATION structure. If a CPU Set is allocated to the specified process, the flag is set. Otherwise, it is clear. This handle must have the PROCESS\_QUERY\_LIMITED\_INFORMATION access right. The value returned by [**GetCurrentProcess**](https://learn.microsoft.com/windows/win32/api/processthreadsapi/nf-processthreadsapi-getcurrentprocess) may also be specified here.

### `Flags`

Reserved, must be 0.

## Return value

If the API succeeds it returns TRUE. If it fails, the error reason is available through **GetLastError**. If the Information buffer was NULL or not large enough, the error code ERROR\_INSUFFICIENT\_BUFFER is returned. This API cannot fail when passed valid parameters and a buffer that is large enough to hold all of the return data.

## Remarks

## See also