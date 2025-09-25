# OnlineClusterResourceEx function

## Description

Brings an offline or failed [resource](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resources) online.

## Parameters

### `hResource` [in]

The handle to the resource to bring online.

### `dwOnlineFlags` [in]

A flag that specifies settings for the resource that is to be brought online.

#### CLUSAPI_GROUP_ONLINE_IGNORE_RESOURCE_STATUS (0x00000001)

The server is to ignore locked mode for the resource.

#### CLUSAPI_RESOURCE_ONLINE_DO_NOT_UPDATE_PERSISTENT_STATE (0x00000002)

Do not update the persistent state of the resource.

#### CLUSAPI_RESOURCE_ONLINE_NECESSARY_FOR_QUORUM (0x00000004)

The resource must be brought online to maintain a quorum.

#### CLUSAPI_RESOURCE_ONLINE_BEST_POSSIBLE_NODE (0x00000008)

The cluster service is to determine the node that will host the resource when it is brought online.

**Windows Server 2012 R2 and Windows Server 2012:** This value is not supported before Windows Server 2016.

#### 0

The server is not to ignore locked mode for the resource.

### `lpInBuffer` [in, optional]

A pointer to the input buffer that receives instructions for the operation. The *lpInBuffer* parameter is formatted as a property list.

### `cbInBufferSize` [in]

The size of *lpInBuffer*, in bytes.

## Return value

If the operation succeeds, the function returns **ERROR_SUCCESS**.

If the operation fails,
the function returns a [system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes). The following is a possible error code.

| Return code | Description |
| --- | --- |
| **ERROR_IO_PENDING** | The resource or one of the resources that it depends on has returned **ERROR_IO_PENDING** from its [Online](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-ponline_routine) entry point function. |

## See also

[Failover Cluster Resource Management Functions](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-management-functions)