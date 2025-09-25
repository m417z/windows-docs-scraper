# MI_Context_PostInstance function

## Description

Posts an instance back to the client (through the server) in response to a request.

## Parameters

### `context` [in]

Request context.

### `instance` [in]

Instance to be posted to the server.

## Return value

This function returns MI_INLINE MI_Result MI_INLINE_CALL.

## Remarks

There will be posting functions automatically generated for the indication class (for example, className_Post), and they should be called here.

The server is responsible for copying the instance so the provider is free to dispose of the instance afterwards using the [MI_Instance_Delete](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_instance_delete) function.

## See also

[MI_Context](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_context)

[MI_Instance](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_instance)

[MI_Instance_Delete](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_instance_delete)