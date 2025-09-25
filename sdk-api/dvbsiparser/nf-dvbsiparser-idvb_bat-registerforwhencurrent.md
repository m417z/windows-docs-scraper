# IDVB_BAT::RegisterForWhenCurrent

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

This topic applies to Update Rollup 2 for Microsoft Windows XP Media Center Edition 2005 and later.

The **RegisterForWhenCurrent** method registers the client to be notified when the table becomes current.

## Parameters

### `hNextTableIsCurrent` [in]

Handle to an event created by the caller. The object signals the event when the table becomes current.

## Return value

The method returns an **HRESULT**. Possible values include those in the following table.

| Return code | Description |
| --- | --- |
| **E_ACCESSDENIED** | This table is already a *current* table. |
| **E_INVALIDARG** | Invalid argument; *hNextTableIsCurrent* cannot be **NULL**. |
| **MPEG2_E_ALREADY_INITIALIZED** | The method has already been called. |
| **S_OK** | The method succeeded. |

## Remarks

This method applies only to *next* tables. Otherwise, the method returns E_ACCESSDENIED.

## See also

[IDVB_BAT Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-idvb_bat)