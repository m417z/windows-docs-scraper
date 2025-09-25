# InitializeProcThreadAttributeList function

## Description

Initializes the specified list of attributes for process and thread creation.

## Parameters

### `lpAttributeList` [out, optional]

The attribute list. This parameter can be NULL to determine the buffer size required to support the specified number of attributes.

### `dwAttributeCount` [in]

The count of attributes to be added to the list.

### `dwFlags`

This parameter is reserved and must be zero.

### `lpSize` [in, out]

If *lpAttributeList* is not NULL, this parameter specifies the size in bytes of the *lpAttributeList* buffer on input. On output, this parameter receives the size in bytes of the initialized attribute list.

If *lpAttributeList* is NULL, this parameter receives the required buffer size in bytes.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

First, call this function with the *dwAttributeCount* parameter set to the maximum number of attributes you will be using and the *lpAttributeList* to NULL. The function returns the required buffer size in bytes in the *lpSize* parameter.

**Note** This initial call will return an error by design. This is expected behavior.

Allocate enough space for the data in the *lpAttributeList* buffer and call the function again to initialize the buffer.

To add attributes to the list, call the [UpdateProcThreadAttribute](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-updateprocthreadattribute) function. To specify these attributes when creating a process, specify EXTENDED_STARTUPINFO_PRESENT in the *dwCreationFlag* parameter and a [STARTUPINFOEX](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-startupinfoexa) structure in the *lpStartupInfo* parameter. Note that you can specify the same **STARTUPINFOEX** structure to multiple child processes.

When you have finished using the list, call the [DeleteProcThreadAttributeList](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-deleteprocthreadattributelist) function.

## See also

[DeleteProcThreadAttributeList](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-deleteprocthreadattributelist)

[Process and Thread Functions](https://learn.microsoft.com/windows/desktop/ProcThread/process-and-thread-functions)

[UpdateProcThreadAttribute](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-updateprocthreadattribute)