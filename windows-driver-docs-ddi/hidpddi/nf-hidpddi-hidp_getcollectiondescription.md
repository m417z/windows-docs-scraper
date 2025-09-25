# HidP_GetCollectionDescription function

## Description

Fills a device description
block with collection description and the corresponding
report ID information for the specified report descriptor.
A HID minidriver generally does not need to call this function. Instead, it returns the report descriptor to Hidclass driver in response to [IOCTL_HID_GET_REPORT_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidport/ni-hidport-ioctl_hid_get_report_descriptor).

## Parameters

### `ReportDesc` [in]

A pointer to a UCHAR array that contains the raw report descriptor.

### `DescLength` [in]

The length of the report descriptor array.

### `PoolType` [in]

A [POOL_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_pool_type)-value that indicates the pool type from which memory for the linked list is allocated. This includes each [HIDP_COLLECTION_DESC](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpddi/ns-hidpddi-_hidp_collection_desc) array element of [HIDP_DEVICE_DESC](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpddi/ns-hidpddi-_hidp_device_desc), each [HIDP_PREPARSED_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidsdi/nf-hidsdi-hidd_getpreparseddata) in each **HIDP_COLLECTION_DESC**, each [HIDP_REPORT_IDS](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpddi/ns-hidpddi-_hidp_report_ids) array element of **HIDP_DEVICE_DESC**.

### `DeviceDescription` [out]

A pointer to a [HIDP_DEVICE_DESC](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpddi/ns-hidpddi-_hidp_device_desc) structure that is populated with device description block filled in
collection descriptors as linked lists. This is a caller-allocated structure. However, its [HIDP_COLLECTION_DESC](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpddi/ns-hidpddi-_hidp_collection_desc) array elements and [HIDP_REPORT_IDS](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpddi/ns-hidpddi-_hidp_report_ids) array elements are allocated by this function.

## Return value

**HidP_GetCollectionDescription** can return one of these values: **TRUE** if it successfully fills the device description block. Otherwise, it returns **FALSE**.

| Return value | Description |
| --- | --- |
| STATUS_SUCCESS | Successfully parsed the report descriptor and allocated the memory blocks necessary to describe the device. |
| STATUS_NO_DATA_DETECTED | Failed to find top-level collections in the report descriptor. |
| STATUS_COULD_NOT_INTERPRET | An error was detected in the report descriptor. See the error code in **Dbg** field of the [HIDP_DEVICE_DESC](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpddi/ns-hidpddi-_hidp_device_desc) structure. |
| STATUS_BUFFER_TOO_SMALL | Found the end of the report descriptor when it expected more data. |
| STATUS_INSUFFICIENT_RESOURCES | Failed to allocate memory. |
| STATUS_ILLEGAL_INSTRUCTION | Failed to parse an item in the report descriptor. |
| HIDP_STATUS_INVALID_REPORT_TYPE | Report ID of 0 was found in the descriptor. |

## Remarks

 For a raw report descriptor that is specified by the *ReportDesc* parameter, *HidP_GetCollectionDescription* fills in the *DeviceDescription*
block with a caller-allocated linked list of collection descriptors and the corresponding
Report ID information that is described by the given report descriptor.
The memory for the collection information and the ReportID information is
allocated based on the *PoolType* value.