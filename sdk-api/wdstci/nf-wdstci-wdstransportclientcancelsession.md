# WdsTransportClientCancelSession function

## Description

Releases the resources associated with a session in the client.

## Parameters

### `hSessionKey` [in]

Unique handle returned by the call to [WdsTransportClientInitializeSession](https://learn.microsoft.com/windows/desktop/api/wdstci/nf-wdstci-wdstransportclientinitializesession). This session will eventually complete with an error code of **ERROR_CANCELLED** to the callback [PFN_WdsTransportClientSessionComplete](https://learn.microsoft.com/windows/desktop/api/wdstci/nc-wdstci-pfn_wdstransportclientsessioncomplete) callback.

## Return value

If the function succeeds, the return value is **ERROR_SUCCESS**.

## Remarks

It is safe to call this function from within a callback.