# MI_Context_RequestUnload function

## Description

Requests to unload the module or the provider.

## Parameters

### `context` [in]

The request context.

## Return value

A value of the [MI_Result](https://learn.microsoft.com/windows/desktop/api/mi/ne-mi-mi_result) enumeration that specifies the function return code. This can be one of the following codes.

## Remarks

This function undoes a call to the [MI_Context_RefuseUnload](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_context_refuseunload) function. It must use the same context that was used in that function.

## See also

[MI_Context](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_context)

[MI_Context_RefuseUnload](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_context_refuseunload)