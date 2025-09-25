# PFN_WdsTransportClientSessionComplete callback function

## Description

The PFN_WdsTransportClientSessionCompete callback is used by the client to indicate that no more callbacks will be sent to the consumer and that the session either completed successfully or encountered a non-recoverable error.

## Parameters

### `hSessionKey` [in]

The handle belonging to the session that is being started.

### `pCallerData` [in]

Pointer to the caller specific data for this session. This data was specified in the call to [WdsTransportClientStartSession](https://learn.microsoft.com/windows/desktop/api/wdstci/nf-wdstci-wdstransportclientstartsession) function.

### `dwError` [in]

The overall status of the file transfer. If the session succeeded, this value will be set to **ERROR_SUCCESS**. If the session did not succeed, the error code for the session will be set.

## Remarks

This will be the last callback a consumer receives. The consumer will always receive this callback, even if the session is canceled.