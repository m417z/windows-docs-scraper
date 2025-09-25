# ClusterControl function

## Description

Initiates an
operation that affects a [cluster](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/c-gly). The operation
performed depends on the [control code](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/control-codes) passed to the
*dwControlCode* parameter.

## Parameters

### `hCluster` [in]

Handle to the cluster to be affected.

### `hHostNode` [in, optional]

If non-**NULL**, handle to the node to perform the operation represented by the control
code. If **NULL**, the local node performs the operation. Specifying
*hHostNode* is optional.

### `dwControlCode` [in]

A [cluster control code](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-control-codes) from the
[CLUSCTL_CLUSTER_CODES](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ne-clusapi-clusctl_cluster_codes) enumeration that specifies
the operation to be performed. For the syntax associated with a control code, refer to
[Control Code Architecture](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/control-code-architecture) and the following
topics:

* [CLUSCTL_CLUSTER_CHECK_VOTER_DOWN](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-cluster-check-voter-down)
* [CLUSCTL_CLUSTER_CHECK_VOTER_EVICT](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-cluster-check-voter-evict)
* [CLUSCTL_CLUSTER_CLEAR_NODE_CONNECTION_INFO](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-cluster-clear-node-connection-info)
* [CLUSCTL_CLUSTER_ENUM_COMMON_PROPERTIES](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-cluster-enum-common-properties)
* [CLUSCTL_CLUSTER_ENUM_PRIVATE_PROPERTIES](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-cluster-enum-private-properties)
* [CLUSCTL_CLUSTER_GET_COMMON_PROPERTIES](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-cluster-get-common-properties)
* [CLUSCTL_CLUSTER_GET_FQDN](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-cluster-get-fqdn)
* [CLUSCTL_CLUSTER_GET_COMMON_PROPERTY_FMTS](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-cluster-get-common-property-fmts)
* [CLUSCTL_CLUSTER_GET_PRIVATE_PROPERTIES](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-cluster-get-private-properties)
* [CLUSCTL_CLUSTER_GET_PRIVATE_PROPERTY_FMTS](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-cluster-get-private-property-fmts)
* [CLUSCTL_CLUSTER_GET_RO_COMMON_PROPERTIES](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-cluster-get-ro-common-properties)
* [CLUSCTL_CLUSTER_GET_RO_PRIVATE_PROPERTIES](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-cluster-get-ro-private-properties)
* [CLUSCTL_CLUSTER_GET_SHARED_VOLUME_ID](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-cluster-get-shared-volume-id)
* [CLUSCTL_CLUSTER_SET_COMMON_PROPERTIES](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-cluster-set-common-properties)
* [CLUSCTL_CLUSTER_SET_PRIVATE_PROPERTIES](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-cluster-set-private-properties)
* [CLUSCTL_CLUSTER_SHUTDOWN](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-cluster-shutdown)
* [CLUSCTL_CLUSTER_UNKNOWN](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-cluster-unknown)
* [CLUSCTL_CLUSTER_VALIDATE_COMMON_PROPERTIES](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-cluster-validate-common-properties)
* [CLUSCTL_CLUSTER_VALIDATE_PRIVATE_PROPERTIES](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-cluster-validate-private-properties)

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

### `lpBytesReturned` [out, optional]

Returns the actual size (in bytes) of the data resulting from the operation. If this information is not
needed, pass **NULL** for *lpcbBytesReturned*.

## Return value

The function returns one of the following values.

| Return code | Description |
| --- | --- |
| **ERROR_SUCCESS** | The operation was successful. If the operation required an output buffer, *lpcbBytesReturned* (if not **NULL** on input) points to the actual size of the data returned in the buffer. |
| **ERROR_MORE_DATA** | The output buffer pointed to by *lpOutBuffer* was not large enough to hold the data resulting from the operation. The *lpcbBytesReturned* parameter (if not **NULL** on input) points to the size required for the output buffer. Only operations requiring an output buffer return **ERROR_MORE_DATA**. If the *lpOutBuffer* parameter is **NULL** and the *nOutBufferSize* parameter is zero, then **ERROR_SUCCESS** may be returned, not **ERROR_MORE_DATA**. |
| **[System error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes)** | The operation was not successful. If the operation required an output buffer, the value specified by *lpcbBytesReturned* (if not **NULL** on input) is unreliable. |

## Remarks

If **ClusterControl** returns
**ERROR_MORE_DATA**, set *nOutBufferSize* to the number of bytes
pointed to by *lpcbBytesReturned* and call the function again.

Do not pass LPC and RPC handles to the same function call. Otherwise, the call will raise an RPC exception and
can have additional destructive effects. For information on how LPC and RPC handles are created, see
[LPC and RPC Handles](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/lpc-and-rpc-handles) and
[OpenCluster](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-opencluster).

**ClusterControl** is one of the
[control code functions](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/control-code-functions). For more information on
control codes and control code functions, see
[Using Control Codes](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/using-control-codes).

## See also

[Cluster Control Codes](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-control-codes)

[OpenCluster](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-opencluster)