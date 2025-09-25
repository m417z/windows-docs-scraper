# WdsTransportClientWaitForCompletion function

## Description

Blocks until either the multicast session is complete or the specified timeout is reached.

## Parameters

### `hSessionKey` [in]

Unique handle returned by the call to [WdsTransportClientInitializeSession](https://learn.microsoft.com/windows/desktop/api/wdstci/nf-wdstci-wdstransportclientinitializesession).

### `uTimeout` [in]

A timeout, in milliseconds.

## Return value

If the function succeeds, the return value is **ERROR_SUCCESS**.