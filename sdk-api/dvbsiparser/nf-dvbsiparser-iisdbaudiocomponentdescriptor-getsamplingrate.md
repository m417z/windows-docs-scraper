# IIsdbAudioComponentDescriptor::GetSamplingRate

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

 Gets the value of the sampling_rate field from a an Integrated Services Digital Broadcasting (ISDB) audio component descriptor. This three-bit field contains a code that indicates the sampling frequency.

## Parameters

### `pbVal` [out]

Receives one of the following codes:

| Value | Meaning |
| --- | --- |
| 000 | Reserved for future use. |
| 001 | 16 kHz. |
| 010 | 22.05 kHz. |
| 011 | 24 kHz. |
| 101 | 32 kHz. |
| 110 | 44.1 kHz. |
| 111 | 48 kHz. |

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IIsdbAudioComponentDescriptor](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-iisdbaudiocomponentdescriptor)