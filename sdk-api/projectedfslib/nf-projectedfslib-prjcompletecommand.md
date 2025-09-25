# PrjCompleteCommand function

## Description

Indicates that the provider has completed processing a callback from which it had previously returned HRESULT_FROM_WIN32(ERROR_IO_PENDING).

## Parameters

### `namespaceVirtualizationContext` [in]

Opaque handle for the virtualization instance. This must be the value from the VirtualizationInstanceHandle member of the callbackData passed to the provider in the callback that is being complete.

### `commandId` [in]

A value identifying the callback invocation that the provider is completing. This must be the value from the CommandId member of the callbackData passed to the provider in the callback that is being completed.

### `completionResult` [in]

The final HRESULT of the operation.

### `extendedParameters` [in, optional]

Optional pointer to extended parameters required for completing certain callbacks.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.