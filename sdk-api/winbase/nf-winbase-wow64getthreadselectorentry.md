# Wow64GetThreadSelectorEntry function

## Description

Retrieves a descriptor table entry for the specified selector and WOW64 thread.

## Parameters

### `hThread` [in]

A handle to the thread containing the
specified selector. The handle must have been created with
THREAD_QUERY_INFORMATION access to the thread. For more information, see
[Thread Security and Access Rights](https://learn.microsoft.com/windows/desktop/ProcThread/thread-security-and-access-rights).

### `dwSelector` [in]

The global or local selector value to look up in the thread's descriptor tables.

### `lpSelectorEntry` [out]

A pointer to a
[WOW64_LDT_ENTRY](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-wow64_ldt_entry) structure that receives a copy of the descriptor table entry if the specified selector has an entry in the specified thread's descriptor table. This information can be used to convert a segment-relative address to a linear virtual address.

## Return value

If the function succeeds, the return value is nonzero. In that case, the structure pointed to by the *lpSelectorEntry* parameter receives a copy of the specified descriptor table entry.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The **Wow64GetThreadSelectorEntry** function is functional only on 64-bit systems and can be called only by 64-bit processes. If this function is called by a 32-bit process, the function fails with ERROR_NOT_SUPPORTED. A 32-bit process should use the [GetThreadSelectorEntry](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getthreadselectorentry) function instead.

Debuggers use this function to convert segment-relative addresses to linear virtual addresses. The
[ReadProcessMemory](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-readprocessmemory) and
[WriteProcessMemory](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-writeprocessmemory) functions use linear virtual addresses.