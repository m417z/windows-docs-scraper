# PONLINE_V2_ROUTINE callback function

## Description

Marks a
[resource](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resources) as available for use. The
**PONLINE_V2_ROUTINE** type defines a pointer to this function.

## Parameters

### `Resource` [in]

A resource identifier for the resource to be made available.

### `EventHandle` [out]

On input, *EventHandle* is **NULL**. On output,
*EventHandle* contains a handle to a non signaled
[synchronization object](https://learn.microsoft.com/windows/desktop/Sync/synchronization-objects). The
[resource DLL](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-dlls) can signal this handle at any time to report
a resource failure to the [Resource Monitor](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-monitor).
*EventHandle* can also be set to **NULL** on output, which indicates
that the resource does not support asynchronous event notifications.

### `OnlineFlags` [in]

A bitmask of flags that specify settings for this operation. This parameter can be set to one or more of the following values:

#### CLUS_RESDLL_ONLINE_RECOVER_MONITOR_STATE (0x00000001)

Monitor the state of the resource if the resource is recovering from an error.

#### CLUS_RESDLL_ONLINE_IGNORE_RESOURCE_STATUS (0x00000002)

Perform the operation even if the resource indicates that it should be locked.

#### CLUS_RESDLL_ONLINE_RETURN_TO_SOURCE_NODE_ON_ERROR (0x00000004)

If the resource experiences an error, return it to the source node.

#### CLUS_RESDLL_ONLINE_RESTORE_ONLINE_STATE (0x00000008)

Set the status of the resource to online.

#### CLUS_RESDLL_ONLINE_IGNORE_NETWORK_CONNECTIVITY (0x00000010)

Perform the operation even if there is network error.

### `InBuffer` [in, optional]

A pointer to a buffer that contains data for the operation; otherwise **NULL** if the operation does not require data.

### `InBufferSize` [in]

The size of the *InBuffer* parameter, in bytes.

### `Reserved` [in]

Reserved.

## Return value

| Return code/value | Description |
| --- | --- |
| **ERROR_SUCCESS**<br><br>0 | The operation was successful, and the resource is online. |
| **ERROR_RESOURCE_NOT_AVAILABLE**<br><br>5006 (0x138E) | The resource was arbitrated with some other systems, and one of the other systems won the arbitration. Only [quorum-capable resources](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/q-gly) return this value. |
| **ERROR_IO_PENDING**<br><br>997 (0x3E5) | The request is pending, and a thread has been activated to process the online request. |

If the operation was not successful for other reasons,
a
system error code is returned.

## See also

[Resource DLL Entry-Point Functions](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-dll-entry-point-functions)