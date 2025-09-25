# IIsdbCADescriptor::GetPrivateDataBytes

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Gets the private data bytes from a conditional access (CA) descriptor.

## Parameters

### `pbBufferLength` [in, out]

On input, specifies the length of the private data being retrieved, in bytes. On output, returns the actual data length.

### `pbBuffer` [out]

Receives the conditional access private data.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IIsdbCADescriptor](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-iisdbcadescriptor)