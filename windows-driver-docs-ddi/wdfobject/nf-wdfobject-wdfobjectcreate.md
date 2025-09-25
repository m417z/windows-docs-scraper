# WdfObjectCreate function

## Description

[Applies to KMDF and UMDF]

The **WdfObjectCreate** method creates a general framework object.

## Parameters

### `Attributes` [in, optional]

A pointer to a [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure that contains driver-supplied attributes for the new object. This parameter is optional and can be WDF_NO_OBJECT_ATTRIBUTES.

### `Object` [out]

A pointer to a location that receives a handle to the new framework object.

## Return value

**WdfObjectCreate** returns STATUS_SUCCESS if the operation succeeds. For a list of additional return values, see [Framework Object Creation Errors](https://learn.microsoft.com/windows-hardware/drivers/wdf/framework-object-creation-errors).

This method might also return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

## Remarks

By default, the new general framework object's parent is the framework driver object that the [WdfDriverCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nf-wdfdriver-wdfdrivercreate) method created. You can use the **ParentObject** member of the [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure to specify a different parent. The framework deletes the general object when it deletes the parent object. If your driver does not change the default parent, the driver should delete the general object when it has finished using the object; otherwise, the object will remain until the I/O manager unloads your driver.

For more information about the **WdfObjectCreate** method, see [Using General Framework Objects](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-general-framework-objects).

For more information about the cleanup rules for a framework object hierarchy, see [Framework Object Life Cycle](https://learn.microsoft.com/windows-hardware/drivers/wdf/framework-object-life-cycle).

#### Examples

The following code example initializes an WDF_OBJECT_ATTRIBUTES structure and creates a general framework object.

```cpp
WDF_OBJECT_ATTRIBUTES  Attributes;
WDFOBJECT  Object;

WDF_OBJECT_ATTRIBUTES_INIT(&Attributes);
status = WdfObjectCreate(
                         &Attributes,
                         &Object
                         );
```

## See also

[WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes)

[WDF_OBJECT_ATTRIBUTES_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/nf-wdfobject-wdf_object_attributes_init)

[WdfDriverCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nf-wdfdriver-wdfdrivercreate)

[WdfObjectDelete](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/nf-wdfobject-wdfobjectdelete)