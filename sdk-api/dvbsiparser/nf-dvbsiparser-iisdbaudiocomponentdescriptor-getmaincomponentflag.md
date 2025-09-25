# IIsdbAudioComponentDescriptor::GetMainComponentFlag

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Gets a flag from an Integrated Services Digital Broadcasting (ISDB) audio component descriptor that indicates whether the audio component is the main audio.

## Parameters

### `pfVal` [out]

Receives 1 if the audio component is the main audio or 0 if it is not. In ES simulcast mode, receives 1 if the first audio component is the main audio or 0 if it is not.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IIsdbAudioComponentDescriptor](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-iisdbaudiocomponentdescriptor)