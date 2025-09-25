# IDvbSiParser::GetSDT

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

This topic applies to Update Rollup 2 for Microsoft Windows XP Media Center Edition 2005 and later.

The **GetSDT** method retrieves the service description table (SDT).

## Parameters

### `tableId` [in]

Specifies the table identifier of the SDT. Use one of the values in the following table.

| Value | Description |
| --- | --- |
| DVB_SDT_ACTUAL_TID (0x42) | SDT for the current transport stream. |
| DVB_SDT_OTHER_TID (0x46) | SDT for another transport stream. |

### `pwTransportStreamId` [in]

Optional parameter that contains a transport stream identifier (TSID). You can use this value to filter the request. Otherwise, set this parameter to **NULL**.

### `ppSDT` [out]

Address of a variable that receives an [IDVB_SDT](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-idvb_sdt) interface pointer. The caller must release the interface.

## Return value

The method returns an **HRESULT**. Possible values include those in the following table.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | Invalid argument. |
| **E_POINTER** | **NULL** pointer argument. |
| **MPEG2_E_SECTION_NOT_FOUND** | The filter did not receive the table in the allotted time. |
| **S_OK** | The method succeeded. |

## Remarks

The method fails if the filter does not receive a matching table within a predetermined length of time.

## See also

[IDvbSiParser Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-idvbsiparser)