# ISCTE_EAS::GetEASEventCode

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **GetEASEventCode** method returns the EAS event code.

## Parameters

### `pbVal` [out]

A pointer to a buffer that receives the EAS_event_code field. The caller must allocate the buffer, which must be large enough to hold the event code. To get the required size of the buffer, call [ISCTE_EAS::GetEASEventCodeLen](https://learn.microsoft.com/previous-versions/windows/desktop/api/atscpsipparser/nf-atscpsipparser-iscte_eas-geteaseventcodelen). The event code consists of ASCII characters.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **MPEG2_E_UNINITIALIZED** | The [ISCTE_EAS::Initialize](https://learn.microsoft.com/previous-versions/windows/desktop/api/atscpsipparser/nf-atscpsipparser-iscte_eas-initialize) method was not called. |
| **S_OK** | The method succeeded. |

## See also

[GetEASEventCodeLen](https://learn.microsoft.com/previous-versions/windows/desktop/api/atscpsipparser/nf-atscpsipparser-iscte_eas-geteaseventcodelen)

[ISCTE_EAS Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/atscpsipparser/nn-atscpsipparser-iscte_eas)