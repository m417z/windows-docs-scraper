# PcNewResourceSublist function

## Description

The **PcNewResourceSublist** function creates and initializes an empty resource list that is derived from another resource list.

## Parameters

### `OutResourceList` [out]

Output pointer to the resource-list object that this function creates. This parameter points to the caller-allocated pointer variable into which the function outputs the pointer to the [IResourceList](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iresourcelist) object. Specify a valid, non-**NULL** pointer value for this parameter.

### `OuterUnknown` [in, optional]

Pointer to the [IUnknown](https://learn.microsoft.com/windows/win32/api/unknwn/nn-unknwn-iunknown) interface of an object that needs to aggregate the object. Unless aggregation is required, set this parameter to **NULL**.

### `PoolType` [in]

Specifies the type of pool from which the object is to be allocated. This is a [POOL_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_pool_type) enumeration value.

### `ParentList` [in]

Pointer to the resource list from which the child list will be created. The resource list has an [IResourceList](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iresourcelist) interface.

### `MaximumEntries` [in]

Specifies the maximum number of entries that will be added to the resource list.

## Return value

**PcNewResourceSublist** returns STATUS_SUCCESS if the call was successful. Otherwise, it returns an appropriate error code.

## Remarks

This function creates an empty resource sublist.

An adapter driver typically uses the **PcNewResourceSublist** function in combination with the [IResourceList::AddEntryFromParent](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iresourcelist-addentryfromparent) method to take the original list of resources that it received from the system and divide them up into sublists that it assigns to its various subdevices.

The *OutResourceList*, *OuterUnknown*, and *ParentList* parameters follow the [reference-counting conventions for COM objects](https://learn.microsoft.com/windows-hardware/drivers/audio/reference-counting-conventions-for-com-objects).

## See also

[IResourceList](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iresourcelist)

[IResourceList::AddEntryFromParent](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iresourcelist-addentryfromparent)

[POOL_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_pool_type)