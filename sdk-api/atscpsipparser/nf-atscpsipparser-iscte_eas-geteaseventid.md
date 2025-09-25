# ISCTE_EAS::GetEASEventID

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **GetEASEventID** method returns the identifier of this emergency event.

## Parameters

### `pwVal` [out]

Receives the EAS_Event_ID field.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **MPEG2_E_UNINITIALIZED** | The [ISCTE_EAS::Initialize](https://learn.microsoft.com/previous-versions/windows/desktop/api/atscpsipparser/nf-atscpsipparser-iscte_eas-initialize) method was not called. |
| **S_OK** | The method succeeded. |

## See also

[ISCTE_EAS Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/atscpsipparser/nn-atscpsipparser-iscte_eas)