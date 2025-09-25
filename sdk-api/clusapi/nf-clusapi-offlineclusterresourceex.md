# OfflineClusterResourceEx function

## Description

Extends the [OfflineClusterResource](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-offlineclusterresource)
method. The client can use the flags to control policies of the resource and the input buffer to send specific
instructions for the offline operation to the resource. For instance, the input buffer can be used to instruct a
VM to go offline by saving its state as opposed to shutting down.

## Parameters

### `hResource` [in]

The handle to a cluster resource.

### `dwOfflineFlags` [in]

Flags that influence the offline policy.

This parameter can be set to one or more of the following values:

#### CLUSAPI_RESOURCE_OFFLINE_IGNORE_RESOURCE_STATUS (0x00000001)

Ignore the status of the resource if the resource is locked.

#### CLUSAPI_RESOURCE_OFFLINE_FORCE_WITH_TERMINATION (0x00000002)

The resource is to be marked as unavailable and shut down without waiting for the cleanup process to
complete.

#### CLUSAPI_RESOURCE_OFFLINE_REASON_NONE (0x00000000)

No flags are specified.

**Windows Server 2012:** This value is not supported before Windows Server 2012 R2.

#### CLUSAPI_RESOURCE_OFFLINE_REASON_UNKNOWN (0x00000001)

The reason is unknown.

**Windows Server 2012:** This value is not supported before Windows Server 2012 R2.

#### CLUSAPI_RESOURCE_OFFLINE_REASON_MOVING (0x00000002)

The resource is being moved to another node.

**Windows Server 2012:** This value is not supported before Windows Server 2012 R2.

#### CLUSAPI_RESOURCE_OFFLINE_REASON_USER_REQUESTED (0x00000004)

There was a user request to bring the resource offline.

**Windows Server 2012:** This value is not supported before Windows Server 2012 R2.

#### CLUSAPI_RESOURCE_OFFLINE_REASON_BEING_DELETED (0x00000008)

The resource is being deleted.

**Windows Server 2012:** This value is not supported before Windows Server 2012 R2.

#### CLUSAPI_RESOURCE_OFFLINE_REASON_BEING_RESTARTED (0x00000010)

The resource is being restarted.

**Windows Server 2012:** This value is not supported before Windows Server 2012 R2.

#### CLUSAPI_RESOURCE_OFFLINE_REASON_PREEMPTED (0x00000020)

The resource had a preemptive failure.

**Windows Server 2012:** This value is not supported before Windows Server 2012 R2.

#### CLUSAPI_RESOURCE_OFFLINE_REASON_SHUTTING_DOWN (0x00000040)

The resource is shutting down.

**Windows Server 2012:** This value is not supported before Windows Server 2012 R2.

### `lpInBuffer` [in]

Contains instructions for the offline operation that are targeted at the specific resource.
*lpInBuffer* is formatted as a property list, which means that the instructions are
contained in property values. The resource DLL searches the property list for property names that it supports
for offline operations and then interprets the instructions in the associated property value. Note that the
properties supported by a resource in an
**OfflineClusterResourceEx** operation are not
related to the private properties associated with a resource.

### `cbInBufferSize` [in]

The size of *lpInBuffer*, in bytes.

## Return value

**OfflineClusterResourceEx** returns
**ERROR_IO_PENDING** if the offline command has been accepted and is in progress.
**OfflineClusterResourceEx** returns a nonzero
error code if the offline command was rejected immediately with no changes to resource state.

## Remarks

**OfflineClusterResourceEx** fails immediately
with error **ERROR_CLUSTER_RESOURCE_LOCKED_STATUS** if the
**CLUSAPI_RESOURCE_OFFLINE_IGNORE_RESOURCE_LOCKED_STATUS** flag is not set and the resource
has indicated that it is “locked” in its current state.

Similar to [MoveClusterGroupEx](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/nf-clusapi-moveclustergroupex), if
**OfflineClusterResourceEx** returns
**ERROR_IO_PENDING**, then the cluster service will attempt to bring the resource to the
offline state.

**OfflineClusterResourceEx** requires that the
client be granted Full access in the cluster security descriptor.

#### Examples

```
#include "stdafx.h"
#include <windows.h>
#include <stdio.h>
#include <ClusAPI.h>

#define DemoResDllTypeName L"dummy"
#define DemoResourceName L"DemoResource"

BOOL WaitForResourceToGoOffline(__in HRESOURCE hResource)
{
    for(;;)
    {
        CLUSTER_RESOURCE_STATE state = GetClusterResourceState( hResource, NULL, 0, NULL, 0 );
        if( state == ClusterResourceOnline || state == ClusterResourceFailed)
        {
            return false;
        }
        else if ( state == ClusterResourceOffline )
        {
            return true;
        }

        Sleep(100);
    }
}

int __cdecl main( void )
{
    HCLUSTER hCluster= NULL;
    HRESOURCE hResource = NULL;
    DWORD error = 0;

    hCluster = OpenCluster( NULL );
    if ( hCluster == NULL )
    {
        error = GetLastError();
        wprintf( L"Failed to open cluster: 0x%x\n", error );
        goto Cleanup;
    }

    hResource = OpenClusterResource( hCluster, DemoResourceName );
    if ( hResource == NULL )
    {
        error = GetLastError();
        wprintf( L"Failed to open cluster resource " DemoResourceName L": 0x%x\n", error );
        goto Cleanup;
    }

    // Offlining Resource example
    error = OfflineClusterResourceEx(hResource, CLUSAPI_RESOURCE_OFFLINE_IGNORE_RESOURCE_STATUS, NULL, 0);
    if ( error == ERROR_IO_PENDING  )
    {
        if (WaitForResourceToGoOffline(hResource))
        {
            error = ERROR_SUCCESS;
        }
    }
    if ( error )
    {
        wprintf( L"Failed to offline the resource" DemoResourceName L": 0x%x\n", error );
        goto Cleanup;
    }
    else
    {
        wprintf( L"Offlined the resource" DemoResourceName);
    }

Cleanup:

    if ( hResource != NULL )
    {
        CloseClusterResource( hResource );
        hResource = NULL;
    }
    if ( hCluster != NULL )
    {
        CloseCluster( hCluster );
        hCluster = NULL;
    }

    return (int)error;
}
```