# MI_Context_Canceled function

## Description

Determines whether the operation has been canceled. This function is reserved; instead, use the [MI_Context_RegisterCancel](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_context_registercancel) function.

## Parameters

### `context` [in]

A pointer to the request context that was passed to the provider method.

### `flag` [out]

A pointer to a flag that holds the deletion result. Upon return, this flag will be **MI_TRUE** if the operation has been successfully canceled;
otherwise, it will be **MI_FALSE**.

## Return value

This function returns MI_INLINE MI_Result MI_INLINE_CALL.

## Remarks

A canceled operation on the client does not always signal to the server that the operation should be canceled. It depends on both the type of operation and the support from the underlying protocol handler.