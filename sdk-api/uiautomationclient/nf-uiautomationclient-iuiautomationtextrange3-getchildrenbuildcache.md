# IUIAutomationTextRange3::GetChildrenBuildCache

## Description

Returns the children and supplied properties and patterns for elements in a text range in a single cross-process call. This is equivalent to calling [GetChildren](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nf-uiautomationclient-iuiautomationtextrange-getchildren), but adds the standard build cache pattern.

## Parameters

### `cacheRequest` [in]

An [IUIAutomationCacheRequest](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationcacherequest) specifying the properties and control patterns to be cached.

### `children` [out, retval]

Returns the children, and each child’s properties or patterns, of the text range that meet the criteria of the supplied *cacheRequest*.

## Return value

Returns **S_OK** if successful, otherwise an **HRESULT** error code.

## Remarks

 Following the design of [GetChildren](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nf-uiautomationclient-iuiautomationtextrange-getchildren):

* Children that overlap with the text range, but are not entirely enclosed by it will also be included.
* When no children exist, an empty collection is returned.

As a result of a successful call, UI Automation clients are able call "Cached" APIs of [IUIAutomationElement](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationelement) that are provided in the *cacheRequest*, for example, [IUIAutomationElement::GetCachedPropertyValue](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nf-uiautomationclient-iuiautomationelement-getcachedpropertyvalue).

## See also

[IUIAutomationTextRange3](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationtextrange3)

[UI Automation Support for Textual Content](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-ui-automation-textpattern-overview)