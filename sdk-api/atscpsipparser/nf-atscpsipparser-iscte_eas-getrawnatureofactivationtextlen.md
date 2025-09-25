# ISCTE_EAS::GetRawNatureOfActivationTextLen

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Gets the length of the nature_of_activation_text field.

## Parameters

### `pbVal` [out]

Receives the size of the nature_of_activation_text field, in bytes. To get the value of the field, allocate a buffer of this size and call [ISCTE_EAS::GetRawNatureOfActivationText](https://learn.microsoft.com/previous-versions/windows/desktop/api/atscpsipparser/nf-atscpsipparser-iscte_eas-getrawnatureofactivationtext).

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ISCTE_EAS](https://learn.microsoft.com/previous-versions/windows/desktop/api/atscpsipparser/nn-atscpsipparser-iscte_eas)

[ISCTE_EAS::GetNatureOfActivationText](https://learn.microsoft.com/previous-versions/windows/desktop/api/atscpsipparser/nf-atscpsipparser-iscte_eas-getnatureofactivationtext)