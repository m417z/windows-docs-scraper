# IDVB_SDT::ConvertNextToCurrent

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

This topic applies to Update Rollup 2 for Microsoft Windows XP Media Center Edition 2005 and later.

The **ConvertNextToCurrent** method converts a *next* table to a *current* table.

## Return value

The method returns an **HRESULT**. Possible values include those in the following table.

| Return code | Description |
| --- | --- |
| **E_ACCESSDENIED** | This table is already current. |
| **E_INVALIDARG** | The **RegisterForWhenCurrent** method was not called. |
| **MPEG2_E_MALFORMED_TABLE** | The new *current* table is malformed. |
| **S_OK** | The method succeeded. |

## Remarks

This method applies only to *next* tables that have become current. Before calling this method, call [IDVB_SDT::RegisterForWhenCurrent](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nf-dvbsiparser-idvb_sdt-registerforwhencurrent) and wait for the event to be signaled.

## See also

[IDVB_SDT Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-idvb_sdt)