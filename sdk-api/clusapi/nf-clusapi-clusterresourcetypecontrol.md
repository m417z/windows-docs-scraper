# ClusterResourceTypeControl function

## Description

Initiates an operation affecting a [resource type](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-types). The
operation performed depends on the [control code](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/control-codes) passed to the
*dwControlCode* parameter.

## Parameters

### `hCluster` [in]

Handle to the cluster containing the resource type identified in
*lpszResourceTypeName*.

### `lpszResourceTypeName` [in]

Pointer to a **NULL**-terminated Unicode string containing the name of the resource
type to be affected.

### `hHostNode` [in, optional]

Handle to the node hosting the affected resource type.

### `dwControlCode` [in]

A [resource type control code](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-type-control-codes) specifying
the operation to be performed. For the syntax associated with a control code, refer to
[Control Code Architecture](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/control-code-architecture) and the following
topics:

* [CLUSCTL_RESOURCE_TYPE_ENUM_COMMON_PROPERTIES](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-type-enum-common-properties)
* [CLUSCTL_RESOURCE_TYPE_ENUM_PRIVATE_PROPERTIES](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-type-enum-private-properties)
* [CLUSCTL_RESOURCE_TYPE_GET_CHARACTERISTICS](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-type-get-characteristics)
* [CLUSCTL_RESOURCE_TYPE_GET_CLASS_INFO](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-type-get-class-info)
* [CLUSCTL_RESOURCE_TYPE_GET_COMMON_PROPERTIES](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-type-get-common-properties)
* [CLUSCTL_RESOURCE_TYPE_GET_COMMON_PROPERTY_FMTS](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-type-get-common-property-fmts)
* [CLUSCTL_RESOURCE_TYPE_GET_COMMON_RESOURCE_PROPERTY_FMTS](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-type-get-common-resource-property-fmts)
* [CLUSCTL_RESOURCE_TYPE_GET_CRYPTO_CHECKPOINTS](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-type-get-crypto-checkpoints)
* [CLUSCTL_RESOURCE_TYPE_GET_FLAGS](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-type-get-flags)
* [CLUSCTL_RESOURCE_TYPE_GET_PRIVATE_PROPERTIES](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-type-get-private-properties)
* [CLUSCTL_RESOURCE_TYPE_GET_PRIVATE_PROPERTY_FMTS](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-type-get-private-property-fmts)
* [CLUSCTL_RESOURCE_TYPE_GET_PRIVATE_RESOURCE_PROPERTY_FMTS](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-type-get-private-resource-property-fmts)
* [CLUSCTL_RESOURCE_TYPE_GET_REGISTRY_CHECKPOINTS](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-type-get-registry-checkpoints)
* [CLUSCTL_RESOURCE_TYPE_GET_REQUIRED_DEPENDENCIES](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-type-get-required-dependencies)
* [CLUSCTL_RESOURCE_TYPE_GET_RO_COMMON_PROPERTIES](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-type-get-ro-common-properties)
* [CLUSCTL_RESOURCE_TYPE_GET_RO_PRIVATE_PROPERTIES](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-type-get-ro-private-properties)
* [CLUSCTL_RESOURCE_TYPE_QUERY_DELETE](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-type-query-delete)
* [CLUSCTL_RESOURCE_TYPE_SET_COMMON_PROPERTIES](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-type-set-common-properties)
* [CLUSCTL_RESOURCE_TYPE_SET_PRIVATE_PROPERTIES](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-type-set-private-properties)
* [CLUSCTL_RESOURCE_TYPE_STORAGE_GET_AVAILABLE_DISKS](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-type-storage-get-available-disks)
* [CLUSCTL_RESOURCE_TYPE_STORAGE_GET_RESOURCEID](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-type-storage-get-resourceid)
* [CLUSCTL_RESOURCE_TYPE_UNKNOWN](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-type-unknown)
* [CLUSCTL_RESOURCE_TYPE_VALIDATE_COMMON_PROPERTIES](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-type-validate-common-properties)
* [CLUSCTL_RESOURCE_TYPE_VALIDATE_PRIVATE_PROPERTIES](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-type-validate-private-properties)

### `lpInBuffer` [in, optional]

Pointer to the input buffer with information needed for the operation, or **NULL** if
no information is needed.

### `nInBufferSize` [in]

Number of bytes in the buffer pointed to by *lpInBuffer*.

### `lpOutBuffer` [out, optional]

Pointer to the output buffer with information resulting from the operation, or
**NULL** if nothing will be returned.

### `nOutBufferSize` [in]

Number of bytes in the output buffer pointed to by *lpOutBuffer*, or zero if the
caller does not know how much data will be returned.

### `lpBytesReturned` [out, optional]

Pointer to the number of bytes in the buffer pointed to by *lpOutBuffer* that were
actually filled in as a result of the operation. The caller can pass **NULL** for
*lpBytesReturned* if
**ClusterResourceTypeControl** does not need
to pass back the number of bytes in the output buffer.

## Return value

The function returns one of the following values.

| Return code | Description |
| --- | --- |
| **ERROR_SUCCESS** | The operation was successful. If the operation required an output buffer, *lpBytesReturned* (if not **NULL** on input) points to the actual size of the data returned in the buffer. |
| **ERROR_MORE_DATA** | The output buffer pointed to by *lpOutBuffer* was not large enough to hold the data resulting from the operation. The *lpBytesReturned* parameter (if not **NULL** on input) points to the size required for the output buffer. Only operations requiring an output buffer return **ERROR_MORE_DATA**. If the *lpOutBuffer* parameter is **NULL** and the *nOutBufferSize* parameter is zero, then **ERROR_SUCCESS** may be returned, not **ERROR_MORE_DATA**. |
| **[System error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes)** | The operation was not successful. If the operation required an output buffer, the value specified by *lpBytesReturned* is unreliable. |

## Remarks

When **ClusterResourceTypeControl** returns
**ERROR_MORE_DATA**, set *nOutBufferSize* to the number of bytes
pointed to by *lpBytesReturned*, and call the function again.

Do not pass LPC and RPC handles to the same function call. Otherwise, the call will raise an RPC exception and
can have additional destructive effects. For information on how LPC and RPC handles are created, see
[LPC and RPC Handles](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/lpc-and-rpc-handles) and
[OpenCluster](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-opencluster).

**ClusterResourceTypeControl** is one of the
[control code functions](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/control-code-functions). For more information on
control codes and control code functions, see
[Using Control Codes](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/using-control-codes).

## See also

[OpenCluster](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-opencluster)

[Resource Type Control Codes](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-type-control-codes)