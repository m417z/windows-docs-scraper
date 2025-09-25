# SHAlloc function

## Description

[This function is available through Windows XP Service Pack 2 (SP2) and Windows Server 2003. It might be altered or unavailable in subsequent versions of Windows. Use [CoTaskMemAlloc](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemalloc) instead.]

Allocates memory from the Shell's heap.

## Parameters

### `cb` [in]

Type: **SIZE_T**

The number of bytes of memory to allocate.

## Return value

Type: **LPVOID**

A pointer to the allocated memory.

## Remarks

You can free this memory by calling [SHFree](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-shfree).