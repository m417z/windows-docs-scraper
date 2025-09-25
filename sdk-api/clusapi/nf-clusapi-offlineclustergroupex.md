# OfflineClusterGroupEx function

## Description

Extends the [OfflineClusterGroup](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-offlineclustergroup) method.
The client can use the flags to control failover policies of the group and the input buffer to send specific
instructions for the offline operation to the resources in the target group. For instance, the input buffer can be
used to instruct a virtual machine to go offline by saving its state as opposed to shutting down.

## Parameters

### `hGroup` [in]

The handle to a cluster group.

### `dwOfflineFlags` [in]

Flags that influence the offline policy. Along with 0x0, the following is an acceptable value:
**CLUSAPI_GROUP_OFFLINE_IGNORE_RESOURCE_LOCKED_STATUS** (0x00000001): disregard if a
resource has indicated that it should be “locked” in its current state.

### `lpInBuffer`

Contains instructions for the offline operation that are targeted at specific resources within the group.
*lpInBuffer* is formatted as a property list, which means that the instructions are
contained in property values. Resources in the group search the property list for property names that they
support for offline operations and then interpret the instructions in the associated property value. Note that
the properties supported by a resource in an
**OfflineClusterGroupEx** operation are not
related to the private properties associated with a resource.

### `cbInBufferSize` [in]

The size of *lpInBuffer*, in bytes.

## Return value

**OfflineClusterGroupEx** returns
**ERROR_IO_PENDING** if the offline command has been accepted and is in progress.
**OfflineClusterGroupEx** returns a nonzero error
code if the offline command was rejected immediately with no changes to group state.

## Remarks

**OfflineClusterGroupEx** fails immediately with
error **ERROR_CLUSTER_RESOURCE_LOCKED_STATUS** if the
**CLUSAPI_OFFLINE_GROUP_IGNORE_RESOURCE_LOCKED_STATUS** flag is not set and any resource in
the group has indicated that it is “locked” in its current state.

Similar to [MoveClusterGroupEx](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/nf-clusapi-moveclustergroupex), if
**OfflineClusterGroupEx** returns
**ERROR_IO_PENDING**, then the cluster service will attempt to bring the group to the
offline state.

**OfflineClusterGroupEx** requires that the client
be granted Full access in the cluster security descriptor.

#### Examples

```
#include "stdafx.h"
#include <windows.h>
#include <stdio.h>
#include <ClusAPI.h>

#define DemoResDllTypeName L"dummy"
#define DemoGroupName L"DemoGroup"

BOOL WaitForGroupToGoOffline(__in HGROUP hGroup)
{
    for(;;)
    {
        CLUSTER_GROUP_STATE state = GetClusterGroupState( hGroup, NULL, NULL );
        if( state == ClusterGroupFailed || state == ClusterGroupPartialOnline || state == ClusterGroupOnline)
        {
            return false;
        }
        else if ( state == ClusterGroupOffline )
        {
            return true;
        }

        Sleep(100);
    }
}

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

    // Offlining Group example
    error = OfflineClusterGroupEx(hGroup, CLUSAPI_GROUP_OFFLINE_IGNORE_RESOURCE_STATUS, NULL, 0);
    if ( error == ERROR_IO_PENDING  )
    {
        if (WaitForGroupToGoOffline(hGroup))
        {
            error = ERROR_SUCCESS;
        }
    }
    if ( error )
    {
        wprintf( L"Failed to offline the group" DemoGroupName L": 0x%x\n", error );
        goto Cleanup;
    }
    else
    {
        wprintf( L"Offlined the group" DemoGroupName);
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