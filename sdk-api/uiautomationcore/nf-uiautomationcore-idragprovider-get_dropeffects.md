# IDragProvider::get_DropEffects

## Description

Retrieves an array of localized strings that enumerate the full set of effects that can happen when this element is dropped as part of a drag-and-drop operation.

This property is read-only.

## Parameters

## Remarks

Some drag operations support a set of different drop effects. For example, a drag operation initiated through a right-click might display a menu of options when the element is dropped. In the source-only style of Microsoft UI Automation drag-and-drop, no elements implement the [DropTarget](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-implementingdroptarget) pattern. To find out what effect dropping the dragged element will have, a client can query the [DropEffect](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nf-uiautomationcore-idragprovider-get_dropeffect) property of the dragged element. This property can be a short string such as "move", or a longer one, such as "insert into Main group". The strings are always localized.

## See also

[IDragProvider](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-idragprovider)