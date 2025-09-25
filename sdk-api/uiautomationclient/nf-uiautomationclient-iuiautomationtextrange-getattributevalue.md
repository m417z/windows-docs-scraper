# IUIAutomationTextRange::GetAttributeValue

## Description

Retrieves the value of the specified text attribute across the entire text range.

## Parameters

### `attr` [in]

Type: **TEXTATTRIBUTEID**

The identifier of the text attribute. For a list of text attribute IDs, see [Text Attribute Identifiers](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-textattribute-ids).

### `value` [out, retval]

Type: **[VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant)***

Receives the value of the specified attribute.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The type of value retrieved by this method depends on the *attr* parameter.
For example, calling **GetAttributeValue** with the *attr* parameter set to [UIA_FontNameAttributeId](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-textattribute-ids) returns a string that represents the font name of the text range, while calling **GetAttributeValue** with *attr* set to [UIA_IsItalicAttributeId](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-textattribute-ids) would return a boolean.

If the attribute specified by *attr* is not supported, the *value* parameter receives a value that is equivalent to the [IUIAutomation::ReservedNotSupportedValue](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nf-uiautomationclient-iuiautomation-get_reservednotsupportedvalue) property.

A text range can include more than one value for a particular attribute. For example, if a text range includes more than one font, the FontName attribute will have multiple values. An attribute with more than one value is called a *mixed attribute*. You can determine if a particular attribute is a mixed attribute by comparing the value retrieved from **GetAttributeValue** with the [UIAutomation::ReservedMixedAttributeValue](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nf-uiautomationclient-iuiautomation-get_reservedmixedattributevalue) property.

The **GetAttributeValue** method retrieves the attribute value regardless of whether the text is hidden or visible.
Use UIA_ IsHiddenAttributeId to check text visibility.

## See also

[IUIAutomationTextRange](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationtextrange)

[UI Automation Support for Textual Content](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-ui-automation-textpattern-overview)