# IServiceLocationDescriptor::GetPCR_PID

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Gets the program ID (PID) for the packets that contain the Program Clock Reference (PCR) in the transport stream from an Advanced Television Systems Committee (ATSC) Service Location Descriptor.

## Parameters

### `pwVal` [out]

Receives the PID value.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IServiceLocationDescriptor](https://learn.microsoft.com/previous-versions/windows/desktop/api/atscpsipparser/nn-atscpsipparser-iservicelocationdescriptor)