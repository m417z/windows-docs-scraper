# IIsdbAudioComponentDescriptor::GetQualityIndicator

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

 Gets the value of the quality_indicator field from an Integrated Services Digital Broadcasting (ISDB) audio component descriptor. This two-bit field indicates the tone quality mode.

## Parameters

### `pbVal` [out]

Receives one of the following values:

| Value | Meaning |
| --- | --- |
| 00 | Reserved for future use. |
| 01 | Mode 1. |
| 10 | Mode 2. |
| 11 | Mode 3. |

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IIsdbAudioComponentDescriptor](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-iisdbaudiocomponentdescriptor)