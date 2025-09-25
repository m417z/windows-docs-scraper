# RxCeSend function

## Description

**RxCeSend** sends a transport service data unit (TSDU) along the specified connection on a virtual circuit.

## Parameters

### `pVc` [in]

A pointer to the virtual circuit along which the TSDU is to be sent.

### `SendOptions` [in]

The desired options for transmitting the data on this send operation by the transport. Note that this is only a request sent to the transport. The transport may only support a limited number of the options specified and ignore options not supported. The *SendOptions* parameter consists of a set of bits defined in *rxce.h*. The *SendOptions* parameter can be a combination of the following bits:

#### RXCE_SEND_EXPEDITED

The given data should be sent ahead of any normal send requests the transport is currently holding queued for transmission on this endpoint-to-endpoint connection. If the transport does not support expedited transfers, it can ignore this flag. Note that RXCE_SEND_EXPEDITED is equivalent to the TDI TDI_SEND_EXPEDITED flag.

#### RXCE_SEND_NO_RESPONSE_EXPECTED

The caller is giving a hint to the underlying transport that it does not expect a response to this send from its remote-node peer. This flag should disable piggybacking of the TSDU acknowledgment by the remote-node transport. Note that RXCE_SEND_NO_RESPONSE_EXPECTED is equivalent to the TDI_SEND_NO_RESPONSE_EXPECTED flag.

#### RXCE_SEND_NON_BLOCKING

If the underlying transport currently has no internal buffer space available for the given data, it should just complete the IRP with STATUS_DEVICE_NOT_READY. If the transport has some buffer space available, it should copy as much data as it can from the client-supplied buffer, set the **IoStatus.Information** member to the number of bytes it copied, and complete the IRP with STATUS_SUCCESS.

This flag is irrelevant to transports that do not buffer sends internally. Note that RXCE_SEND_NON_BLOCKING is equivalent to the TDI_SEND_NON_BLOCKING flag.

#### RXCE_SEND_PARTIAL

Signifies if an RX_MEM_DESC(MDL) is to be sent in its entirety, or if only portions of it need to be sent. This option requests that the transport allow the send operation to transmit part of the data if the transport and MDL allow this behavior.

#### RXCE_SEND_SYNCHRONOUS

Signifies if the send operation is to transmit the data synchronously. When this option is set, the request is submitted to the underlying transport and control does not return to the caller until the request completes. Note that the *pCompletionContext* parameter is ignored when this bit is set.

### `pMdl` [in]

A pointer to the buffer to be sent.

### `SendLength` [in]

The length of data to be sent.

### `pCompletionContext` [in]

The context passed back to the caller during **SendCompletion** for asynchronous operations. Not that this parameter is ignored if the *SendOptions* parameter requests a synchronous send operation.

## Return value

**RxCeSend** returns STATUS_SUCCESS on success or one of the following error codes on failure:

| Return code | Description |
| --- | --- |
| **STATUS_CONNECTION_DISCONNECTED** | An invalid or disconnected virtual circuit or connection was specified |
| **STATUS_INSUFFICIENT_RESOURCES** | The allocation of nonpaged pool memory needed by this routine failed. |
| **STATUS_INVALID_PARAMETER** | An invalid length was passed in the *SendLength* parameter based on the *SendOptions* specified. |

## Remarks

The **RxCeSend** routine will allocate the IRP, build the send request for the underlying transport driver, and submit the request to TDI. In the case of synchronous send operations, this routine will also the free IRP and resources allocated when the routine completes.

The asynchronous and synchronous options indicated in the *SendOptions* parameter used in **RxCeSend** distinguish between two situations. In the asynchronous case, control returns to the caller once the request has been successfully submitted to the underlying transport. The results for any given request are communicated back using the **SendCompletion** callback routine. The *pCompletionContext* parameter in **RxCeSend** is passed back in the callback routine to assist the caller in disambiguating the requests.

In the synchronous case, the request is submitted to the underlying transport and the control does not return to the caller till the request completes. Note that in the synchronous case, the *pCompletionContext* parameter is ignored and the status that is returned corresponds to the completion status of the operations.

The benefit of asynchronous and synchronous options depends on the underlying transport. In a virtual circuit environment (TCP, for example), a synchronous option implies that the control does not return until the data reaches the server. On the other hand for datagram oriented transports (UDP, for example), there is very little difference between the two options.

## See also

[MDL](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_mdl)

[RxCeSendDatagram](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxce/nf-rxce-rxcesenddatagram)