# PcNewResourceList function

## Description

The **PcNewResourceList** function creates and initializes a resource list.

## Parameters

### `OutResourceList` [out]

Output pointer for the resource-list object created by this function. This parameter points to a caller-allocated pointer variable into which the function outputs the pointer to the [IResourceList](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iresourcelist) object. Specify a valid, non-**NULL** pointer value for this parameter.

### `OuterUnknown` [in, optional]

Pointer to the [IUnknown](https://learn.microsoft.com/windows/win32/api/unknwn/nn-unknwn-iunknown) interface of an object that needs to aggregate the resource-list object. Unless aggregation is required, set this parameter to **NULL**.

### `PoolType` [in]

Specifies the type of pool from which the object is to be allocated. This is a [POOL_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_pool_type) enumeration value.

### `TranslatedResources` [in]

Pointer to a WDM-supplied resource list for translated resources. The list is a system structure of type [CM_RESOURCE_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_cm_resource_list).

### `UntranslatedResources` [in]

Pointer to a WDM-supplied resource list for untranslated resources. The list is a system structure of type [CM_RESOURCE_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_cm_resource_list).

## Return value

**PcNewResourceList** returns STATUS_SUCCESS if the call was successful. Otherwise, it returns an appropriate error code.

## Remarks

For a discussion of translated and untranslated (or "raw") resource lists, see [Mapping Bus-Relative Addresses to Virtual Addresses](https://learn.microsoft.com/windows-hardware/drivers/kernel/mapping-bus-relative-addresses-to-virtual-addresses).

The *OutResourceList* and *OuterUnknown* parameters follow the [reference-counting conventions for COM objects](https://learn.microsoft.com/windows-hardware/drivers/audio/reference-counting-conventions-for-com-objects).

## See also

[CM_RESOURCE_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_cm_resource_list)

[IResourceList](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iresourcelist)

[POOL_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_pool_type)