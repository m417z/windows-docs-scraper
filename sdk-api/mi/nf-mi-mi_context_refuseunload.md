# MI_Context_RefuseUnload function

## Description

Tells the provider infrastructure not to unload the provider.

## Parameters

### `context` [in]

The request context.

## Return value

A value of the [MI_Result](https://learn.microsoft.com/windows/desktop/api/mi/ne-mi-mi_result) enumeration that specifies the function return code. This can be one of the following codes.

## Remarks

This function stops the WMI server from shutting down the provider. The provider needs to call the [MI_Context_RequestUnload](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_context_requestunload) function to allow the provider to be unloaded, and that function must use the same context that was used with the **MI_Context_RefuseUnload** function.

Some providers may use this mechanism to cache expensive data; however, holding a provider open a provider that is rarely touched becomes a performance issue in the long term. A provider that wants to maintain control of the lifetime of its provider should use a decoupled provider. If the provider wants to hold it open for a couple of minutes to maintain caches more efficiently, and if no new requests are received within that time, it should then request unload to shut down the provider and potentially host.

## See also

[MI_Context](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_context)

[MI_Context_RequestUnload](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_context_requestunload)