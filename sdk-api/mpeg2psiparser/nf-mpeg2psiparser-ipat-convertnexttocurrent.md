# IPAT::ConvertNextToCurrent

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

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

This method applies only to *next* tables that have become current. Before calling this method, call [IPAT::RegisterForWhenCurrent](https://learn.microsoft.com/windows/desktop/api/mpeg2psiparser/nf-mpeg2psiparser-ipat-registerforwhencurrent) and wait for the event to be signaled.

## See also

[IPAT Interface](https://learn.microsoft.com/windows/desktop/api/mpeg2psiparser/nn-mpeg2psiparser-ipat)