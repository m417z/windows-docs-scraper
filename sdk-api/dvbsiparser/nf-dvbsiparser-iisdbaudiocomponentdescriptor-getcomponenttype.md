# IIsdbAudioComponentDescriptor::GetComponentType

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Gets the value of the component_type field from an Integrated Services Digital Broadcasting (ISDB) audio component descriptor. This field identifies the audio component type.

## Parameters

### `pbVal` [out]

Receives the component_type field value. See Table 6-43 in Section 6.2.26, *SERVICE INFORMATION FOR DIGITAL
BROADCASTING SYSTEM
ARIB STANDARD,
ARIB STD-B10, Version 4.6* for a list of valid component type codes.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IIsdbAudioComponentDescriptor](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-iisdbaudiocomponentdescriptor)