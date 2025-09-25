# WdfLookasideListCreate function

## Description

[Applies to KMDF only]

The **WdfLookasideListCreate** method creates a lookaside-list object, from which the driver can obtain memory objects.

## Parameters

### `LookasideAttributes` [in, optional]

A pointer to a [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure that contains object attributes for the new lookaside-list object. This parameter is optional and can be WDF_NO_OBJECT_ATTRIBUTES.

### `BufferSize` [in]

The nonzero size, in bytes, of the buffer that the framework will allocate for each memory object.

### `PoolType` [in]

A [POOL_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_pool_type)-typed value that specifies the type of memory to be allocated.

### `MemoryAttributes` [in, optional]

A pointer to a [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure that contains object attributes for each memory object that the driver obtains from the lookaside list. This parameter is optional and can be WDF_NO_OBJECT_ATTRIBUTES.

### `PoolTag` [in, optional]

A driver-defined pool tag for each memory object's buffer. Debuggers display this tag. Drivers typically specify a character string of up to four characters, delimited by single quotation marks, in reverse order (for example, 'dcba'). The ASCII value of each character in the tag must be between 0 and 127. Debugging your driver is easier if each pool tag is unique.

If *PoolTag* is zero, the framework provides a default pool tag that uses the first four characters of your driver's kernel-mode service name. If the service name begins with "WDF" (the name is not case sensitive and does not include the quotation marks), the next four characters are used. If fewer than four characters are available, "FxDr" is used.

For KMDF versions 1.5 and later, your driver can use the **DriverPoolTag** member of the [WDF_DRIVER_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/ns-wdfdriver-_wdf_driver_config) structure to specify a default pool tag.

### `Lookaside` [out]

A pointer to a location that receives a handle to the new lookaside-list object.

## Return value

**WdfLookasideListCreate** returns STATUS_SUCCESS if the operation succeeds. Otherwise, this method might return one of the following values:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | An invalid parameter was detected. |
| **STATUS_INSUFFICIENT_RESOURCES** | There was insufficient memory. |

For a list of other return values that the **WdfLookasideListCreate** method might return, see [Framework Object Creation Errors](https://learn.microsoft.com/windows-hardware/drivers/wdf/framework-object-creation-errors).

This method also might return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

## Remarks

After your driver calls **WdfLookasideListCreate** to create a lookaside-list object, the driver can call [WdfMemoryCreateFromLookaside](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfmemory/nf-wdfmemory-wdfmemorycreatefromlookaside) to obtain a buffer from the lookaside list.

By default, the new lookaside-list object's parent is the framework driver object that the [WdfDriverCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nf-wdfdriver-wdfdrivercreate) method creates. You can use the **ParentObject** member of the [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure to specify a different parent. The framework deletes the lookaside-list object when it deletes the parent object. If your driver does not change the default parent, the driver should delete the lookaside-list object when it has finished using the object; otherwise, the lookaside-list object will remain until the I/O manager unloads your driver.

If your driver supplies a WDF_OBJECT_ATTRIBUTES structure for both the *LookasideAttributes* and the *MemoryAttributes* parameters, and if both structures specify a device object as the parent object, the device object handles must be the same.

For more information about framework memory objects and lookaside lists, see [Using Memory Buffers](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-memory-buffers).

If your driver specifies **PagedPool** for the *PoolType* parameter, the **WdfLookasideListCreate** method must be called at IRQL <= APC_LEVEL. Otherwise, the method can be called at IRQL <= DISPATCH_LEVEL.

#### Examples

For a code example that uses **WdfLookasideListCreate**, see [WdfMemoryCreateFromLookaside](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfmemory/nf-wdfmemory-wdfmemorycreatefromlookaside).

## See also

[WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes)

[WdfDriverCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nf-wdfdriver-wdfdrivercreate)

[WdfMemoryCreateFromLookaside](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfmemory/nf-wdfmemory-wdfmemorycreatefromlookaside)