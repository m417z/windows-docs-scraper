# AVRF_HANDLEOPERATION_ENUMERATE_CALLBACK callback function

## Description

Receives information related to the enumeration of handle traces.

## Parameters

### `HandleOperation`

A pointer to an [AVRF_HANDLE_OPERATION](https://learn.microsoft.com/windows/desktop/api/avrfsdk/ns-avrfsdk-avrf_handle_operation) structure containing information related to the enumeration of handle traces.

### `EnumerationContext`

A pointer to a user-defined information related to the context of the enumeration that is passed in when the [VerifierEnumerateResource](https://learn.microsoft.com/windows/desktop/api/avrfsdk/nf-avrfsdk-verifierenumerateresource) function is invoked.

### `EnumerationLevel`

A pointer to a value that informs the [VerifierEnumerateResource](https://learn.microsoft.com/windows/desktop/api/avrfsdk/nf-avrfsdk-verifierenumerateresource) function to either continue or stop the enumeration operation. These values are defined in the [eHeapEnumerationLevel](https://learn.microsoft.com/windows/desktop/api/avrfsdk/ne-avrfsdk-eheapenumerationlevel) enum.

## Return value

This function returns error codes or other values defined by the application.

## See also

[Resource Enumeration](https://learn.microsoft.com/windows/desktop/DevNotes/resource-enumeration)