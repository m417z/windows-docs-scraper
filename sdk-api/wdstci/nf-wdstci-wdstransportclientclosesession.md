# WdsTransportClientCloseSession function

## Description

Releases the resources associated with a session in the client.

## Parameters

### `hSessionKey` [in]

Unique handle returned by the call to [WdsTransportClientInitializeSession](https://learn.microsoft.com/windows/desktop/api/wdstci/nf-wdstci-wdstransportclientinitializesession). After this handle has been used with the **WdsTransportClientCloseSession**, it cannot be used again with the [WdsTransportClientCancelSession](https://learn.microsoft.com/windows/desktop/api/wdstci/nf-wdstci-wdstransportclientcancelsession) function.

## Return value

If the function succeeds, the return value is **ERROR_SUCCESS**.

## Remarks

This function does not cancel the session and callbacks can be received until session completes.