# LSA_CREATE_THREAD callback function

## Description

The **CreateThread** function is a wrapper for the Windows
[CreateThread](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createthread) function that should be used by the [Local Security Authority](https://learn.microsoft.com/windows/desktop/SecGloss/l-gly) (LSA). It creates a thread that the LSA can track, attaches debugging information to threads it starts, and provides special exception handling to protect the LSA process.

## Parameters

### `SecurityAttributes` [in]

Pointer to a **SEC_ATTRS** structure that determines whether the returned handle can be inherited by child processes.

### `StackSize` [in]

Specifies the initial commit size of the stack, in bytes.

### `StartFunction` [in]

Pointer to the application-defined function of type **SEC_THREAD_START** to be executed by the thread.

### `ThreadParameter` [in]

Pointer to a single parameter value passed to the thread.

### `CreationFlags` [in]

Specifies flags that control the creation of the thread.

### `ThreadId` [out]

Pointer to a variable that receives the thread identifier.

## Return value

If the function succeeds, the return value is a handle to the new thread. When you have finished using the handle, close it by calling the [CloseHandle](https://learn.microsoft.com/windows/desktop/api/handleapi/nf-handleapi-closehandle) function.

If the function fails, the return value is **NULL**. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

A pointer to the **CreateThread** function is available in the
[LSA_SECPKG_FUNCTION_TABLE](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-lsa_secpkg_function_table) structure received by the
[SpInitialize](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-spinitializefn) function.

For more information, see the Windows
[CreateThread](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createthread) function.

## See also

[CreateThread](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createthread)

[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror)

[LSA_SECPKG_FUNCTION_TABLE](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/ns-ntsecpkg-lsa_secpkg_function_table)

[SpInitialize](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-spinitializefn)