# IResourceList::TranslatedList

## Description

The `TranslatedList` method returns the list of translated resources.

## Return value

`TranslatedList` returns a pointer to a [CM_RESOURCE_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_cm_resource_list) structure that specifies all of the system hardware resources that are assigned to the device. This pointer remains valid until the resource list object is deleted.

## See also

[CM_RESOURCE_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_cm_resource_list)

[IResourceList](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iresourcelist)