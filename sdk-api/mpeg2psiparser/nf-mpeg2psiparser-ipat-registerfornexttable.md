# IPAT::RegisterForNextTable

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **RegisterForNextTable** method registers the client to be notified when a *next* table arrives that will replace the current table.

## Parameters

### `hNextTableAvailable` [in]

Handle to an event created by the caller. The object signals the event when the *next* table arrives. When the event is signaled, call the [IPAT::GetNextTable](https://learn.microsoft.com/windows/desktop/api/mpeg2psiparser/nf-mpeg2psiparser-ipat-getnexttable) method to retrieve the table.

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

[IPAT Interface](https://learn.microsoft.com/windows/desktop/api/mpeg2psiparser/nn-mpeg2psiparser-ipat)