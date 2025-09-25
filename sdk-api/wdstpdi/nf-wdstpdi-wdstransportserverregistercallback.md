# WdsTransportServerRegisterCallback function

## Description

Registers a provider callback with the multicast server.

## Parameters

### `hProvider` [in]

Handle to the provider. This handle was given to the provider in the [WdsTransportProviderInitialize](https://learn.microsoft.com/windows/desktop/api/wdstpdi/nf-wdstpdi-wdstransportproviderinitialize) function.

### `CallbackId` [in]

The value of this parameter is a [TRANSPORTPROVIDER_CALLBACK_ID](https://learn.microsoft.com/windows/desktop/api/wdstpdi/ne-wdstpdi-transportprovider_callback_id) structure.

### `pfnCallback` [in]

Pointer to the function pointer associated with this id.

## Return value

If the function succeeds, the return is **S_OK**.