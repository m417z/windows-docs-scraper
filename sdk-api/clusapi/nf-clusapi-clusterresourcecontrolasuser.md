# ClusterResourceControlAsUser function

## Description

Initiates an operation affecting a [resource](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resources).

The operation performed depends on the [control code](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/control-codes) passed
to the *dwControlCode* parameter.

## Parameters

### `hResource` [in]

Handle to the resource to be affected.

### `hHostNode` [in, optional]

Optional handle to the node to perform the operation. If **NULL**, the node that owns
the resource identified by *hResource* performs the operation.

### `dwControlCode` [in]

A [resource control code](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-control-codes), enumerated by the
[CLUSCTL_RESOURCE_CODES](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ne-clusapi-clusctl_resource_codes) enumeration, specifying
the operation to be performed. For the syntax associated with a control code, refer to
the link on the **CLUSCTL_RESOURCE_CODES** topic.

### `lpInBuffer` [in, optional]

Pointer to an input buffer containing information needed for the operation, or **NULL**
if no information is needed.

### `cbInBufferSize` [in]

The allocated size (in bytes) of the input buffer.

### `lpOutBuffer` [out, optional]

Pointer to an output buffer to receive the data resulting from the operation, or
**NULL** if no data will be returned.

### `cbOutBufferSize` [in]

The allocated size (in bytes) of the output buffer.

### `lpBytesReturned` [out, optional]

Returns the actual size (in bytes) of the data resulting from the operation. If this information is not
needed, pass **NULL** for *lpBytesReturned*.

## Return value

The function returns one of the following values.

| Return code/value | Description |
| --- | --- |
| **ERROR_SUCCESS**<br><br>0 | The operation was successful. If the operation required an output buffer, *lpBytesReturned* (if not **NULL** on input) points to the actual size of the data returned in the buffer. |
| **ERROR_MORE_DATA**<br><br>234 (0xEA) | The output buffer pointed to by *lpOutBuffer* was not large enough to hold the data resulting from the operation. The *lpBytesReturned* parameter (if not **NULL** on input) points to the size required for the output buffer. Only operations requiring an output buffer return **ERROR_MORE_DATA**. If the *lpOutBuffer* parameter is **NULL** and the *cbOutBufferSize* parameter is zero, then **ERROR_SUCCESS** may be returned, not **ERROR_MORE_DATA**. |
| **ERROR_RESOURCE_PROPERTIES_STORED**<br><br>5024 (0x13A0) | Applies only to [CLUSCTL_RESOURCE_SET_COMMON_PROPERTIES](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-set-common-properties) and [CLUSCTL_RESOURCE_SET_PRIVATE_PROPERTIES](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-set-private-properties). Indicates that the properties were successfully stored but have not yet been applied to the resource. The new properties will take effect after the resource is taken offline and brought online again. |
| **ERROR_HOST_NODE_NOT_RESOURCE_OWNER**<br><br>5015 (0x1397) | The node specified by the *hNode* parameter is not the node that owns the resource specified by *hResource*. |
| **[System error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes)** | The operation was not successful. If the operation required an output buffer, the value specified by *lpBytesReturned* (if not **NULL** on input) is unreliable. |

## Remarks

When [ClusterResourceControl](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/nf-clusapi-clusterresourcecontrol) returns
**ERROR_MORE_DATA**, set *cbOutBufferSize* to the number of bytes
pointed to by *lpBytesReturned*, and call the function again.

Do not pass LPC and RPC handles to the same function call. Otherwise, the call will raise an RPC exception and
can have additional destructive effects. For information on how LPC and RPC handles are created, see
[LPC and RPC Handles](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/lpc-and-rpc-handles) and
[OpenCluster](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-opencluster).

The [ClusterResourceControl](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/nf-clusapi-clusterresourcecontrol) function is one
of the [control code functions](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/control-code-functions). For more information
on control codes and control code functions, see
[Using Control Codes](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/using-control-codes).

## See also

[OpenCluster](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-opencluster)

[Resource Type Control Codes](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-type-control-codes)