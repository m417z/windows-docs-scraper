# VerifierEnumerateResource function

## Description

Enumerates operating system resources for use by debugging and support tools.

## Parameters

### `Process`

A handle to the process in which resources are being enumerated.

When the *ResourceType* parameter is AvrfResrouceHeapAllocation, the handle must be opened with the PROCESS_VM_READ and PROCESS_QUERY_INFORMATION access rights.

If *ResourceType* is AvrfResrouceHeapAllocation and the *Flags* parameter contains AVRF_ENUM_RESOURCES_FLAGS_SUSPEND, the PROCESS_SUSPEND_RESUME flag must be used as well.

### `Flags`

If *ResourceType* is AvrfResourceHandleTrace, no flags are defined and the value for the Flags parameter must be 0.

If the *ResourceType* parameter is AvrfResourceHeapAllocation, the *Flags* parameter can be 0 or a combination of the following values.

| Value | Meaning |
| --- | --- |
| **AVRF_ENUM_RESOURCES_FLAGS_DONT_RESOLVE_TRACES** | The stack backtraces of the heap allocations, when present, are not copied over the ReturnAddresses array. This may speed up the enumeration process. |
| **AVRF_ENUM_RESOURCES_FLAGS_SUSPEND** | The process is suspended before the heap allocations enumeration is executed.This minimizes the chance that changing the heap might affect the enumeration. |

### `ResourceType`

This parameter can be one of the following values:

| Value | Meaning |
| --- | --- |
| **AvrfResourceHandleTrace** | The API enumerates the last recently saved operations on the handles from the handle table of the current process. |
| **AvrfResourceHeapAllocation** | The API enumerates heap allocation, including heap metadata blocks. |

### `ResourceCallback`

An application-defined function that is invoked by the API.

The prototype is agnostic toward the type of resource being enumerated. The use will pass a prototype suitable for the type of enumeration being performed

### `EnumerationContext`

An application-specific pointer that is passed back to the callback function.

## Return value

This function returns one of the [system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## Remarks

This function has no associated import library. You must use the [LoadLibrary](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress) functions to dynamically link to Verifier.dll.

#### Examples

See [Using Resource Enumeration](https://learn.microsoft.com/windows/desktop/DevNotes/using-resource-enumeration).

## See also

[AVRF_HANDLEOPERATION_ENUMERATE_CALLBACK](https://learn.microsoft.com/windows/desktop/api/avrfsdk/nc-avrfsdk-avrf_handleoperation_enumerate_callback)

[AVRF_HEAPALLOCATION_ENUMERATE_CALLBACK](https://learn.microsoft.com/windows/desktop/api/avrfsdk/nc-avrfsdk-avrf_heapallocation_enumerate_callback)

[AVRF_RESOURCE_ENUMERATE_CALLBACK](https://learn.microsoft.com/windows/desktop/api/avrfsdk/nc-avrfsdk-avrf_resource_enumerate_callback)

[Resource Enumeration](https://learn.microsoft.com/windows/desktop/DevNotes/resource-enumeration)