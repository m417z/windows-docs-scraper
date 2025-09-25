# IUIAutomationDragPattern::get_CachedDropEffects

## Description

Retrieves a cached array of localized strings that enumerate the full set of effects that can happen when the user drops this element as part of a drag-and-drop operation.

This property is read-only.

## Parameters

## Remarks

Some drag operations support a set of different drop effects. For example, a drag operation that is initiated with a right-click might display a menu of options for the action that occurs when the element is dropped. In the source-only style of Microsoft UI Automation drag-and-drop, no elements implement the [DropTarget](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-implementingdroptarget) pattern. To find out the set of effects that can happen when the grabbed element is dropped, a client can query the [DropEffects](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nf-uiautomationcore-idragprovider-get_dropeffects) property of the dragged element. This property can contain short strings such as "move", or longer ones such as "insert into Main group". The strings are always localized.

## See also

[IUIAutomationDragPattern](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationdragpattern)