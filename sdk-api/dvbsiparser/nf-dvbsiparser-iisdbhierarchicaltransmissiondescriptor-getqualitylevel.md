# IIsdbHierarchicalTransmissionDescriptor::GetQualityLevel

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Gets the value of the quality_flag field from an Integrated Services Digital Broadcasting (ISDB) hierarchical transmission descriptor. This field indicates the quality level of the hierarchical stream construction.

## Parameters

### `pbVal` [out]

Receives the quality_flag field value. A value of 1 indicates a high-quality stream; a value of 0 indicates a low-quality stream.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IIsdbHierarchicalTransmissionDescriptor](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-iisdbhierarchicaltransmissiondescriptor)