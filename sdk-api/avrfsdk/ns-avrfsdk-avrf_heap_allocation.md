# AVRF_HEAP_ALLOCATION structure

## Description

Stores metadata information about heap allocation.

## Members

### `HeapHandle`

The handle to the heap being enumerated.

### `UserAllocation`

The address of the heap allocation as seen by the application.

### `UserAllocationSize`

The size, in bytes, of the application's allocation on the heap.

### `Allocation`

The address of the heap allocation as seen by the operating system.

### `AllocationSize`

The size, in bytes, of the heap allocation as seen by the operating system.

### `UserAllocationState`

One of the values in the [eUserAllocationState](https://learn.microsoft.com/windows/desktop/api/avrfsdk/ne-avrfsdk-euserallocationstate) enumerated type.

### `HeapState`

The state of the heap allocation. The user can extract one of the values in the [eHeapAllocationState](https://learn.microsoft.com/windows/desktop/api/avrfsdk/ne-avrfsdk-eheapallocationstate) enum after AND-ing the **HeapStateMask** value.

### `HeapContext`

The context of the heap currently allocated.

### `BackTraceInformation`

A pointer to an [AVRF_BACKTRACE_INFORMATION](https://learn.microsoft.com/windows/desktop/api/avrfsdk/ns-avrfsdk-avrf_backtrace_information) structure containing information about the last operation that occurred on the allocation.

When available, it can be the stack backtrace of the place where the address specified in the **UserAllocation** member of the structure was allocated (if **UserAllocationState** is **AllocationstateBusy**) or where the address specified in the **UserAllocation** member was freed (if **UserAllocationState** is **AllocationStateFree**).

## See also

[Resource Enumeration](https://learn.microsoft.com/windows/desktop/DevNotes/resource-enumeration)

[VerifierEnumerateResource](https://learn.microsoft.com/windows/desktop/api/avrfsdk/nf-avrfsdk-verifierenumerateresource)