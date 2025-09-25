# ISCTE_EAS::GetNatureOfActivationText

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **GetNatureOfActivationText** method gets a textual representation of the alert for a specified ISO 639 language code.

## Parameters

### `bstrIS0639code` [in]

The ISO 639 language code.

### `pbstrString` [out]

Receives the text as a **BSTR**. The caller must free the string by calling **SysFreeString**.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_FAIL** | The specified language is not present. |

## Remarks

The returned string is taken from the nature_of_activation_text field, as defined by ANSI-J-STD-042-A.

**Note**An earlier version of the documentation gave an incorrect signature for this method.

## See also

[ISCTE_EAS Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/atscpsipparser/nn-atscpsipparser-iscte_eas)