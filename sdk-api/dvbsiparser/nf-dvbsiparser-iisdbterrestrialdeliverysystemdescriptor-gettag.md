# IIsdbTerrestrialDeliverySystemDescriptor::GetTag

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Gets the tag that identifies an Integrated Digital Services Broadcasting (ISDB) terrestrial delivery system descriptor.

## Parameters

### `pbVal` [out]

Receives the terrestrial delivery system descriptor tag. For terrestrial delivery system descriptors, this value is 0xFA.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IIsdbTerrestrialDeliverySystemDescriptor](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-iisdbterrestrialdeliverysystemdescriptor)