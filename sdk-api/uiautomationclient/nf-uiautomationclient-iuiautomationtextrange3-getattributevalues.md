# IUIAutomationTextRange3::GetAttributeValues

## Description

Returns all of the requested text attribute values for a text range in a single cross-process call. This is equivalent to calling [GetAttributeValue](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nf-uiautomationclient-iuiautomationtextrange-getattributevalue), except it can retrieve multiple values instead of just one.

## Parameters

### `attributeIds` [in]

A list of [text attribute identifiers](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-textattribute-ids).

### `attributeIdCount` [in]

The number of [text attribute identifiers](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-textattribute-ids) in the *attributeIds* list.

### `attributeValues` [out, retval]

A **SAFEARRAY** of **VARIANT** containing values to corresponding text attributes for a text range.

## Return value

Returns **S_OK** if successful, otherwise an **HRESULT** error code.

## Remarks

**GetAttributeValues** only gets the text attributes that are supplied in the call.

## See also

[IUIAutomationTextRange3](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationtextrange3)

[UI Automation Support for Textual Content](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-ui-automation-textpattern-overview)