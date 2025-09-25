# WdsTransportClientStartSession function

## Description

Initiates a multicast file transfer.

## Parameters

### `hSessionKey` [in]

The handle returned by the [WdsTransportClientInitializeSession](https://learn.microsoft.com/windows/desktop/api/wdstci/nf-wdstci-wdstransportclientinitializesession) session.

## Return value

If the function succeeds, the return value is **ERROR_SUCCESS**.

## Remarks

All callbacks must be registered before this function is called. If a required callback is not registered, this function will fail.

It is possible for a session to start and complete before this function returns. This means that it is possible to receive a callback with a session handle that has not been seen yet. This also means that a session can start and error out before this function has a chance to complete. In this case, this function may still return success, even if the session itself fails.