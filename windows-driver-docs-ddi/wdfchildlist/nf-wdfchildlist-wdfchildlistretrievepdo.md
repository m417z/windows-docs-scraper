# WdfChildListRetrievePdo function

## Description

[Applies to KMDF only]

The **WdfChildListRetrievePdo** method returns a handle to the framework device object that is associated with a specified child description in a child list.

## Parameters

### `ChildList` [in]

A handle to a child list object.

### `RetrieveInfo` [in, out]

A pointer to a driver-allocated [WDF_CHILD_RETRIEVE_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/ns-wdfchildlist-_wdf_child_retrieve_info) structure that the driver initializes with the [identification description](https://learn.microsoft.com/windows-hardware/drivers/wdf/dynamic-enumeration) of the child to be retrieved.

## Return value

**WdfChildListRetrievePdo** returns a handle to the framework device object if the specified child device is located in the child list, if a framework device object exists for the child device, and if the framework has reported the device's existence to the PnP manager. Otherwise, the method returns **NULL**. The framework returns additional status information in the **Status** member of the [WDF_CHILD_RETRIEVE_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/ns-wdfchildlist-_wdf_child_retrieve_info) structure.

A system bug check occurs if the driver supplies an invalid object handle.

## Remarks

Before calling **WdfChildListRetrievePdo**, the driver must place an identification description in a [WDF_CHILD_RETRIEVE_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/ns-wdfchildlist-_wdf_child_retrieve_info) structure.

The **WdfChildListRetrievePdo** method traverses the specified child list, looking for a child with an identification description that matches the one that the driver supplied in the WDF_CHILD_RETRIEVE_INFO structure. If the framework finds a match, and if the child has an [address description](https://learn.microsoft.com/windows-hardware/drivers/wdf/dynamic-enumeration), the framework fills in the structure's address description.

Be sure to wrap this call with [**WdfChildListBeginIteration**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nf-wdfchildlist-wdfchildlistbeginiteration) and [**WdfChildListEndIteration**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nf-wdfchildlist-wdfchildlistenditeration) to protect the caller from sudden PnP removal of the PDO on another thread.

For more information about child lists, see [Dynamic Enumeration](https://learn.microsoft.com/windows-hardware/drivers/wdf/dynamic-enumeration).

#### Examples

The following code example searches a child list to find a child device whose identification description contains a specified serial number, and it obtains a handle to the device object that represents the child device.

```cpp
WDF_CHILD_LIST_ITERATOR iterator;
PDO_IDENTIFICATION_DESCRIPTION description;
WDF_CHILD_RETRIEVE_INFO info;
WDFDEVICE hChild;

WDF_CHILD_IDENTIFICATION_DESCRIPTION_HEADER_INIT(
                                                 &description.Header,
                                                 sizeof(description)
                                                 );

description.SerialNo = DeviceSerialNumber;

WDF_CHILD_RETRIEVE_INFO_INIT(
                             &info,
                             &description.Header
                             );

WDF_CHILD_LIST_ITERATOR_INIT(&iterator, WdfRetrieveAllChildren);
WdfChildListBeginIteration(childList, &iterator);

hChild = WdfChildListRetrievePdo(
                                 childList,
                                 &info
                                 );

... access hChild ...

WdfChildListEndIteration(childList, &iterator);
```

## See also

[WDF_CHILD_IDENTIFICATION_DESCRIPTION_HEADER_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nf-wdfchildlist-wdf_child_identification_description_header_init)

[WDF_CHILD_RETRIEVE_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/ns-wdfchildlist-_wdf_child_retrieve_info)

[WDF_CHILD_RETRIEVE_INFO_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nf-wdfchildlist-wdf_child_retrieve_info_init)