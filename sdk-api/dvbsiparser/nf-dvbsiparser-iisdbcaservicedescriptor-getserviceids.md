# IIsdbCAServiceDescriptor::GetServiceIds

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Gets the service identifier (ID) records from a conditional access (CA) service descriptor.

## Parameters

### `pbNumServiceIds` [in, out]

On input specifies the expected number of service ID records. On output returns the actual number of records.

### `pwServiceIds` [out]

Receives the service ID records.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IIsdbCAServiceDescriptor](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-iisdbcaservicedescriptor)