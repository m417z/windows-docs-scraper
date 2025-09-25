# MI_OperationOptions_Clone function

## Description

Creates a copy of a [MI_OperationOptions](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_operationoptions) structure.

## Parameters

### `self` [in]

[MI_OperationOptions](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_operationoptions) structure to be cloned.

### `newOperationOptions` [out]

Returned [MI_OperationOptions](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_operationoptions) clone. When it is no longer needed, the clone needs to be deleted using the [MI_OperationOptions_Delete](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_operationoptions_delete) function.

## Return value

This function returns MI_INLINE MI_Result MI_INLINE_CALL.

## See also

[MI_OperationOptions_Delete](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_operationoptions_delete)