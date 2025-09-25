# CLUS_STARTING_PARAMS structure

## Description

Indicates whether a [node's](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/nodes) attempt to start the [Cluster service](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-service) represents an attempt to form or join a [cluster](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/c-gly), and whether the node has attempted to start this version of the Cluster service before. [Resource DLLs](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-dlls) receive the CLUS_STARTING_PARAMS structure with the [CLUSCTL_RESOURCE_TYPE_STARTING_PHASE1](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-type-starting-phase1) and [CLUSCTL_RESOURCE_TYPE_STARTING_PHASE2](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-type-starting-phase2) control codes.

## Members

### `dwSize`

Byte size of the structure.

### `bForm`

Indicates whether this particular start of the Cluster service represents a form or a join operation.

#### TRUE

The node starting the Cluster service is attempting to form a cluster. No other nodes are currently active.

#### FALSE

The node starting the Cluster service is attempting to join an existing cluster. At least one other node is currently active.

### `bFirst`

Indicates whether this version of the Cluster service has ever started on the node.

#### TRUE

The node is starting a version of the Cluster service for the first time.

#### FALSE

The node has started this version of the Cluster service previously.

## Remarks

The **CLUS_STARTING_PARAMS** structure allows resource DLLs to respond to the CLUSCTL_RESOURCE_TYPE_STARTING_PHASE1 and CLUSCTL_RESOURCE_TYPE_STARTING_PHASE2 control codes based on the circumstances of the start. For example, a DLL might perform special initialization steps when the cluster forms, and perform another set of operations in response to joins.

#### Examples

The following example illustrates an abbreviated implementation of [ResourceTypeControl](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-presource_type_control_routine). For more information, see [Implementing ResourceTypeControl](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/implementing-resourcetypecontrol).

```cpp
const LPWSTR g_MY_RESOURCE_TYPE_NAME[] =
{
    L"MyType_0",
    L"MyType_1",
    L"MyType_2",
    L"MyType_3"
};

DWORD WINAPI MyDllResourceTypeControl(
    IN LPCWSTR ResourceTypeName,
    IN DWORD ControlCode,
    IN PVOID InBuffer,
    IN DWORD InBufferSize,
    OUT PVOID OutBuffer,
    IN DWORD OutBufferSize,
    OUT LPDWORD BytesReturned
)
{
    DWORD status;
    PCLUS_STARTING_PARAMS pStart;

    switch ( ControlCode )
    {
        case CLUSCTL_RESOURCE_TYPE_STARTING_PHASE1:

            if( lstrcmpi( ResourceTypeName, g_MY_RESOURCE_TYPE_NAME[2] ) == 0 )
            {
                pStart = (PCLUS_STARTING_PARAMS) InBuffer;
                if( ( pStart->bForm == TRUE ) &&
                    ( pStart->bFirst == FALSE ) )
                {
                //  Hypothetical initialization code for resource type "MyType_2"
                //  Fires only when the cluster forms, but not for first-time launches of the Cluster service.
                }
            }
            else
            {
                status = ERROR_INVALID_FUNCTION;
            }

            break;

        case CLUSCTL_RESOURCE_TYPE_STARTING_PHASE2:

            pStart = (PCLUS_STARTING_PARAMS) InBuffer;
            if( pStart->bFirst == TRUE )
            {
            //  Hypothetical verification code for all resource types supported by the DLL
            //  Fires for first-time launches of the Cluster service
            }
            else
            {
                status = ERROR_INVALID_FUNCTION;
            }

            break;

    //  case ( Other control codes )....
    //      ...
    //      break;

        default:
            status = ERROR_INVALID_FUNCTION;
            break;

    }
    // end switch

    return( status );

}
// MyDllResourceTypeControl

```

## See also

[CLUSCTL_RESOURCE_TYPE_STARTING_PHASE1](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-type-starting-phase1)

[CLUSCTL_RESOURCE_TYPE_STARTING_PHASE2](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-type-starting-phase2)