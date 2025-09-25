# RtlGrowFunctionTable function

## Description

Reports that a dynamic function table has increased in size.

## Parameters

### `DynamicTable`

An opaque reference returned by [RtlAddGrowableFunctionTable.](https://learn.microsoft.com/windows/desktop/api/winnt/nf-winnt-rtladdgrowablefunctiontable).

### `NewEntryCount` [in]

The new number of entries in the [RUNTIME_FUNCTION](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-runtime_function) array. This must be greater than the previously reported size of the array.

## Return value

This function does not return a value.

## Remarks

**RtlGrowFunctionTable** should be called after populating the corresponding entries in the [RUNTIME_FUNCTION](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-runtime_function) array specified in [RtlAddGrowableFunctionTable.](https://learn.microsoft.com/windows/desktop/api/winnt/nf-winnt-rtladdgrowablefunctiontable)