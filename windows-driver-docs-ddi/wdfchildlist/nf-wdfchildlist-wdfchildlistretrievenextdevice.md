# WdfChildListRetrieveNextDevice function

## Description

[Applies to KMDF only]

The **WdfChildListRetrieveNextDevice** method traverses a specified child list and retrieves the next child device that matches specified criteria.

## Parameters

### `ChildList` [in]

A handle to a framework child-list object.

### `Iterator` [in]

A pointer to the same caller-allocated [WDF_CHILD_LIST_ITERATOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/ns-wdfchildlist-_wdf_child_list_iterator) structure that the driver previously supplied to [WdfChildListBeginIteration](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nf-wdfchildlist-wdfchildlistbeginiteration).

### `Device` [out]

A pointer to a location that receives a handle to a framework device object. The received value is **NULL** if the *Iterator* parameter specifies the [WdfRetrievePendingChildren](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/ne-wdfchildlist-_wdf_retrieve_child_flags) flag.

### `Info` [in, out]

A pointer to a caller-allocated [WDF_CHILD_RETRIEVE_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/ns-wdfchildlist-_wdf_child_retrieve_info) structure. This pointer is optional and can be **NULL**.

## Return value

**WdfChildListRetrieveNextDevice** returns STATUS_SUCCESS, or another status value for which [NT_SUCCESS(status)](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values) equals **TRUE**, if the operation succeeds. Otherwise, this method might return one of the following values:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | An input parameter was invalid. |
| **STATUS_INFO_LENGTH_MISMATCH** | The size of the [WDF_CHILD_LIST_ITERATOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/ns-wdfchildlist-_wdf_child_list_iterator) structure that *Iterator* specified was incorrect |
| **STATUS_INVALID_DEVICE_REQUEST** | An address description was specified but the child list did not contain address descriptions. |
| **STATUS_NO_MORE_ENTRIES** | The framework reached the end of the child list. |
| **STATUS_INVALID_DEVICE_STATE** | The driver has not called [WdfChildListBeginIteration](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nf-wdfchildlist-wdfchildlistbeginiteration). |

This method might also return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

A system bug check occurs if the driver supplies an invalid object handle.

## Remarks

Before calling **WdfChildListRetrieveNextDevice**, your driver must call [WdfChildListBeginIteration](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nf-wdfchildlist-wdfchildlistbeginiteration). After the driver has finished traversing the child list, it must call [WdfChildListEndIteration](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nf-wdfchildlist-wdfchildlistenditeration). The framework then informs the Plug and Play (PnP) manager of any changes that were made to the child list.

Each time the driver calls **WdfChildListRetrieveNextDevice**, the method retrieves the next child that matches the following search criteria:

* The child's type must correspond to [WDF_RETRIEVE_CHILD_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/ne-wdfchildlist-_wdf_retrieve_child_flags)-typed flags in the driver's [WDF_CHILD_LIST_ITERATOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/ns-wdfchildlist-_wdf_child_list_iterator) structure.
* If the driver provides a pointer to an [EvtChildListIdentificationDescriptionCompare](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nc-wdfchildlist-evt_wdf_child_list_identification_description_compare) callback function in its [WDF_CHILD_RETRIEVE_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/ns-wdfchildlist-_wdf_child_retrieve_info) structure, the callback function must return **TRUE**.

If the driver provides an [EvtChildListIdentificationDescriptionCompare](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nc-wdfchildlist-evt_wdf_child_list_identification_description_compare) callback function, it must also provide an [identification description](https://learn.microsoft.com/windows-hardware/drivers/wdf/dynamic-enumeration) in the WDF_CHILD_RETRIEVE_INFO structure. The framework uses the callback function to compare the passed-in identification descriptor with a child's description in the child list, if the WDF_RETRIEVE_CHILD_FLAGS-typed flags indicate that the child is a match candidate. If the callback function returns **TRUE**, the match is successful. If the callback function returns **FALSE**, the framework looks for another candidate.

When **WdfChildListRetrieveNextDevice** finds a match, it copies the child's identification description and address description into the driver's [WDF_CHILD_RETRIEVE_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/ns-wdfchildlist-_wdf_child_retrieve_info) structure, if the pointer that the *Info* parameter specifies is not **NULL**. (Note that this operation overwrites the driver's input identification description.) The method also places a handle to the child's device object in the location that the *Device* parameter identifies.

For more information about child lists, see [Dynamic Enumeration](https://learn.microsoft.com/windows-hardware/drivers/wdf/dynamic-enumeration).

#### Examples

The following code example informs the framework that all of a parent device's children are being ejected. The example obtains a device's default child list and walks through the list. It obtains each child's identification descriptor, and it passes each identification descriptor to [WdfChildListRequestChildEject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nf-wdfchildlist-wdfchildlistrequestchildeject).

```cpp
WDF_CHILD_LIST_ITERATOR  iterator;
WDFDEVICE  hChild;
NTSTATUS  status = STATUS_INVALID_PARAMETER;
WDFCHILDLIST  list;
WDF_CHILD_RETRIEVE_INFO  childInfo;
PDO_IDENTIFICATION_DESCRIPTION  description;
BOOLEAN  ret;

list = WdfFdoGetDefaultChildList(Device);

WDF_CHILD_LIST_ITERATOR_INIT(
                             &iterator,
                             WdfRetrievePresentChildren
                             );
WdfChildListBeginIteration(
                           list,
                           &iterator
                           );
for (;;) {
    WDF_CHILD_RETRIEVE_INFO_INIT(
                                 &childInfo,
                                 &description.Header
                                 );
    WDF_CHILD_IDENTIFICATION_DESCRIPTION_HEADER_INIT(
                                                     &description.Header,
                                                     sizeof(description)
                                                     );
    status = WdfChildListRetrieveNextDevice(
                                            list,
                                            &iterator,
                                            &hChild,
                                            &childInfo
                                            );
    if (!NT_SUCCESS(status) || status == STATUS_NO_MORE_ENTRIES) {
       break;
    }
    ASSERT(childInfo.Status == WdfChildListRetrieveDeviceSuccess);

    ret = WdfChildListRequestChildEject(
                                        list,
                                        &description.Header
                                        );
    if(!ret) {
       WDFVERIFY(ret);
    }
}
WdfChildListEndIteration(
                         list,
                         &iterator
                         );
if (status == STATUS_NO_MORE_ENTRIES) {
   status = STATUS_SUCCESS;
}
return status;
```

## See also

[EvtChildListIdentificationDescriptionCompare](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nc-wdfchildlist-evt_wdf_child_list_identification_description_compare)

[WDF_CHILD_IDENTIFICATION_DESCRIPTION_HEADER_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nf-wdfchildlist-wdf_child_identification_description_header_init)

[WDF_CHILD_LIST_ITERATOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/ns-wdfchildlist-_wdf_child_list_iterator)

[WDF_CHILD_LIST_ITERATOR_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nf-wdfchildlist-wdf_child_list_iterator_init)

[WDF_CHILD_RETRIEVE_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/ns-wdfchildlist-_wdf_child_retrieve_info)

[WDF_RETRIEVE_CHILD_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/ne-wdfchildlist-_wdf_retrieve_child_flags)

[WdfChildListBeginIteration](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nf-wdfchildlist-wdfchildlistbeginiteration)

[WdfChildListBeginScan](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nf-wdfchildlist-wdfchildlistbeginscan)

[WdfChildListEndIteration](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nf-wdfchildlist-wdfchildlistenditeration)

[WdfChildListRequestChildEject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nf-wdfchildlist-wdfchildlistrequestchildeject)

[WdfChildListRetrieveNextDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nf-wdfchildlist-wdfchildlistretrievenextdevice)