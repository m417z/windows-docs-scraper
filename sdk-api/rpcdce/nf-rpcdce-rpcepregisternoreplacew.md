# RpcEpRegisterNoReplaceW function

## Description

The
**RpcEpRegisterNoReplace** function adds server-address information to the local endpoint-map database.

## Parameters

### `IfSpec`

Interface to register with the local endpoint-map database.

### `BindingVector`

Pointer to a vector of binding handles over which the server can receive remote procedure calls.

### `UuidVector`

Pointer to a vector of object UUIDs offered by the server. The server application constructs this vector.

A null parameter value indicates there are no object UUIDs to register.

### `Annotation`

Pointer to the character-string comment applied to each cross-product element added to the local endpoint-map database. The string can be up to 64 characters long, including the null-terminating character. Specify a null value or a null-terminated string ("\0") if there is no annotation string.

The annotation string is used by applications for information only. RPC does not use this string to determine which server instance a client communicates with or to enumerate elements in the endpoint-map database.

## Return value

| Value | Meaning |
| --- | --- |
| **RPC_S_OK** | The call succeeded. |
| **RPC_S_NO_BINDINGS** | No bindings. |
| **RPC_S_INVALID_BINDING** | The binding handle was invalid. |
| **RPC_S_WRONG_KIND_OF_BINDING** | This was the wrong kind of binding for the operation. |

**Note** For a list of valid error codes, see
[RPC Return Values](https://learn.microsoft.com/windows/desktop/Rpc/rpc-return-values).

## Remarks

The
**RpcEpRegisterNoReplace** function adds entries to the local host's endpoint-map database. This function does not replace existing database entries.

A server uses
**RpcEpRegisterNoReplace** rather than
[RpcEpRegister](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcepregister) when multiple instances of the server will run on the same host. In other words, use this function when more than one server instance will offer the same interface UUID, object UUID, and protocol sequence at any one time.

Because entries are not replaced when calling
**RpcEpRegisterNoReplace**, servers must unregister themselves before they stop running. Otherwise, stale data accumulates each time a server instance stops running without calling
[RpcEpUnregister](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcepunregister). Stale entries increase the likelihood that a client will receive endpoints to nonexistent servers. The client will spend time trying to communicate with a nonexistent server before obtaining another endpoint.

A server can use
[RpcEpRegister](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcepregister) and
**RpcEpRegisterNoReplace** to register entries in the endpoint mapper database. Previous to Windows 2000, two functions were available to enable a server to overwrite stale entries in the endpoint mapper database left from previous server instances that are no longer running. The endpoint mapper database automatically removes entries registered by a server instance as soon as the server stops functioning. However, servers are not allowed to replace the endpoint mapper entries of another server for security purposes. Therefore, **RpcEpRegister** and
**RpcEpRegisterNoReplace** perform largely the same functionality.

A server application calls
[RpcEpRegister](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcepregister) to register endpoints specified by calling any of the following functions:

* [RpcServerUseAllProtseqs](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserveruseallprotseqs)
* [RpcServerUseProtseq](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserveruseprotseq)
* [RpcServerUseProtseqEp](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserveruseprotseqep)
* [RpcServerUseAllProtseqsIf](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserveruseallprotseqsif)
* [RpcServerUseProtseqIf](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserveruseprotseqif)

If the server also exports to the name-service database, the server calls
[RpcEpRegister](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcepregister) with the same *IfSpec*, *BindingVector*, and *UuidVector* values used when calling the
[RpcNsBindingExport](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsbindingexporta) function.

If a protocol sequence is used without specifying an endpoint, the RPC run-time library automatically generates a dynamic endpoint. In this case, the server can call
[RpcServerInqBindings](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserverinqbindings) followed by
**RpcEpRegisterNoReplace** to make itself available to multiple clients. Otherwise, the automatically started server is known only to the client for which the server was started.

Each element added to the endpoint-map database logically contains the following:

* Interface UUID
* Interface version (major and minor)
* Binding handle
* Object UUID (optional)
* Annotation (optional)

**RpcEpRegisterNoReplace** creates a cross-product from the *IfSpec*, *BindingVector*, and *UuidVector* parameters and adds each element in the cross-product as a separate registration in the endpoint-map database.

> [!NOTE]
> The rpcdce.h header defines RpcEpRegisterNoReplace as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[RpcBindingFromStringBinding](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcbindingfromstringbinding)

[RpcEpRegister](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcepregister)

[RpcEpUnregister](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcepunregister)

[RpcNsBindingExport](https://learn.microsoft.com/windows/desktop/api/rpcnsi/nf-rpcnsi-rpcnsbindingexporta)

[RpcServerInqBindings](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserverinqbindings)

[RpcServerUseAllProtseqs](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserveruseallprotseqs)

[RpcServerUseAllProtseqsIf](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserveruseallprotseqsif)

[RpcServerUseProtseq](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserveruseprotseq)

[RpcServerUseProtseqEp](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserveruseprotseqep)

[RpcServerUseProtseqIf](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcserveruseprotseqif)