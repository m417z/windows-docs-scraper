# IDragProvider::get_IsGrabbed

## Description

Indicates whether the element has been grabbed as part of a drag-and-drop operation.

This property is read-only.

## Parameters

## Remarks

If this property changes, the provider must notify clients by calling [UiaRaiseAutomationPropertyChangedEvent](https://learn.microsoft.com/windows/desktop/api/uiautomationcoreapi/nf-uiautomationcoreapi-uiaraiseautomationpropertychangedevent) and specifying a property identifier of [UIA_DragIsGrabbedPropertyId](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-control-pattern-propids) or [UIA_DragDropEffectPropertyId](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-control-pattern-propids).

## See also

[IDragProvider](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-idragprovider)