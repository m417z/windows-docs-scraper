# WdfCollectionAdd function

## Description

[Applies to KMDF and UMDF]

The **WdfCollectionAdd** method adds a specified framework object to an object collection.

## Parameters

### `Collection` [in]

A handle to a collection object.

### `Object` [in]

A handle to the framework object that will be added to the collection.

## Return value

**WdfCollectionAdd** returns STATUS_SUCCESS if the operation succeeds. Otherwise, this method might return one of the following values:

| Return code | Description |
| --- | --- |
| **STATUS_UNSUCCESSFUL** | The specified object could not be added to the specified collection. |

This method might also return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

The **WdfCollectionAdd** method appends the specified object to the end of the set of objects that the collection contains. When **WdfCollectionAdd** adds an object to a collection, it increments the object's reference count. Your driver can call [WdfCollectionRemove](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfcollection/nf-wdfcollection-wdfcollectionremove) or [WdfCollectionRemoveItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfcollection/nf-wdfcollection-wdfcollectionremoveitem) to remove the object and decrement its reference count.

For more information about object collections, see [Framework Object Collections](https://learn.microsoft.com/windows-hardware/drivers/wdf/framework-object-collections).

#### Examples

The following code example creates a collection object and then adds a set of driver-created request objects to the collection.

```cpp
WDF_OBJECT_ATTRIBUTES  attributes;
NTSTATUS  status;
WDFCOLLECTION  hCollection = NULL;
WDFREQUEST  subRequest = NULL;

WDF_OBJECT_ATTRIBUTES_INIT(&attributes);
attributes.ParentObject = Request;
status = WdfCollectionCreate(
                             &attributes,
                             &hCollection
                             );
if (!NT_SUCCESS(status)) {
    goto Exit;
}

for (i = 0; i < numSubRequests; i++) {
    WDF_OBJECT_ATTRIBUTES_INIT(&attributes);
    WDF_OBJECT_ATTRIBUTES_SET_CONTEXT_TYPE(
                                           &attributes,
                                           SUB_REQUEST_CONTEXT
                                           );
    status = WdfRequestCreate(
                              &attributes,
                              WdfUsbTargetDeviceGetIoTarget(deviceContext->WdfUsbTargetDevice),
                              &subRequest
                              );
    if (!NT_SUCCESS(status)) {
        goto Exit;
    }
    status = WdfCollectionAdd(
                              hCollection,
                              subRequest
                              );
    if (!NT_SUCCESS(status)) {
        WdfObjectDelete(subRequest);
        goto Exit;
    }
}
```

## See also

[WdfCollectionCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfcollection/nf-wdfcollection-wdfcollectioncreate)

[WdfCollectionRemove](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfcollection/nf-wdfcollection-wdfcollectionremove)

[WdfCollectionRemoveItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfcollection/nf-wdfcollection-wdfcollectionremoveitem)