# MI_Application_NewHostedProvider function

## Description

Registers a hosted provider with the WMI engine on the local machine.

## Parameters

### `application` [in]

A pointer to the handle returned from the
[MI_Application_Initialize](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_application_initializev1)
function.

### `namespaceName` [in]

A pointer to the namespace where the provider is registered. For example,
L"root/cimv2".

### `providerName` [in]

A pointer to the provider name that is registered with the WMI engine for this hosted provider.

### `mi_Main` [in]

Main entry point to an MI provider.

### `extendedError` [out, optional]

A pointer to a pointer to an optional parameter to receive extended error information in the event the API
fails. If a pointer is passed in, then an error instance may be returned. If an error instance is returned,
then, when you have finished using it, delete it by using the
[MI_Instance_Delete](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_instance_delete) function.

### `hostedProvider` [out]

A pointer to a returned hosted provider handle. When you have finished using the handle, close it by
calling the [MI_HostedProvider_Close](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_hostedprovider_close)
function during shutdown or when the provider no longer needs to receive operation requests.

## Return value

This function returns MI_INLINE MI_Result.

## Remarks

A hosted provider is one that resides in a client application rather than in the WMI service's host process.
The client controls the lifetime of these providers. Hosted providers are registered differently than regular
providers. This different registration indicates that the WMI service be hosted by the client. When you have
finished using the provider, the application should shut it down by calling the
[MI_HostedProvider_Close](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_hostedprovider_close) function.