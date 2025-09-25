# IDvbComponentDescriptor::GetComponentType

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Gets the component type code for a Digital Video Broadcast (DVB) component descriptor.

## Parameters

### `pbVal` [out]

Receives the component type code.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

For a list of component types associated with the value returned in the *pbVal* parameter, see Table 26 in Section 6.2.9 of the DVB standards document,
*Digital Video Broadcasting Specification for Service Information (SI) in DVB systems*. (This resource may not be available in some languages

and countries.)

## See also

[IDvbComponentDescriptor](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-idvbcomponentdescriptor)