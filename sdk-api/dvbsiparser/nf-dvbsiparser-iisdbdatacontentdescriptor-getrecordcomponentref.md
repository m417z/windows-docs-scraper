# IIsdbDataContentDescriptor::GetRecordComponentRef

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

 Gets the value of the component_ref field from a specified component record in an Integrated Services Digital Broadcasting (ISDB) data content descriptor. This field contains the broadcaster-defined component tag that identifies a component stream.

## Parameters

### `bRecordIndex` [in]

Zero-based index of the component record containing the tag. To get the number of components, call [IIsdbDataContentDescriptor::GetCountOfRecords](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nf-dvbsiparser-iisdbtsinformationdescriptor-getcountofrecords).

### `pbVal` [out]

Receives the component tag.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IIsdbDataContentDescriptor](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-iisdbdatacontentdescriptor)