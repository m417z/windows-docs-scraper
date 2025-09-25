# ITextRangeProvider::FindAttribute

## Description

Returns a text range subset that has the specified text attribute value.

## Parameters

### `attributeId` [in]

Type: **TEXTATTRIBUTEID**

The identifier of the text attribute. For a list of text attribute IDs, see [Text Attribute Identifiers](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-textattribute-ids).

### `val` [in]

Type: **[VARIANT](https://learn.microsoft.com/windows/desktop/WinAuto/variant-structure)**

The attribute value to search for. This value must match the type specified for the attribute.

### `backward` [in]

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

**TRUE** if the last occurring text range should be returned instead of the first; otherwise **FALSE**.

### `pRetVal` [out, retval]

Type: **[ITextRangeProvider](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-itextrangeprovider)****

Receives a pointer to the text range having a matching attribute and attribute value; otherwise **NULL**.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The **FindAttribute** method retrieves matching text regardless of whether the text is hidden or visible. Clients can use [UIA_IsHiddenAttributeId](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-textattribute-ids) to check text visibility.

## See also

**Conceptual**

[ITextProvider](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-itextprovider)

[ITextRangeProvider](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-itextrangeprovider)

**Reference**

[UI Automation Providers Overview](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-providersoverview)