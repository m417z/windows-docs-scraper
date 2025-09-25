# RpcServerUseAllProtseqsIf function

## Description

The
**RpcServerUseAllProtseqsIf** function tells the RPC run-time library to use all specified protocol sequences and endpoints in the interface specification for receiving remote procedure calls.

## Parameters

### `MaxCalls`

Backlog queue length for the [ncacn_ip_tcp](https://learn.microsoft.com/windows/desktop/Midl/ncacn-ip-tcp) protocol sequence. All other protocol sequences ignore this parameter. Use RPC_C_PROTSEQ_MAX_REQS_DEFAULT to specify the default value. See Remarks.

### `IfSpec`

Interface containing the protocol sequences and corresponding endpoint information to use in creating binding handles.

### `SecurityDescriptor`

Pointer to an optional parameter provided for the security subsystem. Used only for [ncacn_np](https://learn.microsoft.com/windows/desktop/Midl/ncacn-np) and [ncalrpc](https://learn.microsoft.com/windows/desktop/Midl/ncalrpc) protocol sequences. All other protocol sequences ignore this parameter. Using a security descriptor on the endpoint in order to make a server secure is not recommended. This parameter does not appear in the DCE specification for this API.

## Return value

| Value | Meaning |
| --- | --- |
| **RPC_S_OK** | The call succeeded. |
| **RPC_S_NO_PROTSEQS** | There are no supported protocol sequences. |
| **RPC_S_INVALID_ENDPOINT_FORMAT** | The endpoint format. |
| **RPC_S_OUT_OF_MEMORY** | The system is out of memory. |
| **RPC_S_DUPLICATE_ENDPOINT** | The endpoint is a duplicate. |
| **RPC_S_INVALID_SECURITY_DESC** | The security descriptor is invalid. |
| **RPC_S_INVALID_RPC_PROTSEQ** | RPC protocol sequence invalid. |

**Note** For a list of valid error codes, see
[RPC Return Values](https://learn.microsoft.com/windows/desktop/Rpc/rpc-return-values).

## Remarks

**Note** Listening on all supported protocol sequences is not recommended, because it causes the server to listen on all protocol sequences, including non-mainstream protocol sequences. It is recommended that servers listen on [mainstream](https://learn.microsoft.com/windows/desktop/Rpc/use-mainstream-protocol-sequences) protocol sequences only.

A server application calls
**RpcServerUseAllProtseqsIf** to register with the RPC run-time library all protocol sequences and associated endpoint address information provided in the IDL file. For a list of RPC-supported protocol sequences, see
[String Binding](https://learn.microsoft.com/windows/desktop/Rpc/string-binding).

To receive remote procedure call requests, a server must register at least one protocol sequence with the RPC run-time library. For each protocol sequence registered by a server, the RPC run-time library creates one or more endpoints through which the server receives remote procedure call requests. The RPC run-time library creates different endpoints for each protocol sequence.

**Note** Using the
**RpcServerUseAllProtseqsIf** function does not cause the server to listen on the following protocol sequences:

* [ncacn_nb_nb](https://learn.microsoft.com/windows/desktop/Midl/ncacn-nb-nb)
* [ncacn_nb_tcp](https://learn.microsoft.com/windows/desktop/Midl/ncacn-nb-tcp)
* [ncacn_nb_ipx](https://learn.microsoft.com/windows/desktop/Midl/ncacn-nb-ipx)
* [ncadg_mq](https://learn.microsoft.com/windows/desktop/Midl/ncadg-mq)
* [ncacn_at_dsp](https://learn.microsoft.com/windows/desktop/Midl/ncacn-at-dsp)
* [ncacn_http](https://msdn.microsoft.com/)

**Note** To listen on any of those protocol sequences, each sequence must be selected individually.

For *MaxCalls*, the value provided by the application is only a hint. The RPC run time or the Windows Sockets provider may override the value. For example, on Windows XP or Windows 2000 Professional, the value is limited to 5. Values greater than 5 are ignored and 5 is used instead. On Windows Server 2003 and Windows 2000 Server, the value will be honored.

Applications must be careful to pass reasonable values in *MaxCalls*. Large values on Server, Advanced Server, or Datacenter Server can cause a large amount of non-paged pool memory to be used. Using too small a value is also unfavorable, as it may result in TCP SYN packets being met by TCP RST from the server if the backlog queue gets exhausted. An application developer should balance memory footprint versus scalability requirements when determining the proper value for *MaxCalls*.

When the computer is configured to use selective binding, successful return does not guarantee that the server has created endpoints for all the network interfaces present on the computer. The RPC run-time may not listen on some network interfaces depending on the selective binding settings. In addition, if an interface has not yet received an IP address using DHCP, the RPC server does not listen on the network interface until a DHCP address is assigned to it. A successful return implies that the server is listening on at least one network interface; the full list of the binding handles over which remote procedure calls can be received can be obtained with a call to the [RpcServerInqBindings](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserverinqbindings) function.

For more information, see
[Server-Side Binding](https://learn.microsoft.com/windows/desktop/Rpc/server-side-binding). To register selected protocol sequences specified in the IDL file, a server calls
[RpcServerUseProtseqIf](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserveruseprotseqif).

## See also

[RpcBindingVectorFree](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcbindingvectorfree)

[RpcEpRegister](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcepregister)

[RpcEpRegisterNoReplace](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcepregisternoreplace)

[RpcNsBindingExport](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsbindingexporta)

[RpcServerInqBindings](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserverinqbindings)

[RpcServerListen](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserverlisten)

[RpcServerRegisterIf](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserverregisterif)

[RpcServerRegisterIfEx](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserverregisterifex)

[RpcServerUseAllProtseqs](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserveruseallprotseqs)

[RpcServerUseProtseq](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserveruseprotseq)

[RpcServerUseProtseqEp](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserveruseprotseqep)

[RpcServerUseProtseqIf](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserveruseprotseqif)