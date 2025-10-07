# POUT_OF_PROCESS_FUNCTION_TABLE_CALLBACK callback function

Pointer to a function that is used by a debugger to obtain function table entries from a provider that was registered using [**RtlAddFunctionTable**](https://learn.microsoft.com/windows/win32/api/winnt/nf-winnt-rtladdfunctiontable). This must be exported from a DLL and named **OUT_OF_PROCESS_FUNCTION_TABLE_CALLBACK_EXPORT_NAME**. It will be invoked by a debugger from within the debugger's process.

## Parameters

### Process \[in\]

Handle to the target process.

### TableAddress \[in\]

Address of the [**DYNAMIC_FUNCTION_TABLE**](https://learn.microsoft.com/windows/win32/devnotes/dynamic_function_table_type) in the target process.

### Entries \[out\]

Returned count of entries in the *Functions* array.

### Functions \[out\]

Returned pointer to an array of [**RUNTIME_FUNCTION**](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-runtime_function) entries. This array must be allocated using [**HeapAlloc**](https://learn.microsoft.com/windows/win32/api/heapapi/nf-heapapi-heapalloc) on the heap returned from [**GetProcessHeap**](https://learn.microsoft.com/windows/win32/api/heapapi/nf-heapapi-getprocessheap).

## Return value

**NTSTATUS** code indicating if the function was able to successfully obtain the *Functions* array. *STATUS_SUCCESS* \(0x0\) indicates success.

## Remarks

Out of process function table dlls must be registered in `HKEY_LOCAL_MACHINE\Software\Microsoft\Windows NT\CurrentVersion\KnownFunctionTableDlls` to be loaded by the Visual Studio or Windows debuggers.