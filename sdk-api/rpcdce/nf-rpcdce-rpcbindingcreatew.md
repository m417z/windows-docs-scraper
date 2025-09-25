# RpcBindingCreateW function

## Description

The **RpcBindingCreate** function creates a new fast RPC binding handle based on a supplied template.

## Parameters

### `Template` [in]

[RPC_BINDING_HANDLE_TEMPLATE](https://learn.microsoft.com/windows/desktop/api/rpcdce/ns-rpcdce-rpc_binding_handle_template_v1_a) structure that describes the binding handle to be created by this call. This data may be overwritten during the call, so the API does not maintain a reference to this data. The caller must free the memory used by this structure when the API returns.

### `Security` [in, optional]

[RPC_BINDING_HANDLE_SECURITY](https://learn.microsoft.com/windows/desktop/api/rpcdce/ns-rpcdce-rpc_binding_handle_security_v1_a) structure that describes the security options for this binding handle. This data may be overwritten during the call, so the API does not maintain a reference to this data. The caller must free the memory used by this structure when the API returns.

This parameter is optional. If this parameter is set to **NULL**, the default security settings for [RPC_BINDING_HANDLE_SECURITY](https://learn.microsoft.com/windows/desktop/api/rpcdce/ns-rpcdce-rpc_binding_handle_security_v1_a) will be used.

### `Options` [in, optional]

[RPC_BINDING_HANDLE_OPTIONS](https://learn.microsoft.com/windows/desktop/api/rpcdce/ns-rpcdce-rpc_binding_handle_options_v1) structure that describes additional options for the binding handle. This data may be overwritten during the call, so the API does not maintain a reference to this data. The caller must free the memory used by this structure when the API returns.

This parameter is optional. If this parameter is set to **NULL**, the default options for [RPC_BINDING_HANDLE_OPTIONS](https://learn.microsoft.com/windows/desktop/api/rpcdce/ns-rpcdce-rpc_binding_handle_options_v1) will be used.

### `Binding` [out]

[RPC_BINDING_HANDLE](https://learn.microsoft.com/windows/desktop/Rpc/rpc-binding-handle) structure that contains the newly-created binding handle. If this function did not return RPC_S_OK, then the contents of this structure are undefined. For non-local RPC calls, this handle must be passed to [RpcBindingBind](https://learn.microsoft.com/windows/desktop/api/rpcasync/nf-rpcasync-rpcbindingbind).

## Return value

This function returns RPC_S_OK on success; otherwise, an RPC_S_* error code is returned. For information on these error codes, see [RPC Return Values](https://learn.microsoft.com/windows/desktop/Rpc/rpc-return-values).

| Return code | Description |
| --- | --- |
| **RPC_S_OK** | The binding handle was successfully created. |
| **RPC_S_CANNOT_SUPPORT** | An obsolete feature of RPC was requested for this binding handle.<br><br>**Note** The only supported protocol sequences for this API is **ncalrpc**; choosing another protocol sequence results in the return of this error status code. |

**Note** For a list of valid error codes, see
[RPC Return Values](https://learn.microsoft.com/windows/desktop/Rpc/rpc-return-values).

## Remarks

The RPC binding handle returned by this API can be used with any other functions that accepts a binding handle as a parameter.

However, before any calls can be made on the binding handle, [RpcBindingBind](https://learn.microsoft.com/windows/desktop/api/rpcasync/nf-rpcasync-rpcbindingbind) must be called to make the binding handle available for remote calls. The **RpcBindingCreate** API does not touch the network or attempt to communicate with the RPC server -- rather, it simply builds an internal data structure based on the values supplied in the template. A successful return does not indicate that the RPC server is available, accessible, or correctly specified.

> [!NOTE]
> The rpcdce.h header defines RpcBindingCreate as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[RPC_BINDING_HANDLE](https://learn.microsoft.com/windows/desktop/Rpc/rpc-binding-handle)

[RpcBindingBind](https://learn.microsoft.com/windows/desktop/api/rpcasync/nf-rpcasync-rpcbindingbind)