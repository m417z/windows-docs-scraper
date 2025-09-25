# RtlAddGrowableFunctionTable function

## Description

Informs the system of a dynamic function table representing a region of memory containing
code.

## Parameters

### `DynamicTable` [out]

A pointer to a variable that receives an opaque reference to the newly-added table on success.

### `FunctionTable`

A pointer to a partially-filled array of
[RUNTIME_FUNCTION](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-runtime_function) entries which provides
unwind information for the region of code. The entries in this array must remain sorted in ascending order of
the **BeginAddress** members.

### `EntryCount` [in]

The number of entries currently populated in the function table. This value may be zero.

### `MaximumEntryCount` [in]

The capacity of the function table.

### `RangeBase` [in]

The beginning of the memory range described by the function table.

### `RangeEnd` [in]

The end of the memory range described by the function table.

## Return value

This function returns zero on success. (More detail).

See
[http://msdn.microsoft.com/en-us/library/cc704588(PROT.10).aspx](https://learn.microsoft.com/openspecs/windows_protocols/ms-erref/596a1078-e883-4972-9bbc-49e60bebca55)
for a list of **NTSTATUS** values.

## Remarks

The function table can grow as code is added to the memory region. The entries in the table must be sorted.
This table is used for dispatching exceptions through runtime-generated code and for collecting stack
backtraces.