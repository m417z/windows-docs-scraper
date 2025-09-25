# IResourceList::AddEntry

## Description

The `AddEntry` method adds an entry to a resource list.

## Parameters

### `Translated` [in]

Pointer to a translated version of the entry. This parameter points to a [CM_PARTIAL_RESOURCE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_cm_partial_resource_descriptor) structure containing the translated version of the entry to be added.

### `Untranslated` [in]

Pointer to an untranslated version of the entry. This parameter points to a CM_PARTIAL_RESOURCE_DESCRIPTOR structure containing the untranslated (or "raw") version of the entry to be added.

## Return value

`AddEntry` returns STATUS_SUCCESS if the call was successful. Otherwise, the method returns an appropriate error code. The following table shows some of the possible return status codes.

| Return code | Description |
| --- | --- |
| **STATUS_INSUFFICIENT_RESOURCES** | Indicates there are no free entries in the list. |

## See also

[CM_PARTIAL_RESOURCE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_cm_partial_resource_descriptor)

[IResourceList](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iresourcelist)