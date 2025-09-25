# IAtscPsipParser::GetEIT

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

This topic applies to Update Rollup 2 for Microsoft Windows XP Media Center Edition 2005 and later.

The **GetEIT** method retrieves the event information table (EIT).

## Parameters

### `pid` [in]

Specifies the packet identifier (PID) for the requested EIT.

### `pwSourceId` [in]

Optional pointer to a variable that contains a table source identifier. You can use this value to filter the request. Otherwise, set this parameter to **NULL**.

### `dwTimeout` [in]

Specifies a time-out value, in milliseconds. If the filter does not receive the data within the time-out period, the method fails.

### `ppEIT` [out]

Receives an [IATSC_EIT](https://learn.microsoft.com/previous-versions/windows/desktop/api/atscpsipparser/nn-atscpsipparser-iatsc_eit) interface pointer. The caller must release the interface.

## Return value

The method returns an **HRESULT**. Possible values include those in the following table.

| Return code | Description |
| --- | --- |
| **E_OUTOFMEMORY** | Insufficient memory. |
| **E_POINTER** | **NULL** pointer argument. |
| **MPEG2_E_SECTION_NOT_FOUND** | The filter did not receive the table in the allotted time. |
| **MPEG2_E_UNINITIALIZED** | The **Initialize** method was not called. |
| **S_OK** | The method succeeded. |

## See also

[IAtscPsipParser Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/atscpsipparser/nn-atscpsipparser-iatscpsipparser)