# CoWaitForMultipleObjects function

## Description

A replacement for [CoWaitForMultipleHandles](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cowaitformultiplehandles). This replacement API hides the options for **CoWaitForMultipleHandles** that are not supported in ASTA.

## Parameters

### `dwFlags` [in]

[CWMO_FLAGS](https://learn.microsoft.com/windows/desktop/api/combaseapi/ne-combaseapi-cwmo_flags) flag controlling whether call/window message reentrancy is enabled from this wait. By default, neither COM calls nor window messages are dispatched from **CoWaitForMultipleObjects** in ASTA.

### `dwTimeout` [in]

The timeout in milliseconds of the wait.

### `cHandles` [in]

The length of the *pHandles* array. Must be <= 56.

### `pHandles` [in]

An array of handles to waitable kernel objects.

### `lpdwindex` [out]

Receives the index of the handle that satisfied the wait.

## Return value

Same return values as [CoWaitForMultipleHandles](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cowaitformultiplehandles), except the ASTA-specific CO_E_NOTSUPPORTED cases instead return E_INVALIDARG from all apartment types.