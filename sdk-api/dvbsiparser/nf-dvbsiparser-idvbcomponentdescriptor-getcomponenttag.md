# IDvbComponentDescriptor::GetComponentTag

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Gets the component tag from a DVB component descriptor. The component tag has the same value as the component_tag field in the stream identifier descriptor in the Program Specific Information (PSI) program map section for the component stream.

## Parameters

### `pbVal` [out]

Receives the component tag.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDvbComponentDescriptor](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-idvbcomponentdescriptor)