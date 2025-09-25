# GetThreadSelectorEntry function

## Description

Retrieves a descriptor table entry for the specified selector and thread.

## Parameters

### `hThread` [in]

A handle to the thread containing the specified selector. The handle must have THREAD_QUERY_INFORMATION access. For more information, see
[Thread Security and Access Rights](https://learn.microsoft.com/windows/desktop/ProcThread/thread-security-and-access-rights).

### `dwSelector` [in]

The global or local selector value to look up in the thread's descriptor tables.

### `lpSelectorEntry` [out]

A pointer to an
[LDT_ENTRY](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-ldt_entry) structure that receives a copy of the descriptor table entry if the specified selector has an entry in the specified thread's descriptor table. This information can be used to convert a segment-relative address to a linear virtual address.

## Return value

If the function succeeds, the return value is nonzero. In that case, the structure pointed to by the *lpSelectorEntry* parameter receives a copy of the specified descriptor table entry.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

**GetThreadSelectorEntry** is only functional on x86-based systems. For systems that are not x86-based, the function returns **FALSE**.

Debuggers use this function to convert segment-relative addresses to linear virtual addresses. The
[ReadProcessMemory](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-readprocessmemory) and
[WriteProcessMemory](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-writeprocessmemory) functions use linear virtual addresses.

## See also

[Debugging Functions](https://learn.microsoft.com/windows/desktop/Debug/debugging-functions)

[LDT_ENTRY](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-ldt_entry)

[ReadProcessMemory](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-readprocessmemory)

[WriteProcessMemory](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-writeprocessmemory)