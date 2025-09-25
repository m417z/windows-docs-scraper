# IIsdbAudioComponentDescriptor::GetStreamType

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Gets a code that indicates the stream type from an Integrated Services Digital Broadcasting (ISDB) audio component descriptor. See Annex E, Table E-4 *SERVICE INFORMATION FOR DIGITAL
BROADCASTING SYSTEM
ARIB STANDARD,
ARIB STD-B10, Version 4.6* for a list of valid stream type codes.

.

## Parameters

### `pbVal` [out]

Receives the stream type code.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IIsdbAudioComponentDescriptor](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-iisdbaudiocomponentdescriptor)