# ITextRangeProvider::GetAttributeValue

## Description

Retrieves the value of the specified text attribute across the text range.

## Parameters

### `attributeId` [in]

Type: **TEXTATTRIBUTEID**

The identifier of the text attribute. For a list of text attribute IDs, see [Text Attribute Identifiers](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-textattribute-ids).

### `pRetVal` [out, retval]

Type: **[VARIANT](https://learn.microsoft.com/windows/desktop/WinAuto/variant-structure)***

Receives one of the following.

* The address of an object representing the value of the specified attribute. The data type of the value varies depending on the specified attribute. For example, if *attributeId* is [UIA_FontNameAttributeId](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-textattribute-ids), **GetAttributeValue** returns a string that represents the font name of the text range, but if *attributeId* is [UIA_IsItalicAttributeId](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-textattribute-ids), **GetAttributeValue** returns a boolean.
* The address of the value retrieved by the [UiaGetReservedMixedAttributeValue](https://learn.microsoft.com/windows/desktop/api/uiautomationcoreapi/nf-uiautomationcoreapi-uiagetreservedmixedattributevalue) function, if the value of the specified attribute varies over the text range.
* The address of the value retrieved by the [UiaGetReservedNotSupportedValue](https://learn.microsoft.com/windows/desktop/api/uiautomationcoreapi/nf-uiautomationcoreapi-uiagetreservednotsupportedvalue) function, if the specified attribute is not supported by the provider or the control.

This parameter is passed uninitialized.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The **GetAttributeValue** method should retrieve the attribute value regardless of whether the text is hidden or visible.

## See also

**Conceptual**

[ITextProvider](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-itextprovider)

[ITextRangeProvider](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-itextrangeprovider)

**Reference**

[UI Automation Providers Overview](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-providersoverview)