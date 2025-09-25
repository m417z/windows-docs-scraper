# IMpeg2Stream::Initialize

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **Initialize** method initializes the **MPEG2Stream** object. This method should be called once, immediately after creating the object. The [IMpeg2Data::GetStreamOfSections](https://learn.microsoft.com/previous-versions/windows/desktop/api/mpeg2data/nf-mpeg2data-impeg2data-getstreamofsections) method calls this method internally, so typically an application will not call it.

## Parameters

### `requestType` [in]

Specifies the request type, as an [MPEG_REQUEST_TYPE](https://learn.microsoft.com/previous-versions/windows/desktop/api/mpeg2structs/ne-mpeg2structs-mpeg_request_type) value.

### `pMpeg2Data` [in]

Pointer to the [IMpeg2Data](https://learn.microsoft.com/previous-versions/windows/desktop/api/mpeg2data/nn-mpeg2data-impeg2data) interface of the MPEG-2 Sections and Tables filter.

### `pContext` [in]

Pointer to an [MPEG_CONTEXT](https://learn.microsoft.com/previous-versions/windows/desktop/api/mpeg2structs/ns-mpeg2structs-mpeg_context) structure. This structure indicates the MPEG-2 source.

### `pid` [in]

Specifies a packet identifier (PID), indicating which packets in the transport stream are requested.

### `tid` [in]

Specifies a table identifier (TID), indicating which table sections to retrieve.

### `pFilter` [in]

Optional pointer to an [MPEG2_FILTER](https://learn.microsoft.com/previous-versions/windows/desktop/api/mpeg2structs/ns-mpeg2structs-mpeg2_filter) structure. The caller can use this parameter to exclude packets based on additional MPEG-2 header fields. This parameter can be **NULL**.

### `hDataReadyEvent` [in]

Handle to an event. The filter signals this event whenever it receives new data.

## Return value

The method returns an **HRESULT**. Possible values include those in the following table.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | Invalid or **NULL** pointer argument. |
| **E_OUTOFMEMORY** | Insufficient memory. |
| **MPEG2_E_ALREADY_INITIALIZED** | The method has been called on this object already. |
| **S_OK** | The method succeeded. |

## See also

[IMpeg2Stream Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/mpeg2data/nn-mpeg2data-impeg2stream)