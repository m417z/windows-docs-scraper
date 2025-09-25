# RxCeSendDatagram function

## Description

**RxCeSendDatagram** sends a transport service data unit (TSDU) along the specified connection on a virtual circuit.

## Parameters

### `hAddress`

A pointer to the transport along which the TSDU is to be sent.

### `pConnectionInformation` [in]

A pointer to connection information that contains the remote address.

### `SendOptions`

A pointer to connection information that contains the remote address.

### `pMdl` [in]

A pointer to the buffer to be sent.

### `SendLength` [in]

The length of data to be sent.

### `pCompletionContext` [in]

The context passed back to the caller during **SendCompletion** for asynchronous operations. Not that this parameter is ignored if the *Options* parameter requests a synchronous send operation.

## Return value

**RxCeSendDatagram** returns STATUS_SUCCESS on success or one of the following error codes on failure:

| Return code | Description |
| --- | --- |
| **STATUS_INSUFFICIENT_RESOURCES** | The allocation of nonpaged pool memory needed by this routine failed. |
| **STATUS_INVALID_PARAMETER** | An invalid length was passed in the *SendLength* parameter based on the *Options* specified. |

## Remarks

The asynchronous and synchronous options indicated in the *Options* parameter used in **RxCeSendDatagram** distinguish between two situations. In the asynchronous case, control returns to the caller once the request has been successfully submitted to the underlying transport. The results for any given request are communicated back using the **SendCompletion** callback routine. The *pCompletionContext* parameter in **RxCeSendDatagram** is passed back in the callback routine to assist the caller in disambiguating the requests.

In the synchronous case, the request is submitted to the underlying transport and the control does not return to the caller till the request completes. Note that in the synchronous case, the *pCompletionContext* parameter is ignored and the status that is returned corresponds to the completion status of the operations.

The benefit of asynchronous and synchronous options depends on the underlying transport. In a virtual circuit environment (TCP, for example), a synchronous option implies that the control does not return until the data reaches the server. On the other hand for datagram oriented transports (UDP, for example), there is very little difference between the two options.

Note that the synchronous *Option* is disregarded for sending datagrams because the underlying transports do not block on datagram sends.

**RXCE_CONNECTION_INFORMATION** is a typedef for a **TDI_CONNECTION_INFORMATION** structure.

## See also

[MDL](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_mdl)

[RxCeSend](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxce/nf-rxce-rxcesend)

[TDI_CONNECTION_INFORMATION](https://learn.microsoft.com/previous-versions/windows/hardware/network/ff565085(v=vs.85))