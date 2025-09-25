# _HIDP_REPORT_IDS structure

## Description

Contains report ID information for a top-level collection.

## Members

### `ReportID`

The report ID of the top-level collection.

### `CollectionNumber`

The index of the collection in the array of [HIDP_COLLECTION_DESC](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpddi/ns-hidpddi-_hidp_collection_desc) structure.

### `InputLength`

The length of an input report of this report ID.

### `OutputLength`

The length of an output report of this report ID. An input report, an output report, and a feature report can use the same report.

### `FeatureLength`

The length of a feature report of this report ID.

## See also

[HidP_GetCollectionDescription](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpddi/nf-hidpddi-hidp_getcollectiondescription)