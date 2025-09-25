# RPC_POLICY structure

## Description

The
**RPC_POLICY** structure contains flags that determine binding on multihomed computers, and port allocations when using the
[ncacn_ip_tcp](https://learn.microsoft.com/windows/desktop/Midl/ncacn-ip-tcp) and
[ncadg_ip_udp](https://learn.microsoft.com/windows/desktop/Midl/ncadg-ip-udp) protocols.

## Members

### `Length`

Size of the
**RPC_POLICY** structure, in bytes. The **Length** member allows compatibility with future versions of this structure, which may contain additional fields. Always set the **Length** equal to **sizeof**(RPC_POLICY) when you initialize the
**RPC_POLICY** structure in your code.

### `EndpointFlags`

Set of flags that determine the attributes of the port or ports where the server receives remote procedure calls. You can specify more than one flag (by using the bitwise OR operator) from the set of values for a given protocol sequence. The following table lists the possible values for the **EndpointFlags** member.

| Value | Meaning |
| --- | --- |
| **0** | Specifies the system default. |
| **RPC_C_USE_INTERNET_PORT** | Allocates the endpoint from one of the ports defined in the registry as "Internet Available." Valid only with [ncacn_ip_tcp](https://learn.microsoft.com/windows/desktop/Midl/ncacn-ip-tcp) and [ncadg_ip_udp](https://learn.microsoft.com/windows/desktop/Midl/ncadg-ip-udp) protocol sequences. |
| **RPC_C_USE_INTRANET_PORT** | Allocates the endpoint from one of the ports defined in the registry as "Intranet Available." Valid only with [ncacn_ip_tcp](https://learn.microsoft.com/windows/desktop/Midl/ncacn-ip-tcp) and [ncadg_ip_udp](https://learn.microsoft.com/windows/desktop/Midl/ncadg-ip-udp) protocol sequences. |
| **RPC_C_MQ_TEMPORARY** | The server process–receive queue will be deleted automatically when the RPC server exits. Any outstanding calls still in the queue will be lost. This is the default. Valid only with the [ncadg_mq](https://learn.microsoft.com/windows/desktop/Midl/ncadg-mq) protocol sequence. |
| **RPC_C_MQ_PERMANENT** | Specifies that the server process–receive queue persists after the server process exits. The default is that the queue is deleted when the server process terminates. Valid only with ncadg_mq protocol sequence. |
| **RPC_C_MQ_CLEAR_ON_OPEN** | If the receive queue already exists because it was opened previously as a permanent queue, then clear any outstanding calls waiting in the queue. Valid only with the ncadg_mq protocol sequence only. |
| **RPC_C_MQ_USE_EXISTING_SECURITY** | If the receive queue already exists, then do not modify its existing settings for authentication or encryption. Valid only with the ncadg_mq protocol sequence. |
| **RPC_C_MQ_AUTHENTICATE** | The server process–receive queue accepts only authenticated calls from clients. The default is that both authenticated and unauthenticated calls are accepted. Valid only with ncadg_mq protocol sequence. |
| **RPC_C_MQ_ENCRYPT** | Calls to server are encrypted. The default is that both encrypted and unencrypted calls are accepted. Valid only with ncadg_mq protocol sequence. |
| **RPC_C_MQ_AUTHN_LEVEL_NONE** | The server's receive queue accepts all calls from clients. This is the default authentication level. Valid only with the [ncadg_mq](https://learn.microsoft.com/windows/desktop/Midl/ncadg-mq) protocol. |
| **RPC_C_MQ_AUTHN_LEVEL_PKT_INTEGRITY** | Sets the server's receive queue to only accept client calls that have authentication level RPC_C_AUTHN_LEVEL_PKT_INTEGRITY or RPC_C_AUTHN_LEVEL_PKT_PRIVACY. Valid only with the ncadg_mq protocol sequence. |
| **RPC_C_MQ_AUTHN_LEVEL_PKT_PRIVACY** | Sets the server's receive queue to only accept client calls that have authentication level RPC_C_AUTHN_LEVEL_PKT_PRIVACY. Calls with a lower authentication level are ignored. Valid only with the ncadg_mq protocol sequence. |

**Note** If the registry does not contain any of the keys that specify the default policies, then the **EndpointFlags** member will have no effect at run time. If a key is missing or contains an invalid value, then the entire configuration for that protocol (
[ncacn_ip_tcp](https://learn.microsoft.com/windows/desktop/Midl/ncacn-ip-tcp),
[ncadg_ip_udp](https://learn.microsoft.com/windows/desktop/Midl/ncadg-ip-udp) or
[ncadg_mq](https://learn.microsoft.com/windows/desktop/Midl/ncadg-mq)) is marked as invalid and all calls to **RpcServerUseProtseq*** functions over that protocol will fail.

### `NICFlags`

Policy for binding to Network Interface Cards (NICs). The following table lists the possible values for the **NICFlags** member.

| Value | Meaning |
| --- | --- |
| **0** | Binds to NICs on the basis of the registry settings. Always use this value when you are using the **RPC_POLICY** structure to define message-queue properties. |
| **RPC_C_BIND_TO_ALL_NICS** | Overrides the registry settings and binds to all NICs. If the Bind key is missing from the registry, then the **NICFlags** member will have no effect at run time. If the key contains an invalid value, then the entire configuration is marked as invalid and all calls to [RpcServerUseProtseq](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserveruseprotseq)* will fail. |

## Remarks

You can use the **RPC_Policy** structure to set policies for remote procedure calls at run time. These policies include:

* Message queuing: Allows the server to specify message-queuing properties, such as security, quality of delivery, and the lifetime of the server-process queue. This policy is only effective for remote calls over the message-queuing transport (ncadg_mq).
* Port allocation for dynamic ports: Specifies whether the endpoint registered by this application should go to the Internet-available or intranet-available port set.
* Selective binding: Allows multihomed machines to bind selectively to NICs.

**Note** Port allocation and selective binding policies are effective only for remote calls over TCP (
[ncacn_ip_tcp](https://learn.microsoft.com/windows/desktop/Midl/ncacn-ip-tcp)) and UDP (
[ncadg_ip_udp](https://learn.microsoft.com/windows/desktop/Midl/ncadg-ip-udp)) connections. For more information, see
[Configuring the Registry for Port Allocations and Selective Binding](https://learn.microsoft.com/windows/desktop/Rpc/configuring-the-windows-xp-2000-nt-registry-for-port-allocations-and-selective-binding).

## See also

[Configuring the Registry for Port Allocations and Selective Binding](https://learn.microsoft.com/windows/desktop/Rpc/configuring-the-windows-xp-2000-nt-registry-for-port-allocations-and-selective-binding)

[RPC Message Queuing](https://learn.microsoft.com/windows/desktop/Rpc/rpc-message-queuing)

[RpcServerUseAllProtseqsEx](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserveruseallprotseqsex)

[RpcServerUseAllProtseqsIfEx](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserveruseallprotseqsifex)

[RpcServerUseProtseqEpEx](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserveruseprotseqepex)

[RpcServerUseProtseqEx](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserveruseprotseqex)

[RpcServerUseProtseqIfEx](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserveruseprotseqifex)