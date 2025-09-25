# IIsdbDataContentDescriptor::GetEntryComponent

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

 Gets the value of the entry_component field from an Integrated Services Digital Broadcasting (ISDB) data content descriptor. This field indicates the first component stream that is referenced in the descriptor.

## Parameters

### `pbVal` [out]

Returns the entry_component field value.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IIsdbDataContentDescriptor](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-iisdbdatacontentdescriptor)