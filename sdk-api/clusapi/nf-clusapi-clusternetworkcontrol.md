# ClusterNetworkControl function

## Description

Initiates
an operation on a [network](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/networks). The operation performed depends on the
[control code](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/control-codes) passed to the
*dwControlCode* parameter.

## Parameters

### `hNetwork` [in]

Handle to the network to be affected by the operation.

### `hHostNode` [in, optional]

If non-**NULL**, handle to the [node](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/nodes)
hosting the affected network. If **NULL**, the local node performs the operation.
Specifying *hHostNode* is optional.

### `dwControlCode` [in]

A [network control code](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/network-control-codes) specifying the
operation to be performed. For the syntax associated with a control code, refer to
[Control Code Architecture](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/control-code-architecture) and the following
topics:

* [CLUSCTL_NETWORK_ENUM_COMMON_PROPERTIES](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-network-enum-common-properties)
* [CLUSCTL_NETWORK_ENUM_PRIVATE_PROPERTIES](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-network-enum-private-properties)
* [CLUSCTL_NETWORK_GET_CHARACTERISTICS](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-network-get-characteristics)
* [CLUSCTL_NETWORK_GET_COMMON_PROPERTIES](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-network-get-common-properties)
* [CLUSCTL_NETWORK_GET_COMMON_PROPERTY_FMTS](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-network-get-common-property-fmts)
* [CLUSCTL_NETWORK_GET_FLAGS](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-network-get-flags)
* [CLUSCTL_NETWORK_GET_ID](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-network-get-id)
* [CLUSCTL_NETWORK_GET_NAME](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-network-get-name)
* [CLUSCTL_NETWORK_GET_PRIVATE_PROPERTIES](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-network-get-private-properties)
* [CLUSCTL_NETWORK_GET_PRIVATE_PROPERTY_FMTS](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-network-get-private-property-fmts)
* [CLUSCTL_NETWORK_GET_RO_COMMON_PROPERTIES](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-network-get-ro-common-properties)
* [CLUSCTL_NETWORK_GET_RO_PRIVATE_PROPERTIES](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-network-get-ro-private-properties)
* [CLUSCTL_NETWORK_SET_COMMON_PROPERTIES](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-network-set-common-properties)
* [CLUSCTL_NETWORK_SET_PRIVATE_PROPERTIES](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-network-set-private-properties)
* [CLUSCTL_NETWORK_UNKNOWN](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-network-unknown)
* [CLUSCTL_NETWORK_VALIDATE_COMMON_PROPERTIES](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-network-validate-common-properties)
* [CLUSCTL_NETWORK_VALIDATE_PRIVATE_PROPERTIES](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-network-validate-private-properties)

### `lpInBuffer` [in, optional]

Pointer to an input buffer containing information needed for the operation, or **NULL**
if no information is needed.

### `nInBufferSize` [in]

The allocated size (in bytes) of the input buffer.

### `lpOutBuffer` [out, optional]

Pointer to an output buffer to receive the data resulting from the operation, or
**NULL** if no data will be returned.

### `nOutBufferSize` [in]

The allocated size (in bytes) of the output buffer.

### `lpBytesReturned` [in, out, optional]

Returns the actual size (in bytes) of the data resulting from the operation. If this information is not
needed, pass **NULL** for *lpBytesReturned*.

## Return value

The function returns one of the following values.

| Return code | Description |
| --- | --- |
| **ERROR_SUCCESS** | The operation was successful. If the operation required an output buffer, *lpBytesReturned* (if not **NULL** on input) points to the actual size of the data returned in the buffer. |
| **ERROR_MORE_DATA** | The output buffer pointed to by *lpOutBuffer* was not large enough to hold the data resulting from the operation. The *lpBytesReturned* parameter (if not **NULL** on input) points to the size required for the output buffer. Only operations requiring an output buffer return **ERROR_MORE_DATA**. If the *lpOutBuffer* parameter is **NULL** and the *nOutBufferSize* parameter is zero, then **ERROR_SUCCESS** may be returned, not **ERROR_MORE_DATA**. |
| **[System error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes)** | The operation was not successful. If the operation required an output buffer, the value specified by *lpBytesReturned* (if not **NULL** on input) is unreliable. |

## Remarks

If **ClusterNetworkControl** returns
**ERROR_MORE_DATA**, set *nOutBufferSize* to the number of bytes
pointed to by *lpBytesReturned*, and call the function again.

Do not pass LPC and RPC handles to the same function call. Otherwise, the call will raise an RPC exception and
can have additional destructive effects. For information on how LPC and RPC handles are created, see
[LPC and RPC Handles](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/lpc-and-rpc-handles) and
[OpenCluster](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-opencluster).

**ClusterNetworkControl** is one of the
[control code functions](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/control-code-functions). For more information on
control codes and control code functions, see
[Using Control Codes](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/using-control-codes).

## See also

[Network Control Codes](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/network-control-codes)

[OpenCluster](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-opencluster)