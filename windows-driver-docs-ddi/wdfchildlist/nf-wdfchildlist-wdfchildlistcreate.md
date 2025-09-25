# WdfChildListCreate function

## Description

[Applies to KMDF only]

The **WdfChildListCreate** method creates a child list for a specified parent device.

## Parameters

### `Device` [in]

A handle to a framework device object that represents the parent device.

### `Config` [in]

A pointer to a [WDF_CHILD_LIST_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/ns-wdfchildlist-_wdf_child_list_config) structure that contains driver-supplied configuration information for the child list.

### `ChildListAttributes` [in, optional]

A pointer to a [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure that contains driver-supplied object attributes for the framework child-list object. (The structure's **ParentObject** member must be **NULL**.)

### `ChildList` [out]

A pointer to a caller-allocated location that receives a handle to a framework child-list object.

## Return value

**WdfChildListCreate** returns STATUS_SUCCESS, or another status value for which [NT_SUCCESS(status)](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values) equals **TRUE**, if the operation succeeds. Otherwise, this method might return one of the following values:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | An input parameter was invalid. |
| **STATUS_INSUFFICIENT_RESOURCES** | An object could not be allocated. |

This method might also return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

A system bug check occurs if the driver supplies an invalid object handle.

## Remarks

The framework creates a default child list for each framework device object that represents a functional device object (FDO). To use the default child list, the driver calls [WdfFdoGetDefaultChildList](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdffdo/nf-wdffdo-wdffdogetdefaultchildlist). If your driver requires additional child lists, it can call **WdfChildListCreate** to create them.

The parent of each child-list object is the device's framework device object. The driver cannot change this parent, and the **ParentObject** member or the [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure must be **NULL**.

Your driver cannot delete the child-list object that **WdfChildListCreate** creates. The framework deletes the object at the proper time.

For more information about child lists, see [Dynamic Enumeration](https://learn.microsoft.com/windows-hardware/drivers/wdf/dynamic-enumeration).

#### Examples

The following code example initializes a [WDF_CHILD_LIST_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/ns-wdfchildlist-_wdf_child_list_config) structure and then calls **WdfChildListCreate**.

```cpp
WDF_CHILD_LIST_CONFIG listConfig;

WDF_CHILD_LIST_CONFIG_INIT(
                           &listConfig,
                           sizeof(PDO_IDENTIFICATION_DESCRIPTION),
                           My_EvtDeviceListCreatePdo
                           );

listConfig.AddressDescriptionSize = sizeof(PDO_ADDRESS_DESCRIPTION);

listConfig.EvtChildListScanForChildren = My_EvtChildListScanForChildren;

listConfig.EvtChildListIdentificationDescriptionDuplicate = My_EvtChildListIdentificationDescriptionDuplicate;
listConfig.EvtChildListIdentificationDescriptionCompare = My_EvtChildListIdentificationDescriptionCompare;
listConfig.EvtChildListIdentificationDescriptionCleanup = My_EvtChildListIdentificationDescriptionCleanup;

status = WdfChildListCreate(
                            device,
                            &listConfig,
                            WDF_NO_OBJECT_ATTRIBUTES,
                            &ParentDeviceContext->ChildList
                            );
if (!NT_SUCCESS(status)) {
    return status;
}
```

## See also

[WDF_CHILD_LIST_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/ns-wdfchildlist-_wdf_child_list_config)

[WDF_CHILD_LIST_CONFIG_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nf-wdfchildlist-wdf_child_list_config_init)

[WdfFdoGetDefaultChildList](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdffdo/nf-wdffdo-wdffdogetdefaultchildlist)