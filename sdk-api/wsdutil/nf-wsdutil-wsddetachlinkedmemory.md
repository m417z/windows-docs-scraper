# WSDDetachLinkedMemory function

## Description

Detaches a child memory block from its parent memory block.

## Parameters

### `pVoid`

Pointer to the memory block to be detached.

## Remarks

The child memory block must have been previously allocated by a call to [WSDAllocateLinkedMemory](https://learn.microsoft.com/windows/desktop/api/wsdutil/nf-wsdutil-wsdallocatelinkedmemory).