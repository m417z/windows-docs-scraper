# IServiceLocationDescriptor::GetElementStreamType

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Gets a code identifying the type of an elementary stream from an Advanced Television Systems Committee (ATSC) Service Location Descriptor.

## Parameters

### `bIndex` [in]

Specifies the elementary stream,
indexed from zero. Call the [IServiceLocationDescriptor::GetNumberOfElements](https://learn.microsoft.com/previous-versions/windows/desktop/api/atscpsipparser/nf-atscpsipparser-iservicelocationdescriptor-getnumberofelements) method to get the number of elementary streams in the descriptor.

### `pbVal` [out]

Receives the element stream type code. This can be any of the following values:

| Value | Meaning |
| --- | --- |
| 0x00 | ITU-T | ISO/IEC Reserved. |
| 0x01-0x7F | As specified in Table 2.29 (Stream type assignments) of *ITU-T Rec. H.222.0 | ISO/IEC 13818-1:1996, Information Technology Generic coding of moving pictures and associated audio Part 1: Systems (normative)*. |
| 0x80 | [Used in other systems.] |
| 0x81 | ATSC A/53 audio. |
| 0x82-0x84 | [Used in other systems.] |
| 0x85 | UPID that is defined in *ATSC Standard A/57 (1996), Program/Episode/Version Identification (normative).* |
| 0x86-0xBF | Reserved. |
| 0xC0-0xFF | User Private. |

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IServiceLocationDescriptor](https://learn.microsoft.com/previous-versions/windows/desktop/api/atscpsipparser/nn-atscpsipparser-iservicelocationdescriptor)

[IServiceLocationDescriptor::GetNumberOfElements](https://learn.microsoft.com/previous-versions/windows/desktop/api/atscpsipparser/nf-atscpsipparser-iservicelocationdescriptor-getnumberofelements)