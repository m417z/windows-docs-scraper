# IUIAutomationTextRange::FindAttribute

## Description

Retrieves a text range subset that has the specified text attribute value.

## Parameters

### `attr` [in]

Type: **TEXTATTRIBUTEID**

The identifier of the text attribute for the text range subset being retrieved. For a list of text attribute IDs, see [Text Attribute Identifiers](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-textattribute-ids).

### `val` [in]

Type: **[VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant)**

The value of the attribute. This value must match the type specified for the attribute.

### `backward` [in]

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

**TRUE** if the last occurring text range should be returned instead of the first; otherwise **FALSE**.

### `found` [out, retval]

Type: **[IUIAutomationTextRange](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationtextrange)****

Receives a pointer to the text range having a matching attribute and attribute value; otherwise **NULL**.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The **FindAttribute** method retrieves matching text regardless of whether the text is hidden or visible. Use [UIA_IsHiddenAttributeId](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-textattribute-ids) to check text visibility.

## See also

[IUIAutomationTextRange](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationtextrange)

[UI Automation Support for Textual Content](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-ui-automation-textpattern-overview)