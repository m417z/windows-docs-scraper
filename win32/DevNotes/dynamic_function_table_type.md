# DYNAMIC_FUNCTION_TABLE structure

The **DYNAMIC_FUNCTION_TABLE** structure is an entry in a linked list which is used by a debugger to discover all of the dynamic function tables in a target process. The root node in this linked list is returned from [**RtlGetFunctionTableListHead**](https://learn.microsoft.com/windows/win32/devnotes/rtlgetfunctiontablelisthead)

## Members

**ListEntry**

[**LIST_ENTRY**](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-list_entry) structure used to point at next and previous entries in the list.

**FunctionTable**

For function tables which are not `RF_CALLBACK`, this points at an array of [**RUNTIME_FUNCTION**](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-runtime_function) structures.

**Reserved1**

Reserved.

**MinimumAddress**

Smallest instruction address described by this table.

**MaximumAddress**

Largest instruction address described by this table.

**BaseAddress**

The base address to use when computing full virtual addresses from relative virtual addresses of function table entries.

**Reserved2**

Reserved.

**OutOfProcessCallbackDll**

For function tables which are `RF_CALLBACK`, this contains an optional pointer to a string that specifies the path of a DLL that provides function table entries from outside of the target process.

When a debugger unwinds to a function in the range of addresses managed by the callback function, it loads this DLL and calls the **OUT_OF_PROCESS_FUNCTION_TABLE_CALLBACK_EXPORT_NAME**
function, whose type is [**POUT_OF_PROCESS_FUNCTION_TABLE_CALLBACK**](https://learn.microsoft.com/windows/win32/devnotes/pout_of_process_function_table_callback).

**Type**

A member of the [FUNCTION_TABLE_TYPE](https://learn.microsoft.com/windows/win32/devnotes/function_table_type_enum) enumeration.

**EntryCount**

The number of entries in the `FunctionTable` array.

## Remarks

This struct has no associated import library or header file. The structure may be changed or removed from Windows without further notice.