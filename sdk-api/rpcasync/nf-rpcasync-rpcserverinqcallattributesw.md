# RpcServerInqCallAttributesW function

## Description

The
**RpcServerInqCallAttributes** function is an RPC server call that obtains client security context attributes.

## Parameters

### `ClientBinding` [in]

Optional. For explicit binding within a server routine, *ClientBinding* is the binding handle with which the manager routine was called. See Remarks.

### `RpcCallAttributes` [in, out]

[RPC_CALL_ATTRIBUTES_V2](https://learn.microsoft.com/windows/desktop/api/rpcasync/ns-rpcasync-rpc_call_attributes_v2_a) structure that receives call attributes.

## Return value

Returns RPC_S_OK upon success, and *RpcCallAttributes* is filled. If ERROR_MORE_DATA is returned, one or more fields in *RpcCallAttributes* was of insufficient length and could not be filled. See Remarks in
[RPC_CALL_ATTRIBUTES_V2](https://learn.microsoft.com/windows/desktop/api/rpcasync/ns-rpcasync-rpc_call_attributes_v2_a) for details on handling ERROR_MORE_DATA.

Upon failure, the contents of *RpcCallAttributes* is undefined and may be partially modified by RPC.

**Note** For a list of valid error codes, see
[RPC Return Values](https://learn.microsoft.com/windows/desktop/Rpc/rpc-return-values).

## Remarks

The
**RpcServerInqCallAttributes** function uses a versioning scheme to incorporate new capabilities without having to introduce new functions with suffix identifiers. For example, a second version of the
[RPC_CALL_ATTRIBUTES_V2](https://learn.microsoft.com/windows/desktop/api/rpcasync/ns-rpcasync-rpc_call_attributes_v2_a), identified with a simple #define in the header, can add new members to facilitate new functionality built into future versions of the
**RpcServerInqCallAttributes** function, without having to release a function called RpcServerInqCallAttributesEx.

If the
**RpcServerInqCallAttributes** function is called outside a server routine, and if the function call queries the security context attributes for an asynchronous RPC call, *ClientBinding* can be retrieved by calling the
[RpcAsyncGetCallHandle](https://learn.microsoft.com/windows/desktop/api/rpcasync/nf-rpcasync-rpcasyncgetcallhandle) function from the asynchronous handle.

The
**RpcServerInqCallAttributes** function is not supported for datagram protocol sequences, such as ncadg_*. If invoked on a call that executes on a datagram protocol sequence, RPC_S_CANNOT_SUPPORT is returned.

The
**RpcServerInqCallAttributes** function is thread-safe.

#### Examples

```cpp
RPC_CALL_ATTRIBUTES CallAttributes;  // this maps to RPC_CALL_ATTRIBUTES_V1

memset(&CallAttributes, 0, sizeof(CallAttributes));
CallAttributes.Version = RPC_CALL_ATTRIBUTES_VERSION;    // maps to 1
CallAttributes.Flags = ;//....
Status = RpcServerInqCallAttributes(0, &ClientContextAttributes);

```

> [!NOTE]
> The rpcasync.h header defines RpcServerInqCallAttributes as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[RPC_CALL_ATTRIBUTES_V2](https://learn.microsoft.com/windows/desktop/api/rpcasync/ns-rpcasync-rpc_call_attributes_v2_a)

[RpcAsyncGetCallHandle](https://learn.microsoft.com/windows/desktop/api/rpcasync/nf-rpcasync-rpcasyncgetcallhandle)