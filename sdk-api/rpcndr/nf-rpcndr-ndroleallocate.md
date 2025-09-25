# NdrOleAllocate function

## Description

The **NdrOleAllocate** function is used by RPC to allocate memory for an object interface. This function is a wrapper for the [CoTaskMemAlloc](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemalloc) function.

## Parameters

### `Size` [in]

Memory to allocate, in bytes.

## Return value

Returns a void pointer to the allocated space upon success. Returns null upon failure due to insufficient memory.

## Remarks

To return a pointer other than a void, use a type cast on the return value. The memory pointed to by the return value is guaranteed to be suitably aligned for the storage of any type of object. If the *Size* parameter is zero, **NdrOleAllocate** allocates a zero-length item in the heap and returns a valid pointer to that item. Always check the return value from **NdrOleAllocate**, even if the amount of memory requested is small.

## See also

[CoTaskMemAlloc](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemalloc)