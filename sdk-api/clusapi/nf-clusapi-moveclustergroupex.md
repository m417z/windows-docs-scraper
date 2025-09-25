# MoveClusterGroupEx function

## Description

Extends the existing [MoveClusterGroup](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-moveclustergroup) method with the addition of flags and a buffer. The flags control the behavior of the cluster failover policy, and the input buffer enables the client to send special instructions to the resources in the group.

## Parameters

### `hGroup` [in]

The handle to a cluster group.

### `hDestinationNode` [in, optional]

The handle to a cluster node, indicating the node to which the group should be moved. This parameter is optional. If left **NULL**, the cluster will move the group to the most suitable node, according to failover policies configured for the cluster and for this particular group.

### `dwMoveFlags` [in]

A bitwise combination of the flags that influence the failover policy with respect to this move operation.

#### CLUSAPI_GROUP_MOVE_IGNORE_RESOURCE_STATUS (0x00000001)

Forces the group move even if a resource has indicated that it should be "locked" in its current state on the current node, and terminates the resource if necessary.

#### CLUSAPI_GROUP_MOVE_RETURN_TO_SOURCE_NODE_ON_ERROR (0x00000002)

If the group fails to reach its persistent state on the destination node (whether specified with *hDestinationNode* or chosen by the cluster), returns the group to the source node and brings it to its persistent state there.

#### CLUSAPI_GROUP_MOVE_QUEUE_ENABLED (0x00000004)

If a resource DLL in the group indicates that the move is not possible at this time but may be possible in the near future, queues this move in the cluster service and continues retrying, when deemed appropriate, until either the move operation completes or is cancelled by the client.

#### CLUSAPI_GROUP_MOVE_HIGH_PRIORITY_START (0x00000008)

Brings this group to its persistent state on the destination node as soon as possible without regard to implementation-specific policies that govern the ordering and/or prioritization of bringing groups to their persistent states.

#### CLUSAPI_GROUP_MOVE_FAILBACK (0x00000010)

Reserved.

### `lpInBuffer` [in, optional]

A [property list](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/property-lists) that contains move operation instructions for specific resources within the group. The instructions are contained in property values. Resources in the group search the property list for property names that they support for move operations and then interpret the instructions in the associated property value. The properties supported by a resource in a **MoveClusterGroupEx** operation are not related to the private properties associated with a resource.

### `cbInBufferSize` [in]

The size of *lpInBuffer*, in bytes.

## Return value

**MoveClusterGroupEx** returns **ERROR_IO_PENDING** if the move command has been accepted and is in progress. **MoveClusterGroupEx** returns a nonzero error code if the move command was rejected immediately with no changes to group state. For instance, this would happen if *hDestinationNode* is not Up at the time of the move request.

## Remarks

**MoveClusterGroupEx** fails immediately with error **ERROR_CLUSTER_RESOURCE_LOCKED_STATUS** if the **CLUSAPI_GROUP_MOVE_IGNORE_RESOURCE_STATUS** flag is not set and any resource in the group is online and has indicated that it is "locked" in its current state.

After **MoveClusterGroupEx** returns **ERROR_IO_PENDING**, there are a number of possible outcomes, including:

* The move operation could succeed, and the group could reach its persistent state on the target node.
* The move operation could fail, in that the group cannot reach its persistent state on the target node. If *dwMoveFlags* does not include **CLUSAPI_GROUP_MOVE_RETURN_TO_SOURCE_NODE_ON_ERROR**, then the cluster will take appropriate action (according to configured policies) to bring the group to its persistent state, perhaps on other nodes in the cluster. If *dwMoveFlags* includes **CLUSAPI_GROUP_MOVE_RETURN_TO_SOURCE_NODE_ON_ERROR**, then the cluster will attempt to bring the group to its persistent state on the source node. If this fails, then the cluster will take appropriate action (according to configured policies) to bring the group to its persistent state, perhaps on other nodes in the cluster.
* The move operation could be queued if a resource indicates that it cannot move immediately and the **CLUSAPI_GROUP_MOVE_QUEUE_ENABLED** flag is set.
* The move operation could be rejected by a resource in the group, thus returning the group to its persistent state on the source node without incrementing any failure counts or triggering any failure policies. This cannot occur if the **CLUSAPI_GROUP_MOVE_IGNORE_RESOURCE_STATUS** flag is set.

For a live migration of a virtual machine, perform these steps:

1. In the *dwMoveFlags* parameter, set the **CLUSAPI_GROUP_MOVE_RETURN_TO_SOURCE_NODE_ON_ERROR**, **CLUSAPI_GROUP_MOVE_QUEUE_ENABLED**, and **CLUSAPI_GROUP_MOVE_HIGH_PRIORITY_START** flags.
2. In the *lpInBuffer* parameter, add to the property list a resource type named "Virtual Machine" or "Virtual Machine Configuration" that specifies a [CLUSTER_PROPERTY_FORMAT](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ne-clusapi-cluster_property_format) enumeration value of **CLUSPROP_FORMAT_DWORD** (which represents the property's data format) and a property value of **VmResdllContextLiveMigration** (from the [VM_RESDLL_CONTEXT](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/ne-resapi-vm_resdll_context) enumeration of possible virtual machine actions).

**MoveClusterGroupEx** requires that the client be granted Full access in the cluster security descriptor.

#### Examples

```
#include "stdafx.h"
#include <windows.h>
#include <stdio.h>
#include <ClusAPI.h>

#define DemoResDllTypeName L"dummy"
#define DemoGroupName L"DemoGroup"

int __cdecl main( void )
{
    HCLUSTER hCluster= NULL;
    HGROUP hGroup = NULL;
    DWORD error = 0;

    hCluster = OpenCluster( NULL );
    if ( hCluster == NULL )
    {
        error = GetLastError();
        wprintf( L"Failed to open cluster: 0x%x\n", error );
        goto Cleanup;
    }

    hGroup = OpenClusterGroup( hCluster, DemoGroupName );
    if ( hGroup == NULL )
    {
        error = GetLastError();
        wprintf( L"Failed to open cluster group " DemoGroupName L": 0x%x\n", error );
        goto Cleanup;
    }

    // Move Group example
    error = MoveClusterGroupEx( hGroup,
                                NULL,
                                CLUSAPI_GROUP_MOVE_RETURN_TO_SOURCE_NODE_ON_ERROR | CLUSAPI_GROUP_MOVE_IGNORE_RESOURCE_STATUS,
                                NULL,
                                0);

    if ( error == ERROR_IO_PENDING  )
    {
        wprintf( L"Group move pending" DemoGroupName L": 0x%x\n", error );
        error = ERROR_SUCCESS;
    }
    else if ( error != ERROR_SUCCESS)
    {
        wprintf( L"Failed to move group" DemoGroupName L": 0x%x\n", error );
    }
    else
    {
        wprintf( L"Group move completed" DemoGroupName L": 0x%x\n");
    }

Cleanup:

    if ( hGroup != NULL )
    {
        CloseClusterGroup( hGroup );
        hGroup = NULL;
    }
    if ( hCluster != NULL )
    {
        CloseCluster( hCluster );
        hCluster = NULL;
    }

    return (int)error;
}

```