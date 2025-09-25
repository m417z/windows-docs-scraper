# WSDFreeLinkedMemory function

## Description

Frees a memory block previously allocated with [WSDAllocateLinkedMemory](https://learn.microsoft.com/windows/desktop/api/wsdutil/nf-wsdutil-wsdallocatelinkedmemory).

## Parameters

### `pVoid`

Pointer to the memory block to be freed.

## Remarks

All children of the memory block are automatically freed.