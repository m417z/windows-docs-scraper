# RESOURCE_STATUS_EX structure

## Description

Contains information
about a [resource](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resources) that is being brought online or taken offline.
This structure is used as a parameter to the callback function
[SetResourceStatusEx](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-pset_resource_status_routine_ex).

## Members

### `ResourceState`

A [CLUSTER_RESOURCE_STATE](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ne-clusapi-cluster_resource_state) enumeration value that describes the state of the resource.

### `CheckPoint`

A value set by the [resource DLL](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-dlls) to flag a status
report as new.

### `EventHandle`

A handle to an event that indicates when the resource has failed.

### `ApplicationSpecificErrorCode`

TBD

### `Flags`

A bitmask of flags that specify settings for the operation. This member can contain one or more of the following values:

#### CLUSRESDLL_STATUS_OFFLINE_BUSY (0x00000001)

The resource is busy.

#### CLUSRESDLL_STATUS_OFFLINE_SOURCE_THROTTLED (0x00000002)

The source is being throttled.

#### CLUSRESDLL_STATUS_OFFLINE_DESTINATION_THROTTLED (0x00000004)

The destination is being throttled.

#### CLUSRESDLL_STATUS_OFFLINE_DESTINATION_REJECTED (0x00000008)

The destination was rejected.

#### CLUSRESDLL_STATUS_INSUFFICIENT_MEMORY (0x00000010)

There was insufficient memory to perform the operation.

#### CLUSRESDLL_STATUS_INSUFFICIENT_PROCESSOR (0x00000020)

There was insufficient processing resources to perform the operation.

#### CLUSRESDLL_STATUS_INSUFFICIENT_OTHER_RESOURCES (0x00000040)

There was insufficient resources (other than processing or memory resources) to perform the operation.

#### STATUS_INVALID_PARAMETERS (0x00000080)

The [SetResourceStatusEx](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-pset_resource_status_routine_ex) function received invalid parameters.

#### CLUSRESDLL_STATUS_NETWORK_NOT_AVAILABLE (0x00000100)

The network is not available.

**Windows Server 2012:** This value is not supported before Windows Server 2012 R2.

### `WaitHint`

This member is not being used at this time.

**Windows Server 2012:** This member was added in Windows Server 2012 R2.

## See also

[Resource DLL Structures](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-dll-structures)