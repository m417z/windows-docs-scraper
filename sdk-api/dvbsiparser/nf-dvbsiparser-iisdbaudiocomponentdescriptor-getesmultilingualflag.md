# IIsdbAudioComponentDescriptor::GetESMultiLingualFlag

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Gets a flag from an Integrated Services Digital Broadcasting (ISDB) audio component descriptor that indicates whether the stream uses ES multilingual mode.

## Parameters

### `pfVal` [out]

Receives 1 if the stream uses ES multilingual mode.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

ES multilingual mode (also called *2-language multilingual mode* or *1/0 + 1/0 mode*) is a dual-channel monaural mode indicated by a value of 0x02 in the component_type field of the descriptor.

## See also

[IIsdbAudioComponentDescriptor](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-iisdbaudiocomponentdescriptor)