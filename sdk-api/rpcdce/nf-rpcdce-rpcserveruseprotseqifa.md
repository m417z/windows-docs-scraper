# RpcServerUseProtseqIfA function

## Description

The
**RpcServerUseProtseqIf** function tells the RPC run-time library to use the specified protocol sequence combined with the endpoints in the interface specification for receiving remote procedure calls.

## Parameters

### `Protseq`

Pointer to a string identifier of the protocol sequence to register with the RPC run-time library.

### `MaxCalls`

Backlog queue length for the **ncacn_ip_tcp** protocol sequence. All other protocol sequences ignore this parameter. Use RPC_C_PROTSEQ_MAX_REQS_DEFAULT to specify the default value. See Remarks.

### `IfSpec`

Interface containing endpoint information to use in creating a binding for the protocol sequence specified in the *Protseq* parameter.

### `SecurityDescriptor`

Pointer to an optional parameter provided for the security subsystem. Used only for **ncacn_np** and **ncalrpc** protocol sequences. All other protocol sequences ignore this parameter. Using a security descriptor on the endpoint in order to make a server secure is not recommended. This parameter does not appear in the DCE specification for this API.

## Return value

| Value | Meaning |
| --- | --- |
| **RPC_S_OK** | The call succeeded. |
| **RPC_S_PROTSEQ_NOT_FOUND** | The endpoint for this protocol sequence is not specified in the IDL file. |
| **RPC_S_PROTSEQ_NOT_SUPPORTED** | The protocol sequence is not supported on this host. |
| **RPC_S_INVALID_RPC_PROTSEQ** | The protocol sequence is invalid. |
| **RPC_S_INVALID_ENDPOINT_FORMAT** | The endpoint format is invalid. |
| **RPC_S_OUT_OF_MEMORY** | The system is out of memory. |
| **RPC_S_INVALID_SECURITY_DESC** | The security descriptor is invalid. |

**Note** For a list of valid error codes, see
[RPC Return Values](https://learn.microsoft.com/windows/desktop/Rpc/rpc-return-values).

## Remarks

A server application calls
**RpcServerUseProtseqIf** to register one protocol sequence with the RPC run-time library. With each protocol-sequence registration, the routine includes the endpoint-address information provided in the IDL file.

To receive remote procedure call requests, a server must register at least one protocol sequence with the RPC run-time library. A server application can call this function multiple times to register additional protocol sequences.

For each protocol sequence registered by a server, the RPC run-time library creates one or more endpoints through which the server receives remote procedure call requests. The RPC run-time library creates different endpoints for each protocol sequence. However, each interface in the process is accessible through any endpoint. For more information, see Writing a Secure RPC Client or Server.

For *MaxCalls*, the value provided by the application is only a hint. The RPC run time or the Windows Sockets provider may override the value. For example, on Windows XP or Windows 2000 Professional, the value is limited to 5. Values greater than 5 are ignored and 5 is used instead. On Windows Server 2003 and Windows 2000 Server, the value will be honored.

Applications must be careful to pass reasonable values in *MaxCalls*. Large values on Server, Advanced Server, or Datacenter Server can cause a large amount of non-paged pool memory to be used. Using too small a value is also unfavorable, as it may result in TCP SYN packets being met by TCP RST from the server if the backlog queue gets exhausted. An application developer should balance memory footprint versus scalability requirements when determining the proper value for *MaxCalls*.

When the computer is configured to use selective binding, successful return does not guarantee that the server has created endpoints for all the network interfaces present on the computer. The RPC run-time may not listen on some network interfaces depending on the selective binding settings. In addition, if an interface has not yet received an IP address using DHCP, the RPC server does not listen on the network interface until a DHCP address is assigned to it. A successful return implies that the server is listening on at least one network interface; the full list of the binding handles over which remote procedure calls can be received can be obtained with a call to the RpcServerInqBindings function.

For more information, see
[Server-Side Binding](https://learn.microsoft.com/windows/desktop/Rpc/server-side-binding). For a list of Microsoft RPC supported protocol sequences, see
[String Binding](https://learn.microsoft.com/windows/desktop/Rpc/string-binding). To register all protocol sequences from the IDL file, a server calls
[RpcServerUseAllProtseqsIf](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserveruseallprotseqsif).

**Note** The Microsoft RPC implementation of
**RpcServerUseProtseqIf** includes a new, additional parameter, *SecurityDescriptor*, that does not appear in the DCE specification.

> [!NOTE]
> The rpcdce.h header defines RpcServerUseProtseqIf as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[RpcBindingVectorFree](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcbindingvectorfree)

[RpcEpRegister](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcepregister)

[RpcEpRegisterNoReplace](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcepregisternoreplace)

[RpcNsBindingExport](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsbindingexporta)

[RpcServerInqBindings](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserverinqbindings)

[RpcServerListen](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserverlisten)

[RpcServerRegisterIf](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserverregisterif)

[RpcServerUseAllProtseqs](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserveruseallprotseqs)

[RpcServerUseAllProtseqsIf](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserveruseallprotseqsif)

[RpcServerUseProtseq](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserveruseprotseq)

[RpcServerUseProtseqEp](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserveruseprotseqep)

Writing a Secure RPC Client or Server