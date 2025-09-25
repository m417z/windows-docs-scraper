# IDvbSiParser2::GetEIT2

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **GetEIT2** method gets the event information table (EIT).

## Parameters

### `tableId` [in]

Specifies the table identifier of the EIT. Use one of the following values.

| Value | Meaning |
| --- | --- |
| **DVB_EIT_ACTUAL_TID**<br><br>0x4E | Present/following EIT for this transport stream. |
| **DVB_EIT_OTHER_TID**<br><br>0x4F | Present/following EIT for another transport stream. |
| 0x50 0x5F | Schedule EIT for this transport stream. |
| 0x60 0x6F | Schedule EIT for another transport stream. |

### `pwServiceId` [in]

An optional parameter that contains a service identifier. You can use this value to filter the request. Otherwise, set this parameter to **NULL**.

### `pbSegment` [in]

An optional parameter that contains a segment number. You can use this value to filter the request. Otherwise, set this parameter to **NULL**.

### `ppEIT` [out]

Receives a pointer to the [IDVB_EIT2](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-idvb_eit2) interface. The caller must release the interface.

## Return value

The method returns an **HRESULT**. Possible values include those in the following table.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | Invalid argument. |
| **E_POINTER** | NULL pointer argument. |
| **MPEG2_E_SECTION_NOT_FOUND** | The filter did not receive the table in the allotted time. |
| **S_OK** | The method succeeded. |

## Remarks

The method fails if the filter does not receive a matching table within a predetermined length of time.

## See also

[IDvbSiParser2](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-idvbsiparser2)