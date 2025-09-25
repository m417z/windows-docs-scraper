# CancelClusterGroupOperation function

## Description

Enables a client to cancel a
[MoveClusterGroup](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-moveclustergroup) or
[MoveClusterGroupEx](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/nf-clusapi-moveclustergroupex) operation that is pending for a
group. The group is then returned to its persistent state.

## Parameters

### `hGroup` [in]

The handle to a cluster group.

### `dwCancelFlags_RESERVED` [in]

This parameter is reserved for future use and must be set to zero.

## Return value

**CancelClusterGroupOperation** returns
**ERROR_SUCCESS** if the move operation on the group was successfully cancelled.

**CancelClusterGroupOperation** returns
**ERROR_IO_PENDING** if the cancellation of the move operation is now in progress.

**CancelClusterGroupOperation** returns a
different nonzero error code if there was a failure issuing the cancellation for the move group operation on the
designated group.

## Remarks

**CancelClusterGroupOperation** attempts to
cancel a pending move operation on a cluster group that was issued through a
[MoveClusterGroup](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-moveclustergroup) or
[MoveClusterGroupEx](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/nf-clusapi-moveclustergroupex) call that returned
**ERROR_IO_PENDING** and is still in progress. The call attempts to cancel the pending move
operation and bring the group to its persistent state.

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

    // Cancel Move Group example
    error = MoveClusterGroupEx( hGroup,
                                NULL,
                                CLUSAPI_GROUP_MOVE_RETURN_TO_SOURCE_NODE_ON_ERROR | CLUSAPI_GROUP_MOVE_IGNORE_RESOURCE_STATUS,
                                NULL,
                                0);

    if ( error == ERROR_IO_PENDING  )
    {
        wprintf( L"Group move pending" DemoGroupName L": 0x%x\n", error );
        error = ERROR_SUCCESS;

        // Issuing cancel to the move operation
        error = CancelClusterGroupOperation(hGroup, 0);
        if ( error == ERROR_IO_PENDING  || error == ERROR_SUCCESS )
        {
            // the cancel was registered successfully
            wprintf( L"Cancel issued for move operation for the group " DemoGroupName L"\n" );
        }
        else
        {
            wprintf( L"Failed to Cancel move operation for the group " DemoGroupName L": 0x%x\n" );
        }
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