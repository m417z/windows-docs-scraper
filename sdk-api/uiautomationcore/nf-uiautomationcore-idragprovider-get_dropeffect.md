# IDragProvider::get_DropEffect

## Description

Retrieves a localized string that indicates what happens when this element is dropped as part of a drag-drop operation.

This property is read-only.

## Parameters

## Remarks

In the source-only style of UI Automation drag-and-drop, no elements implement the [DropTarget](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-implementingdroptarget) pattern. To find out what effect dropping the dragged element will have, a client can query the **DropEffect** property of the dragged element. This property can be a short string such as "move", or a longer one, such as "insert into Main group". The string is always localized.

If this property changes, the provider must notify clients by calling [UiaRaiseAutomationPropertyChangedEvent](https://learn.microsoft.com/windows/desktop/api/uiautomationcoreapi/nf-uiautomationcoreapi-uiaraiseautomationpropertychangedevent) and specifying a property identifier of [UIA_DragIsGrabbedPropertyId](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-control-pattern-propids) or [UIA_DragDropEffectPropertyId](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-control-pattern-propids).

## See also

[IDragProvider](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-idragprovider)