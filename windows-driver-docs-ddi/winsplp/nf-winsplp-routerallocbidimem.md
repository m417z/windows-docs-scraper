# RouterAllocBidiMem function

## Description

`RouterAllocBidiMem` allocates a block of memory of a specified size. This function is used by the port monitor to allocate memory for strings and binary objects.

## Parameters

### `NumBytes` [in]

Specifies the size, in bytes, of the block of memory to be allocated.

## Return value

`RouterAllocBidiMem` returns a pointer to the block of memory if successful. If the function fails, the caller can obtain the error code by calling **GetLastError** (described in the Microsoft Windows SDK documentation).

## Remarks

When the memory allocated by this function is no longer needed, it can be returned by a call to [RouterFreeBidiMem](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-routerfreebidimem).

## See also

[RouterFreeBidiMem](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-routerfreebidimem)

[SendRecvBidiDataFromPort](https://learn.microsoft.com/previous-versions/ff562071(v=vs.85))