# WdfCollectionCreate function

## Description

[Applies to KMDF and UMDF]

The **WdfCollectionCreate** method creates a framework collection object.

## Parameters

### `CollectionAttributes` [in, optional]

A pointer to a caller-allocated [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure that contains attributes for the new collection object. This parameter is optional and can be WDF_NO_OBJECT_ATTRIBUTES.

### `Collection` [out]

A pointer to a location that receives a handle to the new collection object.

## Return value

**WdfCollectionCreate** returns STATUS_SUCCESS if the operation succeeds. Otherwise, this method might return one of the following values:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | The caller supplied an invalid parameter value. |
| **STATUS_INSUFFICIENT_RESOURCES** | A collection object could not be allocated. |

This method might also return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

## Remarks

After calling **WdfCollectionCreate** to create a framework collection object, a driver can call [WdfCollectionAdd](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfcollection/nf-wdfcollection-wdfcollectionadd) to add objects to the collection.

By default, the new collection object's parent is the framework driver object that the [WdfDriverCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nf-wdfdriver-wdfdrivercreate) method created. You can use the **ParentObject** member of the [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure to specify a different parent. The framework deletes the collection object when it deletes the parent object. If your driver does not change the default parent, the driver should delete the collection object when it has finished using the object; otherwise, the object will remain until the I/O manager unloads your driver.

For more information about object collections, see [Framework Object Collections](https://learn.microsoft.com/windows-hardware/drivers/wdf/framework-object-collections).

#### Examples

For a code example that uses **WdfCollectionCreate**, see [WdfCollectionAdd](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfcollection/nf-wdfcollection-wdfcollectionadd).

## See also

[WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes)

[WdfCollectionAdd](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfcollection/nf-wdfcollection-wdfcollectionadd)

[WdfCollectionRemove](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfcollection/nf-wdfcollection-wdfcollectionremove)

[WdfDriverCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nf-wdfdriver-wdfdrivercreate)