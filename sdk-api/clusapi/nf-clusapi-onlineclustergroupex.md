# OnlineClusterGroupEx function

## Description

Brings a [group](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/groups) online.

## Parameters

### `hGroup` [in]

A handle to the group to be brought online.

### `hDestinationNode` [in, optional]

A handle to the [node](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/nodes) that is to host the group.

### `dwOnlineFlags` [in]

A flag that specifies settings for the resource that is to be brought online.

#### CLUSAPI_GROUP_ONLINE_IGNORE_RESOURCE_STATUS (0x00000001)

The server is to ignore locked mode for the resource.

#### CLUSAPI_GROUP_ONLINE_SYNCHRONOUS (0x00000002)

Use a synchronous operation to bring the group online.

**Windows Server 2012 R2 and Windows Server 2012:** This value was added in Windows Server 2016.

#### CLUSAPI_GROUP_ONLINE_BEST_POSSIBLE_NODE (0x00000004)

Let the cluster service is to determine the node that will host the group when it is brought online.

**Windows Server 2012 R2 and Windows Server 2012:** This value was added in Windows Server 2016.

#### 0

The server is not to ignore locked mode for the resource.

### `lpInBuffer` [in, optional]

A pointer to the input buffer that receives instructions for the operation. The *lpInBuffer* parameter is formatted as a property list.

### `cbInBufferSize` [in]

The size of the *lpInBuffer* parameter, in bytes.

## Return value

If the operation succeeds, the function returns **ERROR_SUCCESS**.

If the operation fails,
the function returns a [system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes). The following are possible error codes.

| Return code | Description |
| --- | --- |
| **ERROR_HOST_NODE_NOT_AVAILABLE** | A suitable host node was not available. |
| **ERROR_IO_PENDING** | The operation is in progress. |

## See also

[Group Management Functions](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/group-management-functions)