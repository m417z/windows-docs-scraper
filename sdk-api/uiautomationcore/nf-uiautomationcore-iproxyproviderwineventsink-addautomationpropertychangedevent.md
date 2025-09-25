# IProxyProviderWinEventSink::AddAutomationPropertyChangedEvent

## Description

Raises a property-changed event.

## Parameters

### `pProvider` [in]

Type: **[IRawElementProviderSimple](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-irawelementprovidersimple)***

A pointer to the provider for the element that will raise the event.

### `id` [in]

Type: **PROPERTYID**

The identifier of the property that is to be changed. For a list of property IDs, see [Property Identifiers](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-entry-propids).

### `newValue` [in]

Type: **[VARIANT](https://learn.microsoft.com/windows/desktop/WinAuto/variant-structure)**

The new value for the changed property.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IProxyProviderWinEventSink](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-iproxyproviderwineventsink)