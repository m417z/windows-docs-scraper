# _STORAGE_LB_PROVISIONING_MAP_RESOURCES structure

## Description

The **STORAGE_LB_PROVISIONING_MAP_RESOURCES** structure contains, when valid, the count of available and used bytes mapped to a storage device. This structure is returned from an [IOCTL_STORAGE_GET_LB_PROVISIONING_MAP_RESOURCES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_get_lb_provisioning_map_resources) request.

## Members

### `Size`

The size of this structure. This is set to **sizeof**(STORAGE_LB_PROVISIONING_MAP_RESOURCES).

### `Version`

The version of this structure.

### `AvailableMappingResourcesValid`

The validity of the **AvailableMappingResources** member.

| Value | Meaning |
| --- | --- |
| 0 | **AvailableMappingResources** is not valid. |
| 1 | **AvailableMappingResources** is valid. |

### `UsedMappingResourcesValid`

The validity of the **UsedMappingResources** member.

| Value | Meaning |
| --- | --- |
| 0 | **UsedMappingResources** is not valid. |
| 1 | **UsedMappingResources** is valid. |

### `Reserved0`

Reserved.

### `Reserved1`

Reserved.

### `AvailableMappingResourcesScope`

Resources scope available to a LUN or a LUN pool.

| Value | Meaning |
| --- | --- |
| **LOG_PAGE_LBP_RESOURCE_SCOPE_NOT_REPORTED**<br><br>0 | Mapping resources are not reported. |
| **LOG_PAGE_LBP_RESOURCE_SCOPE_DEDICATED_TO_LUN**<br><br>1 | Mapping resources dedicated to a LUN. |
| **LOG_PAGE_LBP_RESOURCE_SCOPE_NOT_DEDICATED_TO_LUN**<br><br>2 | Mapping resources dedicated to a LUN pool. |

### `UsedMappingResourcesScope`

Resources scope used by a LUN or LUN pool.

| Value | Meaning |
| --- | --- |
| **LOG_PAGE_LBP_RESOURCE_SCOPE_NOT_REPORTED**<br><br>0 | Mapping resources are not reported. |
| **LOG_PAGE_LBP_RESOURCE_SCOPE_DEDICATED_TO_LUN**<br><br>1 | Mapping resources dedicated to a LUN. |
| **LOG_PAGE_LBP_RESOURCE_SCOPE_NOT_DEDICATED_TO_LUN**<br><br>2 | Mapping resources dedicated to a LUN pool. |

### `Reserved2`

Reserved.

### `Reserved3`

Reserved.

### `AvailableMappingResources`

The count, in bytes, of the available mapping resources for a disk.

### `UsedMappingResources`

The count, in bytes, of the used mapping resources for a disk.

## Remarks

As a managed storage element, resource usage for a thinly provisioned LUN is tracked. Resource allocation is logged for the device by the storage subsystem. A storage application can query for this resource usage information using the  [IOCTL_STORAGE_GET_LB_PROVISIONING_MAP_RESOURCES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_get_lb_provisioning_map_resources) request.

Logging of mapped resource counts is dependent on support from the storage device. The **AvailableMappingResources** and **UsedMappingResources** members contain resource counts when their respective validity fields are set.

Resource counts are in bytes instead of totals of blocks or slabs.

## See also

 [IOCTL_STORAGE_GET_LB_PROVISIONING_MAP_RESOURCES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_get_lb_provisioning_map_resources)