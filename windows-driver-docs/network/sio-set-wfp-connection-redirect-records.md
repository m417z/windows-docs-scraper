# SIO\_SET\_WFP\_CONNECTION\_REDIRECT\_RECORDS control code

The **SIO\_SET\_WFP\_CONNECTION\_REDIRECT\_RECORDS** socket I/O control operation allows a Winsock client to specify the redirect record to the new TCP socket used for connecting to the final destination.

A WFP redirect record is a buffer of opaque data that WFP must set on an outbound proxy connection so that the redirected connection and the original connection are logically related.

For more information about redirection, see [Using Bind or Connect Redirection](https://learn.microsoft.com/windows-hardware/drivers/network/using-bind-or-connect-redirection).

To set the redirect record to the new TCP socket used for connecting to the final destination, a Winsock client calls the [**WskControlSocket**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_control_socket) function with the following parameters.

| Parameter | Value |
| --- | --- |
| *RequestType* | **WskIoctl** |
| *ControlCode* | **SIO_SET_WFP_CONNECTION_REDIRECT_RECORDS** |
| *Level* | 0 |
| *InputSize* | The size of the redirect record pointed to by the InputBuffer parameter. |
| *InputBuffer* | A pointer to the redirect record associated with the socket. |
| *OutputSize* | 0 |
| *OutputBuffer* | NULL |
| *OutputSizeReturned* | NULL |
| Irp | A pointer to an IRP. |

The Winsock client must allocate a buffer and specify a pointer to the buffer and its size in *InputBuffer* and *InputSize.*

A Winsock client must specify a pointer to an IRP and a completion routine when calling the [**WskControlSocket**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wsk/nc-wsk-pfn_wsk_control_socket) function for this type of request. The client must not release the buffer till the WSK subsystem has completed the IRP. When it completes the IRP, the subsystem invokes the completion routine. In the completion routine, the client must check the IRP status and release all resources that it had previously allocated for the request.

**Note** It is also possible to perform this query in a user-mode application by using [**SIO\_SET\_WFP\_CONNECTION\_REDIRECT\_RECORDS (SDK)**](https://learn.microsoft.com/windows/win32/winsock/sio-set-wfp-connection-redirect-records).

For more information about WSK IRP handling, see [Using IRPs with Winsock Kernel Functions](https://learn.microsoft.com/windows-hardware/drivers/network/using-irps-with-winsock-kernel-functions).

The client can get the status of the IRP by checking *Irp->IoStatus.Status*. *Irp->IoStatus.Status* will be set to **STATUS\_SUCCESS** if the request is successful. Otherwise, it will contain **STATUS\_INTEGER\_OVERFLOW**, or **STATUS\_ACCESS\_DENIED** if the call is not successful.

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

[**SIO\_SET\_WFP\_CONNECTION\_REDIRECT\_RECORDS (SDK)**](https://learn.microsoft.com/windows/win32/winsock/sio-set-wfp-connection-redirect-records)

