# IMpeg2Data::GetTable

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

[**GetTable** is no longer available for use as of Windows7. Instead, use the [IPSITables](https://learn.microsoft.com/windows/desktop/api/mpeg2psiparser/nn-mpeg2psiparser-ipsitables) interface to get program specific information (PSI) tables from an MPEG-2 transport stream.]

Retrieves a complete MPEG-2 PSI table. This method blocks until the filter receives all of the sections that make up the requested table, or until the specified time out elapses.

## Parameters

### `pid` [in]

Specifies the packet identifier (PID) of the transport stream packets to examine.

### `tid` [in]

Specifies the table identifier (TID) of the section to retrieve.

### `pFilter` [in]

Optional pointer to an [MPEG2_FILTER](https://learn.microsoft.com/previous-versions/windows/desktop/api/mpeg2structs/ns-mpeg2structs-mpeg2_filter) structure. The caller can use this parameter to exclude packets based on additional MPEG-2 header fields. This parameter can be **NULL**.

### `dwTimeout` [in]

Specifies a time-out value, in milliseconds. If the filter does not receive a matching section within the time-out period, the method fails.

### `ppSectionList` [out]

Receives an [ISectionList](https://learn.microsoft.com/previous-versions/windows/desktop/api/mpeg2data/nn-mpeg2data-isectionlist) interface pointer. Use this interface to retrieve the section data. The caller must release the interface.

## Return value

The method returns an **HRESULT**. Possible values include those in the following table.

| Return code | Description |
| --- | --- |
| **MPEG2_E_SECTION_NOT_FOUND** | The filter did not receive a matching table section. |
| **S_OK** | The method succeeded. |

## Remarks

You can use the *pFilter* parameter to specify the Table_ID_extension field or the version number field. Otherwise, the filter caches these values from the first section that matches the search criteria. It uses those values to match subsequent sections.

## See also

[IMpeg2Data Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/mpeg2data/nn-mpeg2data-impeg2data)