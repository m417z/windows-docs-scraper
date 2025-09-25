# _HIDP_COLLECTION_DESC structure

## Description

Contains the information of a top-level-collection. This structure is used in the [HidP_GetCollectionDescription](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpddi/nf-hidpddi-hidp_getcollectiondescription) call.

## Members

### `UsagePage`

Specifies the usage page of the usage ID specified by **Usage**.

### `Usage`

Indicates a usage ID.

### `CollectionNumber`

The index of the collection in the array of **HIDP_COLLECTION_DESC** structure. This is a 1-based value.

### `Reserved`

Reserved for internal system use. Must be 0.

### `InputLength`

The maximum length of an input report of this collection.

### `OutputLength`

The maximum length of an output report of this collection.

### `FeatureLength`

The maximum length of a feature report of this collection.

### `PreparsedDataLength`

The length of the preparsed data pointed to by *PreparsedData*.

### `PreparsedData`

A pointer to a [_HIDP_PREPARSED_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidsdi/nf-hidsdi-hidd_getpreparseddata) structure that contains a top-level collection's preparsed data.

## See also

[HidP_GetCollectionDescription](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpddi/nf-hidpddi-hidp_getcollectiondescription)