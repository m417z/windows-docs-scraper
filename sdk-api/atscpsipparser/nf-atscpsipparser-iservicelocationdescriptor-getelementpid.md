# IServiceLocationDescriptor::GetElementPID

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Gets the program ID (PID) that identifies an elementary stream from an Advanced Television Systems Committee (ATSC) Service Location Descriptor.

## Parameters

### `bIndex` [in]

Specifies the elementary stream,
indexed from zero. Call the [IServiceLocationDescriptor::GetNumberOfElements](https://learn.microsoft.com/previous-versions/windows/desktop/api/atscpsipparser/nf-atscpsipparser-iservicelocationdescriptor-getnumberofelements) method to get the number of elementary streams in the descriptor.

### `pwVal` [out]

Receives the PID value for the elementary stream.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IServiceLocationDescriptor](https://learn.microsoft.com/previous-versions/windows/desktop/api/atscpsipparser/nn-atscpsipparser-iservicelocationdescriptor)