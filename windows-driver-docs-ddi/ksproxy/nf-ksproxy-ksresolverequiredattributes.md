# KsResolveRequiredAttributes function

## Description

The **KsResolveRequiredAttributes** function searches the attributes list that is attached to a data range for specified attributes and ensures that all specified attributes were found.

## Parameters

### `DataRange` [in]

Pointer to a [KSDATARANGE](https://learn.microsoft.com/previous-versions/ff561658(v=vs.85)) structure that possibly has an attached attribute list. **KsResolveRequiredAttributes** searches the data range's attribute list for the attributes at *Attributes*. An attribute list attached to a data range follows that data range.

### `Attributes` [in, optional]

Pointer to a buffer that contains a [KSMULTIPLE_ITEM](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksmultiple_item) structure, followed by a sequence of KSATTRIBUTE structures that describe attributes. The KSMULTIPLE_ITEM structure is a header that describes the size of the buffer and the number of entries in the list that follows the header. If this pointer is **NULL**, then **KsResolveRequiredAttributes** only succeeds if *DataRange* does not have an attached attribute list.

## Return value

Returns NOERROR if successful; otherwise, returns an error code.

## See also

[KSATTRIBUTE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksattribute)

[KSDATARANGE](https://learn.microsoft.com/previous-versions/ff561658(v=vs.85))

[KSMULTIPLE_ITEM](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksmultiple_item)