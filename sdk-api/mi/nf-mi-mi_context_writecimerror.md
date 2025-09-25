# MI_Context_WriteCimError function

## Description

Sends a CIM (informative) error instance to the client.

## Parameters

### `context` [in]

Request context.

### `error` [in]

An instance of a [CIM_Error](https://learn.microsoft.com/windows/desktop/hyperv_v2/cim-error) class.

### `flag` [out]

**MI_TRUE** on return if the provider should continue execution. Otherwise, **MI_FALSE**.

## Return value

A value of the [MI_Result](https://learn.microsoft.com/windows/desktop/api/mi/ne-mi-mi_result) enumeration that specifies the function return code. This can be one of the following codes.

## Remarks

A provider calls this function to send a CIM error instance to the client. This does not cancel the operation. Rather, this indicates the error to the client and gives the client the opportunity to determine if the operation should be continued or cancelled. It is then up to the provider to react accordingly.

## See also

[CIM_Error](https://learn.microsoft.com/windows/desktop/hyperv_v2/cim-error)

[MI_Context](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_context)

[MI_Context_PostCimError](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_context_postcimerror)

[MI_Instance](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_instance)