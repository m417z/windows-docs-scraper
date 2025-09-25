# IDebugHostMemory::GetDisplayStringForLocation

## Description

For a given location within the address space of the target as defined by context and location, convert the location to a displayable string (according to whatever format the host chooses).

If the "verbose" argument is true, the string conversion may be "more verbose"

## Parameters

### `context`

The host context in which the location is valid. This represents, for example, the address space in which the location exists.

### `location`

The location to convert to a displayable string.

### `verbose`

An indication of whether the conversion should be verbose or not. A verbose conversion will contain more information than a non-verbose one. The default is for a non-verbose conversion.

### `locationName`

A displayable string for the location will be returned here. This string is allocated by SysAllocString and the caller is responsible for freeing the allocation with a call to the SysFreeString function.

## Return value

This method returns HRESULT which indicates success or failure.

## Remarks

## See also

[IDebugHostMemory interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idebughostmemory)