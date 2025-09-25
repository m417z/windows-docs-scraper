# eHeapAllocationState enumeration

## Description

Specifies the current heap allocation state.

## Constants

### `HeapFullPageHeap:0x40000000`

Specifies the full-page heap arrangement is being used.

### `HeapMetadata:0x80000000`

Specifies the highest bit. When set, it has not been allocated by the user.

### `HeapStateMask:0xFFFF0000`

Specifies a value to be used as a mask with the bitwise AND operator to indicate whether the allocation is by the user.

## See also

[Resource Enumeration](https://learn.microsoft.com/windows/desktop/DevNotes/resource-enumeration)

[VerifierEnumerateResource](https://learn.microsoft.com/windows/desktop/api/avrfsdk/nf-avrfsdk-verifierenumerateresource)