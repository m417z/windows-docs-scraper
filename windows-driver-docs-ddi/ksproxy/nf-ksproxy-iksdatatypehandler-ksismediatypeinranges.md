# IKsDataTypeHandler::KsIsMediaTypeInRanges

## Description

The **KsIsMediaTypeInRanges** method validates that a media type is within the provided data ranges.

## Parameters

### `DataRanges` [in]

Pointer to a buffer that contains a [KSMULTIPLE_ITEM](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksmultiple_item) structure, followed by a sequence of extensible [KSDATARANGE](https://learn.microsoft.com/previous-versions/ff561658(v=vs.85)) structures, aligned on 64-bit boundaries. The KSMULTIPLE_ITEM structure is a header that describes the size of the buffer and the number of entries in the list that follows the header.

## Return value

Returns NOERROR if successful; otherwise, returns an error code.

## Remarks

A client first calls the [IKsDataTypeHandler::KsSetMediaType](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksproxy/nf-ksproxy-iksdatatypehandler-kssetmediatype) method to assign a media type that the client references in subsequent operations on the data type handler. The client then calls **KsIsMediaTypeInRanges** to validate that the media type is within particular data ranges.

## See also

[IKsDataTypeHandler::KsSetMediaType](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksproxy/nf-ksproxy-iksdatatypehandler-kssetmediatype)

[KSDATARANGE](https://learn.microsoft.com/previous-versions/ff561658(v=vs.85))

[KSMULTIPLE_ITEM](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksmultiple_item)