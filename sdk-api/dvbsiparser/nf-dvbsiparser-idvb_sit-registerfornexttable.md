# IDVB_SIT::RegisterForNextTable

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

This topic applies to Update Rollup 2 for Microsoft Windows XP Media Center Edition 2005 and later.

The **RegisterForNextTable** method registers the client to be notified when a *next* table arrives that will replace the current table.

## Parameters

### `hNextTableAvailable` [in]

Handle to an event created by the caller. The object signals the event when the *next* table arrives. When the event is signaled, call the [IDVB_SIT::GetNextTable](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nf-dvbsiparser-idvb_sit-getnexttable) method to retrieve the table.

## Return value

The method returns an **HRESULT**. Possible values include those in the following table.

| Return code | Description |
| --- | --- |
| **E_ACCESSDENIED** | This table is already a *next* table. |
| **E_INVALIDARG** | Invalid argument; *hNextTableAvailable* cannot be **NULL**. |
| **MPEG2_E_ALREADY_INITIALIZED** | The method has already been called. |
| **S_OK** | The method succeeded. |

## Remarks

This method applies only to *current* tables. Otherwise, the method returns E_ACCESSDENIED.

## See also

[IDVB_SIT Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-idvb_sit)