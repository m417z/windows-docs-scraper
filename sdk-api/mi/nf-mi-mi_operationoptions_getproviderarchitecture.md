# MI_OperationOptions_GetProviderArchitecture function

## Description

Gets the provider architecture for an operation.

## Parameters

### `options` [in]

[MI_OperationOptions](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_operationoptions) structure.

### `architecture` [out]

Returned MI_ProviderArchitecture value.

#### MI_PROVIDER_ARCHITECTURE_32BIT

32-bit architecture.

#### MI_PROVIDER_ARCHITECTURE_64BIT

64-bit architecture.

### `mustComply` [out]

Returned Boolean value where **MI_TRUE** means that if you are asking for a 32-bit provider on a 64-bit machine, then a 32-bit provider must be used.

## Return value

This function returns MI_INLINE MI_Result.