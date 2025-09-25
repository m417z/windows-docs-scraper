# MI_Context_PostCimError function

## Description

Posts a return code and an error message (in the form of a [CIM_Error](https://learn.microsoft.com/windows/desktop/hyperv_v2/cim-error) object) to the server in response to a request.

## Parameters

### `context` [in]

A pointer to the request context.

### `error` [in]

A pointer to a [CIM_Error](https://learn.microsoft.com/windows/desktop/hyperv_v2/cim-error) object to be posted to the server.

## Return value

This function returns MI_INLINE MI_Result MI_INLINE_CALL.

## Remarks

The [CIM_Error](https://learn.microsoft.com/windows/desktop/hyperv_v2/cim-error) instance that is returned in the *error* parameter can be compiled into your provider so you can initialize and then post it. Once an error has been posted, the context must not be used, as it becomes invalid at this point.

## See also

[CIM_Error](https://learn.microsoft.com/windows/desktop/hyperv_v2/cim-error)

[MI_Context](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_context)

[MI_Context_WriteCimError](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_context_writecimerror)

[MI_Instance](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_instance)