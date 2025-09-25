# AVRF_RESOURCE_ENUMERATE_CALLBACK callback function

## Description

Provides access to one of the specialized callback functions for enumeration of either heap allocation or handle trace information.

## Parameters

### `ResourceDescription`

A pointer to either an [AVRF_HANDLE_OPERATION](https://learn.microsoft.com/windows/desktop/api/avrfsdk/ns-avrfsdk-avrf_handle_operation) structure or an [AVRF_HEAP_ALLOCATION](https://learn.microsoft.com/windows/desktop/api/avrfsdk/ns-avrfsdk-avrf_heap_allocation) structure. Be sure to cast this parameter to the correct structure type.

### `EnumerationContext`

A pointer to be passed to the resource-specific callback function.

### `EnumerationLevel`

Specifies whether the enumeration operation should continue. This must be one of the values in the [eHeapEnumerationLevel](https://learn.microsoft.com/windows/desktop/api/avrfsdk/ne-avrfsdk-eheapenumerationlevel) enum.

## Return value

This function returns error codes or other values defined by the application.

## See also

[Resource Enumeration](https://learn.microsoft.com/windows/desktop/DevNotes/resource-enumeration)

[VerifierEnumerateResource](https://learn.microsoft.com/windows/desktop/api/avrfsdk/nf-avrfsdk-verifierenumerateresource)