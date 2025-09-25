# IResourceList::NumberOfEntriesOfType

## Description

The `NumberOfEntriesOfType` method returns the number of resource items of a given type in the resource list. For each resource type, a macro is defined to call this method as previously described.

## Parameters

### `Type` [in]

Identifies the resource type of the entries that are to be counted. For a list of valid resource-type values, see the **Type** member of the [CM_PARTIAL_RESOURCE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_cm_partial_resource_descriptor) structure.

## Return value

`NumberOfEntriesOfType` returns the number of items of the indicated type in the resource list.

## Remarks

For each resource type, a macro is defined to call this method. See [IResourceList](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iresourcelist).

## See also

[CM_PARTIAL_RESOURCE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_cm_partial_resource_descriptor)

[IResourceList](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iresourcelist)