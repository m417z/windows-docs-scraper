# IIsdbSIParameterDescriptor::GetTableDescriptionBytes

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Gets description data from a table descriptor in a service information (SI) parameter descriptor.

## Parameters

### `bRecordIndex` [in]

Zero-based index of the SI table descriptor. To get the number of table descriptors, call the [IIsdbSIParameterDescriptor::GetRecordNumberOfTable](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nf-dvbsiparser-iisdbsiparameterdescriptor-getrecordnumberoftable) method.

### `pbBufferLength` [in, out]

On input specifies the length of the table descriptor data that is retrieved, in bytes. On output returns the actual data length.

### `pbBuffer` [out]

Receives the table descriptor data.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IIsdbSIParameterDescriptor](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-iisdbsiparameterdescriptor)

[IIsdbSIParameterDescriptor::GetRecordNumberOfTable](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nf-dvbsiparser-iisdbsiparameterdescriptor-getrecordnumberoftable)