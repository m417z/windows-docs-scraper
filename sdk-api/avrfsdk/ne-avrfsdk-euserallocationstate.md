# eUserAllocationState enumeration

## Description

Specifies the application's current heap allocation state.

## Constants

### `AllocationStateUnknown`

The allocation state cannot be determined.

### `AllocationStateBusy`

The allocation state is currently in use.

### `AllocationStateFree`

Memory has been freed from the stack but has not been returned to the heap yet.

## See also

[Resource Enumeration](https://learn.microsoft.com/windows/desktop/DevNotes/resource-enumeration)

[VerifierEnumerateResource](https://learn.microsoft.com/windows/desktop/api/avrfsdk/nf-avrfsdk-verifierenumerateresource)