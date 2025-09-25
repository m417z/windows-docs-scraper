# ISCTE_EAS::GetRawAlertText

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Gets the raw alert_text field from the EAS table.

## Parameters

### `pbVal` [out]

A pointer to a buffer that receives the alert_text field. The caller must allocate the buffer. To get the required size of the buffer, call [ISCTE_EAS::GetRawAlertTextLen](https://learn.microsoft.com/previous-versions/windows/desktop/api/atscpsipparser/nf-atscpsipparser-iscte_eas-getrawalerttextlen). The text is formatted as a Multiple String Structure as defined by ATSC PSIP Standard A/65.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

To get the alert text for a specific language, call [ISCTE_EAS::GetAlertText](https://learn.microsoft.com/previous-versions/windows/desktop/api/atscpsipparser/nf-atscpsipparser-iscte_eas-getalerttext).

## See also

[ISCTE_EAS](https://learn.microsoft.com/previous-versions/windows/desktop/api/atscpsipparser/nn-atscpsipparser-iscte_eas)

[ISCTE_EAS::GetAlertText](https://learn.microsoft.com/previous-versions/windows/desktop/api/atscpsipparser/nf-atscpsipparser-iscte_eas-getalerttext)