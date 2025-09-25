# ISectionList::InitializeWithRawSections

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **InitializeWithRawSections** method initializes the object with raw section data. This method allows for custom processing of section data.

## Parameters

### `pmplSections` [in]

Pointer to an [MPEG_PACKET_LIST](https://learn.microsoft.com/previous-versions/windows/desktop/api/mpeg2structs/ns-mpeg2structs-mpeg_packet_list) structure that contains a list of MPEG-2 sections.

## Return value

The method returns an **HRESULT**. Possible values include those in the following table.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | Invalid argument. |
| **MPEG2_E_ALREADY_INITIALIZED** | The object has already been initialized. |
| **S_OK** | The method succeeded. |

## Remarks

Use this method as follows:

1. Get the section data by calling the [IMpeg2Data::GetStreamOfSections](https://learn.microsoft.com/previous-versions/windows/desktop/api/mpeg2data/nf-mpeg2data-impeg2data-getstreamofsections) method.
2. Create a new **SectionList** object and call **InitializeWithRawSections** with the section data.

## See also

[ISectionList Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/mpeg2data/nn-mpeg2data-isectionlist)