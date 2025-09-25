# IProxyProviderWinEventSink::AddStructureChangedEvent

## Description

Raises an event to notify clients that the structure of the UI Automation tree has changed.

## Parameters

### `pProvider` [in]

Type: **[IRawElementProviderSimple](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-irawelementprovidersimple)***

A pointer to the provider of the element that is raising the event.

### `structureChangeType` [in]

Type: **[StructureChangeType](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/ne-uiautomationcore-structurechangetype)**

The type of structure change that occurred.

### `runtimeId` [in]

Type: **[SAFEARRAY](https://learn.microsoft.com/windows/win32/api/oaidl/ns-oaidl-safearray)***

A pointer to the runtime identifiers of the elements that are affected. These IDs enable applications to identify elements that have been removed and are no longer represented by [IUIAutomationElement](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationelement) interfaces.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[Best Practices for Using Safe Arrays](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-workingwithsafearrays)

**Conceptual**

[IProxyProviderWinEventSink](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-iproxyproviderwineventsink)

**Reference**