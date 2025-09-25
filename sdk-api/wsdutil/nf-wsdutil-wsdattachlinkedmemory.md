# WSDAttachLinkedMemory function

## Description

Attaches a child memory block to a
parent memory block. Multiple children can be attached to a parent memory block.

## Parameters

### `pParent`

Pointer to the parent memory block.

### `pChild`

Pointer to the child memory block.

## Remarks

The child memory block is automatically freed when the parent memory
block is freed. Both the parent and child memory blocks must have been previously allocated by calls to [WSDAllocateLinkedMemory](https://learn.microsoft.com/windows/desktop/api/wsdutil/nf-wsdutil-wsdallocatelinkedmemory).