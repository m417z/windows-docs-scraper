# IMpeg2Data::GetStreamOfSections

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

[**GetStreamOfSections** is no longer available for use as of Windows7. Instead, use the [IPSITables](https://learn.microsoft.com/windows/desktop/api/mpeg2psiparser/nn-mpeg2psiparser-ipsitables) interface to get program specific information (PSI) tables from an MPEG-2 transport stream.]

The **GetStreamOfSections** method starts an ongoing request for specific MPEG-2 table sections.

## Parameters

### `pid` [in]

Specifies the packet identifier (PID) of the transport stream packets to examine.

### `tid` [in]

Specifies the table identifier (TID) of the section to retrieve.

### `pFilter` [in]

Optional pointer to an [MPEG2_FILTER](https://learn.microsoft.com/previous-versions/windows/desktop/api/mpeg2structs/ns-mpeg2structs-mpeg2_filter) structure. The caller can use this parameter to exclude packets based on additional MPEG-2 header fields. This parameter can be **NULL**.

### `hDataReadyEvent` [in]

Handle to an event created by the caller. The filter signals this event whenever it receives new data.

### `ppMpegStream` [out]

Pointer to a variable that receives an [IMpeg2Stream](https://learn.microsoft.com/previous-versions/windows/desktop/api/mpeg2data/nn-mpeg2data-impeg2stream) interface pointer. The caller must release the interface. Use this interface to retrieve the data when it arrives.

## Return value

The method returns an **HRESULT**. Possible values include those in the following table.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | Invalid argument. |
| **E_POINTER** | **NULL** pointer argument. |
| **S_OK** | The method succeeded. |

## See also

[IMpeg2Data Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/mpeg2data/nn-mpeg2data-impeg2data)