# POFFLINE_V2_ROUTINE callback function

## Description

Marks a [resource](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resources) as unavailable for use after cleanup
processing is complete. The **POFFLINE_V2_ROUTINE** type defines a pointer to
this function.

## Parameters

### `Resource` [in]

A resource identifier for the resource to be taken offline.

### `DestinationNodeName` [in, optional]

The name of the node that is to contain the resource when the operation completes.

### `OfflineFlags` [in]

A bitmask of flags that specify settings for this operation. This parameter can be set to one or more of the following values:

#### CLUS_RESDLL_OFFLINE_IGNORE_RESOURCE_STATUS (0x00000001)

Perform the operation even if the resource indicates that it should be locked.

#### CLUS_RESDLL_OFFLINE_RETURN_TO_SOURCE_NODE_ON_ERROR (0x00000002)

If the resource experiences an error, return it to the source node.

#### CLUS_RESDLL_OFFLINE_QUEUE_ENABLED (0x00000004)

Queue the operation if it is delayed by a resource DLL, and then retry the operation until it completes or is cancelled by the client.

#### CLUS_RESDLL_OFFLINE_RETURNING_TO_SOURCE_NODE_BECAUSE_OF_ERROR (0x00000008)

Indicate that the resource experienced an error, and is returning to the source node.

#### CLUS_RESDLL_OFFLINE_DUE_TO_EMBEDDED_FAILURE (0x00000010)

Indicate that there was an embedded failure.

#### CLUS_RESDLL_OFFLINE_IGNORE_NETWORK_CONNECTIVITY (0x00000020)

Perform the operation even if there is network error.

**Windows Server 2012:** This value is not supported before Windows Server 2012 R2.

#### CLUS_RESDLL_OFFLINE_DO_NOT_UPDATE_PERSISTENT_STATE (0x00000040)

Do not update the persistent state of the resource.

**Windows Server 2012 R2 and Windows Server 2012:** This value is not supported before Windows Server 2016.

### `InBuffer` [in, optional]

A pointer to a buffer that contains data for the operation; otherwise **NULL** if the operation does not require data.

### `InBufferSize` [in]

The size of the *InBuffer* parameter, in bytes.

### `Reserved` [in]

Reserved.

## Return value

| Return code/value | Description |
| --- | --- |
| **ERROR_SUCCESS**<br><br>0 | The request completed successfully, and the resource is offline. |
| **ERROR_IO_PENDING**<br><br>997 (0x3E5) | The request is still pending, and a thread has been activated to process the offline request. |

If the operation was not successful for other reasons,
this function returns one of the
[system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## See also

[Resource DLL Entry Point Functions](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-dll-entry-point-functions)