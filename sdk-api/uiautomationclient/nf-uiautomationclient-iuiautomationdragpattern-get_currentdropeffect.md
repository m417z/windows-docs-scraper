# IUIAutomationDragPattern::get_CurrentDropEffect

## Description

Retrieves a localized string that indicates what happens when the user drops this element as part of a drag-drop operation.

This property is read-only.

## Parameters

## Remarks

In the source-only style of Microsoft UI Automation drag-and-drop, no elements implement the [DropTarget](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-implementingdroptarget) pattern. To find out what effect dropping the dragged element will have, a client can query the [DropEffect](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nf-uiautomationcore-idragprovider-get_dropeffect) property of the dragged element. This property can be a short string such as "move", or a longer one, such as "insert into Main group". The string is always localized.

## See also

[IUIAutomationDragPattern](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationdragpattern)

[IUIAutomationDropTargetPattern::CachedDropTargetEffect](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nf-uiautomationclient-iuiautomationdroptargetpattern-get_cacheddroptargeteffect)

[IUIAutomationDropTargetPattern::CurrentDropTargetEffect](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nf-uiautomationclient-iuiautomationdroptargetpattern-get_currentdroptargeteffect)

[UI Automation Support for Drag-and-Drop](https://learn.microsoft.com/windows/desktop/WinAuto/ui-automation-support-for-drag-and-drop)