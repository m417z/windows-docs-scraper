# IResourceList::FindTranslatedEntry

## Description

The `FindTranslatedEntry` method returns a pointer to a translated entry of the specified type, or **NULL** if no such entry is found.

## Parameters

### `Type` [in]

Identifies the resource type of the entry to find. For a list of valid resource-type values, see the **Type** member of the [CM_PARTIAL_RESOURCE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_cm_partial_resource_descriptor) structure.

### `Index` [in]

Specifies the index of the entry to find. If the [IResourceList::NumberOfEntriesOfType](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iresourcelist-numberofentriesoftype) method returns a value *n* for the number of entries of type *Type*, valid indices range from 0 to *n*-1. If *Index* is zero, for example, the method returns a pointer to the translated version of the first occurrence of an entry of the specified type from the resource list.

## Return value

`FindTranslatedEntry` returns a pointer to the specified entry or is **NULL** if the entry does not exist. This pointer remains valid until the resource list object is deleted.

## Remarks

For each resource type, a macro is defined to call this method. See [IResourceList](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iresourcelist).

The *Index* parameter indicates which occurrence of an entry of the specified type to find in the list of translated resource entries. The first occurrence in the list has an index of zero.

For each resource type, a macro is defined to call this method. See [IResourceList](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iresourcelist).

For more information about translated and untranslated (or "raw") resources, see [CM_PARTIAL_RESOURCE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_cm_partial_resource_descriptor).

## See also

[CM_PARTIAL_RESOURCE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_cm_partial_resource_descriptor)

[IResourceList](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iresourcelist)

[IResourceList::FindUntranslatedEntry](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iresourcelist-finduntranslatedentry)

[IResourceList::NumberOfEntriesOfType](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iresourcelist-numberofentriesoftype)