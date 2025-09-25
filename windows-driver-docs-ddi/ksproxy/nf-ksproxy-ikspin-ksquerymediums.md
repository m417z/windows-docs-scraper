# IKsPin::KsQueryMediums

## Description

The **KsQueryMediums** method retrieves mediums that a pin supports.

## Parameters

### `MediumList` [out]

Pointer to a buffer that receives a pointer to a [KSMULTIPLE_ITEM](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksmultiple_item) structure, followed by a sequence of [KSPIN_MEDIUM](https://learn.microsoft.com/windows-hardware/drivers/stream/kspin-medium-structure) structures that describe medium types. The KSMULTIPLE_ITEM structure is a header that describes the size of the buffer and the number of entries in the list that follows the header.

## Return value

Returns NOERROR if successful; otherwise, returns an error code.

## Remarks

The returned mediums are ordered by preference.

Applications call **KsQueryMediums** to retrieve mediums that pins support in order to build a filter graph.

## See also

[KSMULTIPLE_ITEM](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksmultiple_item)

[KSPIN_MEDIUM](https://learn.microsoft.com/windows-hardware/drivers/stream/kspin-medium-structure)