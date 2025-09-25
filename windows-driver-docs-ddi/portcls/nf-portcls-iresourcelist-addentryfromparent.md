# IResourceList::AddEntryFromParent

## Description

The `AddEntryFromParent` method adds to a resource list an entry found in the resource list's parent list.

## Parameters

### `Parent` [in]

Pointer to parent **IResourceList** object from which the entry is to be taken.

### `Type` [in]

Identifies the resource type of the entry that is to be added. For a list of valid resource-type values, see the description of the **Type** member of the [CM_PARTIAL_RESOURCE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_cm_partial_resource_descriptor) structure.

### `Index` [in]

Specifies the index in the parent list of the entry to add. If the parent's [IResourceList::NumberOfEntriesOfType](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iresourcelist-numberofentriesoftype) method returns a value *n* for the number of entries of type *Type*, valid indices range from 0 to *n*-1. If *Index* is zero, for example, the method adds the first occurrence of an entry of the specified type from the parent list.

## Return value

`AddEntryFromParent` returns STATUS_SUCCESS if the call was successful. Otherwise, the method returns an appropriate error code. The following table shows some of the possible return status codes.

| Return code | Description |
| --- | --- |
| **STATUS_INSUFFICIENT_RESOURCES** | Indicates there are no free entries in the list. |
| **STATUS_INVALID_PARAMETER** | Indicates the entry was not found in the parent list. |

## Remarks

For each resource type, a macro is defined to call this method. See [IResourceList](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iresourcelist).

The *Parent* parameter follows the [reference-counting conventions for COM objects](https://learn.microsoft.com/windows-hardware/drivers/audio/reference-counting-conventions-for-com-objects).

## See also

[CM_PARTIAL_RESOURCE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_cm_partial_resource_descriptor)

[IResourceList](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iresourcelist)

[IResourceList::NumberOfEntriesOfType](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iresourcelist-numberofentriesoftype)