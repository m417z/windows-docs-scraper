# WdsTransportClientInitializeSession function

## Description

Initiates a multicast file transfer.

## Parameters

### `pSessionRequest` [in]

Pointer to a [WDS_TRANSPORTCLIENT_REQUEST](https://learn.microsoft.com/windows/desktop/api/wdstci/ns-wdstci-wds_transportclient_request) structure that contains all the details required to initiate the multicast session. The format of this structure is described below.

### `pCallerData` [in]

User supplied pointer that will be provided with every callback for this session.

### `hSessionKey` [out]

Buffer that will receive the address of a handle that the consumer can use to uniquely identify this session to the client.

## Return value

If the function succeeds, the return value is **ERROR_SUCCESS**.

## Remarks

This function only sets up the session, it does not start the transfer. To start the transfer, call [WdsTransportClientStartSession](https://learn.microsoft.com/windows/desktop/api/wdstci/nf-wdstci-wdstransportclientstartsession).