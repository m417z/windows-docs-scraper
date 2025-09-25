# MI_OperationOptions_SetProviderArchitecture function

## Description

Sets the provider architecture for an operation.

## Parameters

### `options` [in, out]

A pointer to a [MI_OperationOptions](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_operationoptions) structure.

### `architecture` [in]

One of the following [MI_ProviderArchitecture](https://learn.microsoft.com/windows/desktop/api/mi/ne-mi-mi_providerarchitecture) values.

#### MI_PROVIDER_ARCHITECTURE_32BIT (0)

32-bit architecture.

#### MI_PROVIDER_ARCHITECTURE_64BIT (1)

64-bit architecture.

### `mustComply` [in]

Boolean value where **MI_TRUE** means that if you are asking for a 32-bit provider on a 64-bit machine, then a 32-bit provider must be used. **MI_FALSE** means that a 64-bit provider can be used if a 32-bit provider is not available.

## Return value

This function returns MI_INLINE MI_Result.