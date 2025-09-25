# MI_Context_PostIndication function

## Description

Posts an indication result to the server in response to a subscribe operation request.

## Parameters

### `context` [in]

Request context.

### `indication` [in]

Indication instance to be posted.

### `subscriptionIDCount`

Number of subscription identifiers.

### `bookmark`

An optional, null-terminated string that represents the bookmark for this subscription. In general, if a bookmark was supplied to the subscribe operation, and bookmarks are supported, a resume bookmark should be returned with every indication.

## Return value

This function returns MI_INLINE MI_Result MI_INLINE_CALL.

## Remarks

There will be posting functions automatically generated for the indication class (for example, className_Post).

The server is responsible for copying the instance so the provider is free to dispose of the instance afterwards using the [MI_Instance_Delete](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_instance_delete) function.

## See also

[MI_Context](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_context)

[MI_Instance](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_instance)

[MI_Instance_Delete](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_instance_delete)