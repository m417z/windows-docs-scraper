# RPC_ENDPOINT_TEMPLATE structure

## Description

The **RPC_ENDPOINT_TEMPLATE** structure specifies the properties of an RPC interface group server endpoint, including protocol sequence and name.

## Members

### `Version`

This field is reserved and must be set to 0.

### `ProtSeq`

Pointer to a string identifier of the protocol sequence to register with the RPC run-time library. Only [ncalrpc](https://learn.microsoft.com/windows/desktop/Rpc/protocol-sequence-constants), ncacn_ip_tcp, and ncacn_np are supported. This value must not be **NULL**.

### `Endpoint`

Optional pointer to the endpoint-address information to use in creating a binding for the protocol sequence specified in the *Protseq* parameter. Specify **NULL** to use dynamic endpoints.

### `SecurityDescriptor`

Pointer to an optional parameter provided for the security subsystem. Used only for [ncacn_np](https://learn.microsoft.com/windows/desktop/Rpc/protocol-sequence-constants) and ncalrpc protocol sequences. All other protocol sequences ignore this parameter. Using a security descriptor on the endpoint in order to make a server secure is not recommended.

### `Backlog`

Backlog queue length for the [ncacn_ip_tcp](https://learn.microsoft.com/windows/desktop/Rpc/protocol-sequence-constants) protocol sequence. All other protocol sequences ignore this parameter. Use **RPC_C_PROTSEQ_MAX_REQS_DEFAULT** to specify the default value. See Remarks for more information.

## Remarks

The value provided in *Backlog* by applications is only a hint. The RPC run time or the Windows Sockets provider may override the value. For example, on Windows XP or Windows 2000 Professional, the value is limited to 5. Values greater than 5 are ignored and 5 is used instead. On Windows Server 2003 and Windows 2000 Server, the value will be honored.

Applications must be careful to pass reasonable values in *Backlog*. Large values on Server, Advanced Server, or Datacenter Server can cause a large amount of non-paged pool memory to be used. Using too small a value is also unfavorable, as it may result in TCP SYN packets being met by TCP RST from the server if the backlog queue gets exhausted.

An application developer should balance memory footprint versus scalability requirements when determining the proper value for *Backlog*.

## See also

[RpcServerInqBindings](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserverinterfacegroupinqbindings)