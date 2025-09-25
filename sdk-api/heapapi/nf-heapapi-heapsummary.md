## Description

Summarizes the specified heap.

## Parameters

### `hHeap` [in]

A handle to the heap to be summarized. This handle is returned by either the
[HeapCreate](https://learn.microsoft.com/windows/desktop/api/heapapi/nf-heapapi-heapcreate) or
[GetProcessHeap](https://learn.microsoft.com/windows/desktop/api/heapapi/nf-heapapi-getprocessheap) function.

### `dwFlags` [in]

The heap summary options. No options are currently defined, pass zero for this parameter.

### `lpSummary` [in, out]

A pointer to a [HEAP_SUMMARY](https://learn.microsoft.com/windows/win32/api/heapapi/ns-heapapi-heap_summary) structure that receives the information. Note that you must set the **cbSize** member to `sizeof(HEAP_SUMMARY)` before calling this function.

## Return value

Returns TRUE on success, FALSE on failure.

## Remarks

## See also