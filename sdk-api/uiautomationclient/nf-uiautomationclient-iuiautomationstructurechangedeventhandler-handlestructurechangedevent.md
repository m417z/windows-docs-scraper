# IUIAutomationStructureChangedEventHandler::HandleStructureChangedEvent

## Description

Handles an event that is raised when the Microsoft UI Automation tree structure has changed.

## Parameters

### `sender` [in]

Type: **[IUIAutomationElement](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationelement)***

A pointer to the element that raised the event.

### `changeType` [in]

Type: **[StructureChangeType](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/ne-uiautomationcore-structurechangetype)**

A value indicating the type of tree structure change that took place.

### `runtimeId` [in]

Type: **[SAFEARRAY](https://learn.microsoft.com/windows/win32/api/oaidl/ns-oaidl-safearray)***

Receives the runtime identifier of the element. This parameter is used only when *changeType* is [StructureChangeType_ChildRemoved](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/ne-uiautomationcore-structurechangetype); it is **NULL** for all other structure-change events.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method is implemented by the application to handle events that it has subscribed to by using [AddStructureChangedEventHandler](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nf-uiautomationclient-iuiautomation-addstructurechangedeventhandler)

Adjusting an event handler from within this method is not supported.

## See also

[Best Practices for Using Safe Arrays](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-workingwithsafearrays)

[IUIAutomationStructureChangedEventHandler](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationstructurechangedeventhandler)