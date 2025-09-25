# ICaptionServiceDescriptor::GetNumberOfServices

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

This topic applies to Update Rollup 2 for Microsoft Windows XP Media Center Edition 2005 and later.

The **GetNumberOfServices** method returns the number of caption services.

## Parameters

### `pbVal` [out]

Receives the number of caption services.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **MPEG2_E_INCORRECT_DESCRIPTOR_TAG** | The table descriptor tag is incorrect. |
| **MPEG2_E_MALFORMED_TABLE** | The PSIP table is not well formed. |

## See also

[ICaptionServiceDescriptor Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/atscpsipparser/nn-atscpsipparser-icaptionservicedescriptor)