# MiniDumpWriteDump function

## Description

Writes user-mode minidump information to the specified file.

## Parameters

### `hProcess` [in]

A handle to the process for which the information is to be generated.

This handle must have **PROCESS_QUERY_INFORMATION** and
**PROCESS_VM_READ** access to the process. If handle information is to be collected then
**PROCESS_DUP_HANDLE** access is also required. For more information, see
[Process Security and Access Rights](https://learn.microsoft.com/windows/desktop/ProcThread/process-security-and-access-rights).
The caller must also be able to get **THREAD_ALL_ACCESS** access to the threads in the
process. For more information, see
[Thread Security and Access Rights](https://learn.microsoft.com/windows/desktop/ProcThread/thread-security-and-access-rights).

### `ProcessId` [in]

The identifier of the process for which the information is to be generated.

### `hFile` [in]

A handle to the file in which the information is to be written.

### `DumpType` [in]

The type of information to be generated. This parameter can be one or more of the values from the
[MINIDUMP_TYPE](https://learn.microsoft.com/windows/desktop/api/minidumpapiset/ne-minidumpapiset-minidump_type) enumeration.

### `ExceptionParam` [in]

A pointer to a
[MINIDUMP_EXCEPTION_INFORMATION](https://learn.microsoft.com/windows/win32/api/minidumpapiset/ns-minidumpapiset-minidump_exception_information)
structure describing the client exception that caused the minidump to be generated. If the value of this
parameter is **NULL**, no exception information is included in the minidump file.

### `UserStreamParam` [in]

A pointer to a
[MINIDUMP_USER_STREAM_INFORMATION](https://learn.microsoft.com/windows/win32/api/minidumpapiset/ns-minidumpapiset-minidump_user_stream_information)
structure. If the value of this parameter is **NULL**, no user-defined information is
included in the minidump file.

### `CallbackParam` [in]

A pointer to a
[MINIDUMP_CALLBACK_INFORMATION](https://learn.microsoft.com/windows/win32/api/minidumpapiset/ns-minidumpapiset-minidump_callback_information)
structure that specifies a callback routine which is to receive extended minidump information. If the value of
this parameter is **NULL**, no callbacks are performed.

## Return value

If the function succeeds, the return value is **TRUE**; otherwise, the return value is
**FALSE**. To retrieve extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). Note that the last error will be an
**HRESULT** value.

If the operation is canceled, the last error code is
`HRESULT_FROM_WIN32(ERROR_CANCELLED)`.

## Remarks

The [MiniDumpCallback](https://learn.microsoft.com/windows/desktop/api/minidumpapiset/nc-minidumpapiset-minidump_callback_routine) function receives extended
minidump information from **MiniDumpWriteDump**. It also
provides a way for the caller to determine the granularity of information written to the minidump file, as the
callback function can filter the default information.

**MiniDumpWriteDump** should be called from a
separate process if at all possible, rather than from within the target process being dumped. This is especially
true when the target process is already not stable. For example, if it just crashed. A loader deadlock is one of
many potential side effects of calling
**MiniDumpWriteDump** from within the target
process.
If calling **MiniDumpWriteDump** from a separate process is not possible, then it is advisable to have
a dedicated thread whose sole purpose is to call **MiniDumpWriteDump**. This can help ensure that the stack
is not already exhausted before the call to **MiniDumpWriteDump**.

**MiniDumpWriteDump** may not produce a valid stack
trace for the calling thread. To work around this problem, you must capture the state of the calling thread before
calling **MiniDumpWriteDump** and use it as the
*ExceptionParam* parameter. One way to do this is to force an exception inside a
**__try**/**__except** block and use the
[EXCEPTION_POINTERS](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-exception_pointers) information provided by
[GetExceptionInformation](https://learn.microsoft.com/windows/desktop/Debug/getexceptioninformation). Alternatively, you
can call the function from a new worker thread and filter this worker thread from the dump.

All DbgHelp functions, such as this one, are single threaded. Therefore, calls from more than one thread to
this function will likely result in unexpected behavior or memory corruption. To avoid this, you must synchronize
all concurrent calls from more than one thread to this function.

## See also

[DbgHelp Functions](https://learn.microsoft.com/windows/desktop/Debug/dbghelp-functions)

[MINIDUMP_CALLBACK_INFORMATION](https://learn.microsoft.com/windows/win32/api/minidumpapiset/ns-minidumpapiset-minidump_callback_information)

[MINIDUMP_EXCEPTION_INFORMATION](https://learn.microsoft.com/windows/win32/api/minidumpapiset/ns-minidumpapiset-minidump_exception_information)

[MINIDUMP_USER_STREAM_INFORMATION](https://learn.microsoft.com/windows/win32/api/minidumpapiset/ns-minidumpapiset-minidump_user_stream_information)

[MiniDumpCallback](https://learn.microsoft.com/windows/desktop/api/minidumpapiset/nc-minidumpapiset-minidump_callback_routine)

[MiniDumpReadDumpStream](https://learn.microsoft.com/windows/desktop/api/minidumpapiset/nf-minidumpapiset-minidumpreaddumpstream)