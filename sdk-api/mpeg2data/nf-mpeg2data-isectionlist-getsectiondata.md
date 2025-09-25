# ISectionList::GetSectionData

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **GetSectionData** method retrieves a section.

## Parameters

### `sectionNumber` [in]

Specifies the section number to retrieve, indexed from zero. Call the **GetNumberOfSections** method to get the number of sections.

### `pdwRawPacketLength` [out]

Receives the size of the section data, in bytes.

### `ppSection` [out]

Address of a variable that receives a pointer to a **SECTION** structure, containing the section data. Do not free the memory for the structure; the object frees the memory when the interface is released.

## Return value

The method returns an **HRESULT**. Possible values include those in the following table.

| Return code | Description |
| --- | --- |
| **E_ACCESSDENIED** | The request has not completed yet. |
| **E_POINTER** | NULL pointer argument. |
| **MPEG2_E_OUT_OF_BOUNDS** | The section number is out of range. |
| **S_OK** | The method succeeded. |

## Remarks

The section header is converted from network byte order to native byte order. The number of header bytes that are converted depends on the header type. The header types are *short header* ([SECTION](https://learn.microsoft.com/previous-versions/windows/desktop/api/mpeg2structs/ns-mpeg2structs-section) structure), *long header* ([LONG_SECTION](https://learn.microsoft.com/previous-versions/windows/desktop/api/mpeg2structs/ns-mpeg2structs-long_section) structure), or *DSM-CC header* ([DSMCC_SECTION](https://learn.microsoft.com/previous-versions/windows/desktop/api/mpeg2structs/ns-mpeg2structs-dsmcc_section) structure). If the section has a short header, the first three bytes are converted; for a long header, the first eight bytes are converted; and for a DSM-CC header, the first 20 bytes are converted.

The body of the section data, after the header, is left unparsed and unconverted.

## See also

[ISectionList Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/mpeg2data/nn-mpeg2data-isectionlist)