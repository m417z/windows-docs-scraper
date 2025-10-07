# FUNCTION_TABLE_TYPE enumeration

Describes the type of function table which a [**DYNAMIC\_FUNCTION\_TABLE**](https://learn.microsoft.com/windows/win32/devnotes/dynamic_function_table_type) represents.

## Constants

### RF_SORTED

Entries in `FunctionTable` are sorted by their address. These tables were added using [**RtlAddFunctionTable**](https://learn.microsoft.com/windows/win32/api/winnt/nf-winnt-rtladdfunctiontable).

### RF_UNSORTED

Entries in `FunctionTable` are unsorted. These tables were added using [**RtlAddFunctionTable**](https://learn.microsoft.com/windows/win32/api/winnt/nf-winnt-rtladdfunctiontable).

### RF_CALLBACK

The `FunctionTable` array is not allocated up front. Instead, values are provided via a callback. These table entries were added to the list using [**RtlInstallFunctionTableCallback**](https://learn.microsoft.com/windows/desktop/api/WinNT/nf-winnt-rtlinstallfunctiontablecallback).

### RF_KERNEL_DYNAMIC

Entries in `FunctionTable` are sorted by their address and installed by [**RtlAddGrowableFunctionTable**](https://learn.microsoft.com/windows/desktop/api/WinNT/nf-winnt-rtladdgrowablefunctiontable).

## Remarks

This enum has no associated import library or header file. Additional values may be added in the future without further notice.