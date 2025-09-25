# WSDAllocateLinkedMemory function

## Description

Allocates a linked memory block.

## Parameters

### `pParent`

 Pointer to the parent memory block.

### `cbSize`

Size of the memory block to be allocated.

## Return value

Pointer to the newly allocated memory block.

## Remarks

The memory
block allocated by **WSDAllocateLinkedMemory** is linked to a parent memory block and is freed when
the parent memory block is freed.

 If *pParent* is **NULL** the allocated memory block must be explicitly freed by calling
[WSDFreeLinkedMemory](https://learn.microsoft.com/windows/desktop/api/wsdutil/nf-wsdutil-wsdfreelinkedmemory).