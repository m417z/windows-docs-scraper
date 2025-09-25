# IDvbSiParser::GetDIT

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

This topic applies to Update Rollup 2 for Microsoft Windows XP Media Center Edition 2005 and later.

The **GetDIT** method retrieves the discontinuity information table (DIT).

## Parameters

### `dwTimeout` [in]

Specifies a time-out value, in milliseconds. If the filter does not receive the data within the time-out period, the method fails.

### `ppDIT` [out]

Address of a variable that receives an [IDVB_DIT](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-idvb_dit) interface pointer. The caller must release the interface.

## Return value

The method returns an **HRESULT**. Possible values include those in the following table.

| Return code | Description |
| --- | --- |
| **E_POINTER** | NULL pointer argument. |
| **MPEG2_E_SECTION_NOT_FOUND** | The filter did not receive the table in the allotted time. |
| **S_OK** | The method succeeded. |

## See also

[IDvbSiParser Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-idvbsiparser)