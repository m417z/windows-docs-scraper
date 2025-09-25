# WdfMemoryCreateFromLookaside function

## Description

[Applies to KMDF only]

The **WdfMemoryCreateFromLookaside** method creates a framework memory object and obtains a memory buffer from a specified lookaside list.

## Parameters

### `Lookaside` [in]

A handle to a framework lookaside-list object that is obtained by calling [WdfLookasideListCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfmemory/nf-wdfmemory-wdflookasidelistcreate).

### `Memory` [out]

A pointer to a location that receives a handle to the new framework memory object.

## Return value

**WdfMemoryCreateFromLookaside** returns STATUS_SUCCESS if the operation succeeds. Otherwise, this method return one of the following values:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | An invalid parameter was detected. |
| **STATUS_INSUFFICIENT_RESOURCES** | There was insufficient memory. |

This method also might return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

After your driver calls [WdfLookasideListCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfmemory/nf-wdfmemory-wdflookasidelistcreate) to create a lookaside-list object, the driver can call **WdfMemoryCreateFromLookaside** to obtain a buffer from the lookaside list.

The framework provides a handle to a memory object that represents the buffer. When the framework creates the memory object, it uses object attributes that the driver supplied when it called **WdfMemoryCreateFromLookaside**.

When your driver has finished using a memory object that it obtained from a lookaside list, the driver must call [WdfObjectDelete](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/nf-wdfobject-wdfobjectdelete) to return the memory object to the lookaside list.

For more information about framework memory objects and lookaside lists, see [Using Memory Buffers](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-memory-buffers).

If lookaside-list buffers are being allocated from the pageable memory pool, the **WdfMemoryCreateFromLookaside** method must be called at IRQL <= APC_LEVEL. Otherwise, the method can be called at IRQL <= DISPATCH_LEVEL.

#### Examples

The following code example creates a lookaside list and stores the list's handle in driver-defined device object context space. Then, the driver obtains a buffer from the lookaside list.

```cpp
PDRIVER_CONTEXT  driverContext;
WDFMEMORY  memHandle;

driverContext = GetDriverContext(driver);

status = WdfLookasideListCreate(
                                WDF_NO_OBJECT_ATTRIBUTES,
                                sizeof(MY_LOOKASIDE_BUFFER),
                                NonPagedPool,
                                WDF_NO_OBJECT_ATTRIBUTES,
                                MY_POOL_TAG,
                                &driverContext->LookasideListHandle
                                );
...
status = WdfMemoryCreateFromLookaside(
                                      driverContext->LookasideListHandle,
                                      &memHandle
                                      );
```

## See also

[WdfLookasideListCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfmemory/nf-wdfmemory-wdflookasidelistcreate)

[WdfMemoryCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfmemory/nf-wdfmemory-wdfmemorycreate)

[WdfMemoryCreatePreallocated](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfmemory/nf-wdfmemory-wdfmemorycreatepreallocated)

[WdfObjectDelete](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/nf-wdfobject-wdfobjectdelete)