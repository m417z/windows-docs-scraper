# IUIAutomationTextRange3::GetEnclosingElementBuildCache

## Description

Gets the enclosing element and supplied properties and patterns for an element in a text range in a single cross-process call. This is equivalent to calling [GetEnclosingElement](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nf-uiautomationclient-iuiautomationtextrange-getenclosingelement), but adds the standard build cache pattern.

## Parameters

### `cacheRequest` [in]

An [IUIAutomationCacheRequest](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationcacherequest) specifying the properties and control patterns to be cached.

### `enclosingElement` [out, retval]

Returns the enclosing element (and properties/patterns) of the text range if it meets the criteria of the supplied *cacheRequest*.

## Return value

Returns **S_OK** if successful, otherwise an **HRESULT** error code.

## Remarks

Following the design of [GetEnclosingElement](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nf-uiautomationclient-iuiautomationtextrange-getenclosingelement):

* Gets the all-inclusive, innermost enclosing element of a text range and the supplied properties of the element.

As a result of a successful call, UI Automation clients are able call "Cached" APIs of [IUIAutomationElement](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationelement) that are provided in the *cacheRequest*, for example, [IUIAutomationElement::GetCachedPropertyValue](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nf-uiautomationclient-iuiautomationelement-getcachedpropertyvalue).

## See also

[IUIAutomationTextRange3](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationtextrange3)

[UI Automation Support for Textual Content](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-ui-automation-textpattern-overview)