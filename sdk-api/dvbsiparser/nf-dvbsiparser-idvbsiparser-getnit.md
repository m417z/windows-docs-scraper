# IDvbSiParser::GetNIT

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

This topic applies to Update Rollup 2 for Microsoft Windows XP Media Center Edition 2005 and later.

The **GetNIT** method retrieves the network information table (NIT).

## Parameters

### `tableId` [in]

Specifies the table identifier of the NIT. Use one of the values in the following table.

| Value | Description |
| --- | --- |
| DVB_NIT_ACTUAL_TID (0x40) | NIT for the network that carries this transport stream. |
| DVB_NIT_OTHER_TID (0x41) | NIT for another network. |

### `pwNetworkId` [in]

Optional parameter that contains a network identifier. You can use this value to filter the request. Otherwise, set this parameter to **NULL**.

### `ppNIT` [out]

Address of a variable that receives an [IDVB_NIT](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-idvb_nit) interface pointer. The caller must release the interface.

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