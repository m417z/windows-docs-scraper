# SIO\_QUERY\_WFP\_CONNECTION\_REDIRECT\_CONTEXT control code

The **SIO\_QUERY\_WFP\_CONNECTION\_REDIRECT\_CONTEXT** socket I/O control operation allows a Winsock client to retrieve the redirect context for a redirect record for a redirected connection.

A WFP redirect record is a buffer of opaque data that WFP must set on an outbound proxy connection so that the redirected connection and the original connection are logically related.

**Note** The [**SIO\_QUERY\_WFP\_CONNECTION\_REDIRECT\_RECORDS**](https://learn.microsoft.com/windows-hardware/drivers/network/sio-query-wfp-connection-redirect-records) query can only be used if the connection was redirected at the **FWPS\_LAYER\_ALE\_CONNECT\_REDIRECT\_V4** or **FWPS\_LAYER\_ALE\_CONNECT\_REDIRECT\_V6** layer by a WFP client.

For more information about redirection, see [Using Bind or Connect Redirection](https://learn.microsoft.com/windows-hardware/drivers/network/using-bind-or-connect-redirection).

To query the redirect context for a redirect record, a Winsock client calls the [**WskControlSocket**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_control_socket) function with the following parameters.

| Parameter | Value |
| --- | --- |
| *RequestType* | **WskIoctl** |
| *ControlCode* | **SIO_QUERY_WFP_CONNECTION_REDIRECT_CONTEXT** |
| *Level* | 0 |
| *InputSize* | 0 |
| *InputBuffer* | NULL |
| *OutputSize* | The size, in bytes, of the buffer that is pointed to by the *OutputBuffer* parameter. |
| *OutputBuffer* | A pointer to the buffer that receives the redirect context for the redirect record for the accepted TCP connection. The size of the buffer is specified in the *OutputSize* parameter. |
| *OutputSizeReturned* | A pointer to a **ULONG**-typed variable that receives the number of bytes of data that is copied into the buffer that is pointed to by the *OutputBuffer* parameter. |
| Irp | A pointer to an IRP. |

The caller can perform this query in either of the following ways:

- It can set the *OutputBuffer* to a large buffer approximately 1 KB in size. If the output buffer size is not large enough, [**WskControlSocket**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_control_socket) will return **STATUS\_BUFFER\_TOO\_SMALL** and *OutputSizeReturned* will contain the required size of the buffer. A larger buffer can then be allocated and **WskControlSocket** called again with the **SIO\_QUERY\_WFP\_CONNECTION\_REDIRECT\_CONTEXT** request and *OutputBuffer* set to the larger buffer.
- Or it can set the *OutputSize* parameter to 0 and the *OutputBuffer* to NULL and then call [**WskControlSocket**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_control_socket). Upon completion, the **WskControlSocket** function retrieves the output buffer size, in bytes, in the *OutputSizeReturned* parameter. An appropriately sized buffer can then be allocated and **WskControlSocket** called again with the **SIO\_QUERY\_WFP\_CONNECTION\_REDIRECT\_CONTEXT** request and *OutputBuffer* set to the buffer.

**Note** It is also possible to perform this query in a user-mode application by using [**SIO\_QUERY\_WFP\_CONNECTION\_REDIRECT\_CONTEXT (SDK)**](https://learn.microsoft.com/windows/win32/winsock/sio-query-wfp-connection-redirect-context).

For this type of request, the Winsock client must specify a pointer to an IRP and a pointer to its completion routine. The IRP can be passed to the client by a higher driver or the client can choose to allocate the IRP. To specify the completion routine, the client must call [**IoSetCompletionRoutine**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iosetcompletionroutine). For more details, see [Using IRPs with Winsock Kernel Functions](https://learn.microsoft.com/windows-hardware/drivers/network/using-irps-with-winsock-kernel-functions).

The Winsock client must not free the allocated buffer till the IRP is completed by WSK subsystem. When the WSK subsystem completes the IRP, it notifies the client by invoking the completion routine. A reference to that buffer is passed to the client by the WSK subsystem in the *Context* parameter of the completion routine. The size of the buffer is stored in *Irp->IoStatus.Information*.

The client can get the status of the IRP by checking *Irp->IoStatus.Status*. *Irp->IoStatus.Status* will be set to **STATUS\_SUCCESS** if the request is successful. Otherwise, it will contain **STATUS\_INTEGER\_OVERFLOW**, **STATUS\_NOT\_FOUND**, **STATUS\_BUFFER\_TOO\_SMALL**, or **STATUS\_ACCESS\_DENIED** if the call is not successful.

## Requirements

|  |  |
| --- | --- |
| Minimum supported client | Windows 8 |
| Minimum supported server | Windows Server 2012 |
| Header | Mstcpip.h |
| IRQL | PASSIVE_LEVEL |

## See also

[Using Bind or Connect Redirection](https://learn.microsoft.com/windows-hardware/drivers/network/using-bind-or-connect-redirection)

[Using IRPs with Winsock Kernel Functions](https://learn.microsoft.com/windows-hardware/drivers/network/using-irps-with-winsock-kernel-functions)

[**SIO\_QUERY\_WFP\_CONNECTION\_REDIRECT\_RECORDS**](https://learn.microsoft.com/windows-hardware/drivers/network/sio-query-wfp-connection-redirect-records)

[**SIO\_QUERY\_WFP\_CONNECTION\_REDIRECT\_CONTEXT (SDK)**](https://learn.microsoft.com/windows/win32/winsock/sio-query-wfp-connection-redirect-context)

