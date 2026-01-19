# ProcessName function

## Description

Gets the process name of the UI Automation client application.

## Parameters

### `processName` [ out, retval]

The file name as a `BSTR`.

## Return value

S_OK - If process name retrieved successfully.

E_INVALIDARG - If *processName* parameter is null.

E_OUTOFMEMORY - If memory allocation for the process name failed.

## Remarks

Call [SysFreeString](https://learn.microsoft.com/windows/win32/api/oleauto/nf-oleauto-sysfreestring) to free allocated memory.

## See also