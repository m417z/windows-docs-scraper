# _HIDP_DEVICE_DESC structure

## Description

Contains the device description block filled in
collection descriptions as linked lists. This structure is used by [HidP_GetCollectionDescription](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpddi/nf-hidpddi-hidp_getcollectiondescription).

## Members

### `CollectionDesc`

An array of [HIDP_COLLECTION_DESC](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpddi/ns-hidpddi-_hidp_collection_desc) structure that contains the collection descriptors.

### `CollectionDescLength`

The number of elements in the array of the collection descriptors.

### `ReportIDs`

An array of [HIDP_REPORT_IDS](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpddi/ns-hidpddi-_hidp_report_ids) structures report ID information for a report descriptor.

### `ReportIDsLength`

The number of elements in the length of the array of report IDs.

### `Dbg`

A [HIDP_GETCOLDESC_DBG](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpddi/ns-hidpddi-_hidp_getcoldesc_dbg) structure that contains the error code indicating the failure in parsing the report
descriptor.

## See also

[HidP_GetCollectionDescription](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpddi/nf-hidpddi-hidp_getcollectiondescription)