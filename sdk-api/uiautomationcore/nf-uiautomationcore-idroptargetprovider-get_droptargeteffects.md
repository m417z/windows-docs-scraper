# IDropTargetProvider::get_DropTargetEffects

## Description

Retrieves an array of localized strings that enumerate the full set of effects that can happen when the user drops a grabbed element on this drop target as part of a drag-and-drop operation.

This property is read-only.

## Parameters

## Remarks

Some drag operations support a set of different drop effects. For example, a drag operation that is initiated with a right-click might display a menu of options for the action that occurs when the element is dropped. To find out the set of effects that can happen when the grabbed element is dropped, a client can query the [DropEffects](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nf-uiautomationcore-idragprovider-get_dropeffects) property of the dragged element. This property can contain short strings such as "move", or longer ones such as "insert into Main group". The strings are always localized.

## See also

[IDropTargetProvider](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-idroptargetprovider)