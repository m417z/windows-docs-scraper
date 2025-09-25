# MI_Context_PostResult function

## Description

Posts the final terminating result code back to the client (through the server) in response to a request.

## Parameters

### `context` [in]

Request context.

### `result`

Result code to post to the server.

## Return value

This function returns MI_INLINE MI_Result MI_INLINE_CALL.

## Remarks

All calls to the [MI_Context_PostIndication](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_context_postindication) and [MI_Context_PostInstance](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_context_postinstance) functions must be complete before calling this function. When this function is called, the lifetime of the request context is terminated; the context becomes invalid, and no additional calls can be made on the context.

## See also

[MI_Context](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_context)

[MI_Context_PostIndication](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_context_postindication)

[MI_Context_PostInstance](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_context_postinstance)